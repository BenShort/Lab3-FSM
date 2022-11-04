module top (
    input logic             rst,
    input logic             clk,
    input logic             trigger,
    input logic [7:0]       bin,

    output logic [11:0]     BCD,
    output logic [7:0]      data_out
);

logic cmd_seq;
logic cmd_delay;
logic tick;
logic time_out;
logic [6:0] k;



clktick clktick_block(
    .N (5'd14),
    .en (cmd_seq),
    .rst (rst),
    .clk (clk),
    .tick(tick)
);

delay delay_block(
    .n (k),
    .trigger (cmd_delay),
    .rst (rst),
    .clk (clk),
    .time_out (time_out)
);

f1_fsm f1_fsm_block(
    .rst(rst),
    .en(cmd_seq ? tick : time_out),
    .trigger (trigger),
    .clk(clk),
    .data_out(data_out),
    .cmd_seq (cmd_seq),
    .cmd_delay(cmd_delay)
);

lfsr lfsr_block(
    .clk (clk),
    .rst (1'b0),
    .en (1'b1),
    .data_out (k)
);

//bin2bcd bin2bcd_block(
//    .x (bin),
//    .BCD (BCD)
//);

endmodule

