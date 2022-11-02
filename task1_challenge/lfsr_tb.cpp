#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vlfsr.h"

#include "vbuddy.cpp"     // include vbuddy code
#define MAX_SIM_CYC 1000000
#define ADDRESS_WIDTH 9

int main(int argc, char **argv, char **env) {
  int simcyc;     // simulation clock count
  int tick;       // each clk cycle has two ticks for two edges

  Verilated::commandArgs(argc, argv);
  // init top verilog instance
  Vlfsr* top = new Vlfsr;
  // init trace dump
  Verilated::traceEverOn(true);
  VerilatedVcdC* tfp = new VerilatedVcdC;
  top->trace (tfp, 99);
  tfp->open ("lfsr.vcd");
 
  // init Vbuddy
  if (vbdOpen()!=1) return(-1);
  vbdHeader("Lab 3: Task 1 (LFSR)");
  vbdSetMode(1);        // Flag mode set to one-shot

  // initialize simulation input 
  top->clk = 1;
  top->rst = 0;
  top->en = 1;


  int symcyc = 0;
  // run simulation for MAX_SIM_CYC clock cycles
  for (int iterations=0; iterations<10000000000000; iterations++) {
    // dump variables into VCD file and toggle clock
    if(vbdFlag()){
        simcyc++;
        for (tick=0; tick<2; tick++) {
          tfp->dump (2*simcyc+tick);
          top->clk = !top->clk;
          top->eval ();
        }
        vbdHex(2, (top->data_out >> 4) & 0xF);
        vbdHex(1, top->data_out & 0xF);
        vbdBar(top->data_out & 0xFF);
        vbdCycle(simcyc);

        // either simulation finished, or 'q' is pressed
        if ((Verilated::gotFinish()) || (vbdGetkey()=='q')) 
        exit(0);
    }
  }

  vbdClose();     // ++++
  tfp->close(); 
  printf("Exiting\n");
  exit(0);
}
