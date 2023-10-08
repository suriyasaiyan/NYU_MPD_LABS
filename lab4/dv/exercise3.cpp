#include <VExercise3.h>
#include <cstdint>
#include <cstdlib>  
#include <iostream>
#include <catch2/catch_test_macros.hpp>

constexpr int kNumTests = 10;
constexpr int kNumClockCycles = 10;

uint8_t m1(uint8_t a, uint8_t b, uint8_t c) {

  switch(a) {
    case 0: 
      return ((b & 7) << 3) + (c & 7);
    case 1: 
      return (1 << 6) + ((c & 7) << 3) + (b & 7);
    case 2: 
      return b;
    case 3: 
      return c;
    default: 
      return 0;
  }
}

uint16_t m2(uint8_t a, uint8_t b, bool reset) {

  static uint16_t out;
  static uint8_t state;
  
  if (reset) {
    state = 0;
    out = (b << 8) + a;
    return out;
  }
  else {
    switch(state) {
      case 0: {
        out = (a << 8) + (out & 255);
        state++;
        return out; }
      case 1: {
        out = (out & (255 << 8)) + b;
        state++;
        return out; }
      case 2: {
        out = (out << 8) + (out >> 8);
        state++;
        return out; }
      case 3: {
        out = (out << 12) + ((out & (15 << 4)) << 4) + ((out & (15 << 8)) >> 4) + ((out & (15 << 12)) >> 12);
        state++;
        return out;}
      case 4: {
        bool temp = out & 1;
        for (int k = 1; k < 16; k++) {
          temp ^= (out >> k) & 1;
        }
        out = temp;
        state = 0;
        return out; }
      default: return 0;
    }
  }
}

TEST_CASE("runVerificationTest2") {
  VExercise3 model;
  bool reset,clk;
  uint8_t a;
  uint16_t b, c, expected_result;

  for (int i = 0; i < kNumTests; i++) {
    
    //initalizing random numbers for inputs
    model.a = rand() % 0xF;
    model.b = rand() % 0xFFFF;
    model.c = rand() % 0xFFFF;

  //===========    Testing for RESET HIGH   ================

    model.clk = 1;
    model.reset = 0;
    model.eval();
    model.clk = 0;
    model.reset = 1;
    model.eval();
  
    expected_result = m2(m1((model.a & 3), (model.b & 255), (model.c & 255)), m1((model.a >> 2), (model.b >> 8), (model.c >> 8)), 1);
    REQUIRE(model.out == expected_result);

  //===========    Testing for RESET LOW   ================

    for (int j = 0; j < kNumClockCycles; j++) {

      model.clk = 1;
      model.reset = 0;
      model.eval();
      model.clk = 0;
      model.reset = 0;
      model.eval();

      expected_result = m2(m1((model.a & 3), (model.b & 255), (model.c & 255)), m1((model.a >> 2), (model.b >> 8), (model.c >> 8)), 0);
      REQUIRE(model.out == expected_result);
    }
  }
}

