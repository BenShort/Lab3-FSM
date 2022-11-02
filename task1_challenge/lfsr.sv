module lfsr (
    input logic         clk,
    input logic         rst,
    input logic         en,

    output logic [6:0]  data_out
);

logic [7:1] sreg; //shift register

initial begin
    sreg[7:1] = 4'b0000001;
end

always_ff @(posedge clk) begin
    if(en) begin
        if (rst) begin
            sreg <= 7'b0;
        end
        else begin
            sreg[7] <= sreg[6];
            sreg[6] <= sreg[5];
            sreg[5] <= sreg[4];
            sreg[4] <= sreg[3];
            sreg[3] <= sreg[2];
            sreg[2] <= sreg[1];
            sreg[1] <= sreg[3] ^ sreg[7];
        end
    end
end

assign data_out [6:0] = sreg[7:1];

endmodule
