/**
  @brief A simple ALU-like module

  @input op   opcode for the operation to perform
  @input a    input to calculation
  @input b    input to calulation
  @output out result of calculation
*/
module Exercise1 (
    input  [1:0] op,
    input  [7:0] a,
    input  [7:0] b,
    output [7:0] out
);

    assign out = (op == 2'b00) ? a + b :
                (op == 2'b01) ? a - b :
                (op == 2'b10) ? a & b :
                (op == 2'b11) ? a | b :
                8'b0; // Default case 

    //assign out = op[1] ? (op[0] ? a | b : a & b) : (op[0] ? a - b : a + b);

endmodule
