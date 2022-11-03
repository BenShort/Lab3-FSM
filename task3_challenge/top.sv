module top(
    input logic [15:0]          N,
    input logic                 en,
    input logic                 rst,
    input logic                 clk,

    output logic [7:0]          data_out
);

logic tick;

clktick clk_tick_block (
    .clk (clk),
    .rst (rst),
    .en (1'b1),
    .N (N),
    .tick (tick)
);



f1_fsm f1_fsm_block (
    .clk (clk),
    .rst(rst),
    .en(tick),
    .data_out(data_out)
);

endmodule
