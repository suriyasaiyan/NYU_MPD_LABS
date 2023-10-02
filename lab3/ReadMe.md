# Week 3 Lab: Verification

#### make note 1:
- The testing strategy I adopted for Exercise2 is a directed test bench. I provide specific inputs to the DUT and expect specific outputs. I chose this type of testing because it is relatively easy to write and debug, and it can be used to test specific scenarios that are important to the correctness of the design.

- Here are some of the decisions I had to make when writing the test bench:

1. What inputs should I test? I chose to test a variety of inputs, including all 1's, all 0's, and random inputs.
2. How many clock cycles should I test? I chose to test the DUT over a variety of clock cycles, including 10 clock cycles.

#### make note 2:
- testing a "Don't Care" condition involves verifying that when the cs (chip select) signal is set to 0, the value of sel (select) has no effect on the output of the system. To ensure that the input truly has no effect on the output in this scenario, the following steps are taken:

- Test All Combinations: The code runs a series of tests by iterating over all possible combinations of alpha, beta, gamma,cs, and sel values. The cs signal is set to 0 to simulate the "Don't Care" condition.