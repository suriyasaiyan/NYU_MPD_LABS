#include <VExercise4.h>
#include <cstdint>
#include <iostream>
#include <stdlib.h>
#include <catch2/catch_test_macros.hpp>

constexpr int kNumTests = 10;

uint8_t calculateExpectedResult(uint8_t alpha, uint8_t beta, uint8_t gamma, int cs, int sel) {
   if (cs) {
    switch(sel) {
      case 0: return alpha;
      case 1: return beta;
      case 2: return gamma;
      case 3: return alpha & (beta | gamma);
      default: return 0;
    }
  }
  else return 0;
}


TEST_CASE("runVerificationTest3") {
  VExercise4 model;
  uint8_t alpha, beta, gamma, result;
  
  for (int testCount = 0; testCount < kNumTests; testCount++) {

    alpha = rand() % 0xFF;
    beta = rand() % 0xFF;
    gamma = rand() % 0xFF;

    for (int cs = 0; cs < 2; cs++) {
      for (int sel = 0; sel < 4; sel++) {

        model.alpha = alpha;
        model.beta = beta;
        model.gamma = gamma;
        model.cs = cs;
        model.sel = sel;
        model.eval();

        result = calculateExpectedResult(alpha, beta, gamma, cs, sel);
        REQUIRE (model.out == result);
  
      }
    }
  }
}
