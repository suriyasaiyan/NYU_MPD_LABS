#include <VExercise2.h>
#include <cstdint>
#include <cstdlib> 
#include <iostream>

constexpr int kNumTests = 10;
constexpr int kNumClockCycles = 10;

uint16_t m1(uint16_t input, bool reset){

    static uint16_t out;
    if(reset){
        out = ~input;
    }
    else{
        out = ((input << 1) + (((input >> 10) & 1) ^ ((input >> 8) & 1) ^ ((input >> 3) & 1) ^ ((input >> 1) & 1)));
    }
    return out;
 
}

bool runVerificationTest() {
    VExercise2 model;
    uint16_t initial_state, expected_result, temp;

    for (int i = 0; i < kNumTests; i++) {
        initial_state = rand() % 0xFFFF;
        model.init = initial_state;
        model.clk = 1;
        model.reset = 1;
        model.eval();
        model.reset=1;
        model.clk = 0;
        model.eval();

        expected_result = ~initial_state;//m1(intial_state, 1)
        if (model.out != expected_result) return true;

        temp = ~initial_state;
       for (int j = 0; j < kNumClockCycles; j++) { 
            model.clk = 1;
            model.reset = 0;
            model.eval();
            model.clk = 0;
            model.reset = 0;
            model.eval();

            expected_result = m1(temp, 0);
            if (model.out != expected_result) return true;
            temp = model.out;
        }
    }
    return false;
}


int main() {

    bool failFlag = runVerificationTest();
    return failFlag ? 1 : 0; 
}
