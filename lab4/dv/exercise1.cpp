#include <VExercise1.h>
#include <cstdint>
#include <catch2/catch_test_macros.hpp>

using namespace std;

void test_op(uint8_t code, uint8_t(op)(uint8_t, uint8_t)) {
  VExercise1 model;
  model.op = code;
  model.a = 0;
  model.b = 0;

  do {
    do {
      model.eval();
      uint8_t result {op(model.a, model.b)};
      REQUIRE(result == model.out);
    } while(++model.b);
    model.b = 0;
  } while(++model.a);
}

TEST_CASE("Opcode 0, Xor") {
  test_op(0, [](uint8_t a, uint8_t b) -> uint8_t { return a ^ b; });
}

TEST_CASE("Opcode 1, Left shift") {
  test_op(1, [](uint8_t a, uint8_t b) -> uint8_t { 

    if(b >= 8) { 
      return 0; 
    }
    return a << b; 

  });
}

TEST_CASE("Opcode 2, %") {
  test_op(2, [](uint8_t a, uint8_t b) -> uint8_t { 

    if (b != 0) {
      return a % b;
    }
    return 0; 
    
  });
}

TEST_CASE("Opcode 3, ~(a & b)") {
  test_op(3, [](uint8_t a, uint8_t b) -> uint8_t { return ~(a & b); });
}