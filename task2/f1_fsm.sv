module f1_fsm(
    input logic             rst,
    input logic             en,
    input logic             clk,

    output logic [7:0]      data_out
);

//typedef
typedef enum {S0, S1, S2, S3, S4, S5, S6, S7, S8} f1_state;
f1_state current_state, next_state;

//next state logic
always_comb begin
    if(en == 1'b1) begin
        case(current_state)
            S0:         next_state = S1;
            S1:         next_state = S2;
            S2:         next_state = S3;
            S3:         next_state = S4;
            S4:         next_state = S5;
            S5:         next_state = S6;
            S6:         next_state = S7;
            S7:         next_state = S8;
            S8:         next_state = S0;
            default     next_state = S0;
        endcase
    end
end

//state transition
always_ff @(posedge clk) begin
    if (rst)    current_state <= S0;
    else        current_state <= next_state;
end

//output logic
always_comb begin
    if(en == 1'b1) begin
        case(current_state)
            S0:         data_out = 8'b0;
            S1:         data_out = 8'b1;
            S2:         data_out = 8'b11;
            S3:         data_out = 8'b111;
            S4:         data_out = 8'b1111;
            S5:         data_out = 8'b11111;
            S6:         data_out = 8'b111111;
            S7:         data_out = 8'b1111111;
            S8:         data_out = 8'b11111111;
            default     data_out = 8'b0;
        endcase
    end
end

endmodule
