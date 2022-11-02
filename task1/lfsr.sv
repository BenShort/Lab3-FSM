module lfsr (
    input logic         clk,
    input logic         rst,
    input logic         en,

    output logic [3:0]  data_out
);

logic [4:1] sreg; //shift register

initial begin
    sreg[4:1] = 4'b0001;
end

always_ff @(posedge clk) begin
    if(en) begin
        if (rst) begin
            sreg <= 4'b0;
        end
        else begin
            sreg[4] <= sreg[3];
            sreg[3] <= sreg[2];
            sreg[2] <= sreg[1];
            sreg[1] <= sreg[3] ^ sreg[4];
        end
    end
end

assign data_out [3:0] = sreg[4:1];

endmodule
