#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vf1_fsm.h"

#include "vbuddy.cpp"     // include vbuddy code
#define MAX_SIM_CYC 1000000
#define ADDRESS_WIDTH 9

int main(int argc, char **argv, char **env) {
  int simcyc;     // simulation clock count
  int tick;       // each clk cycle has two ticks for two edges

  Verilated::commandArgs(argc, argv);
  // init top verilog instance
  Vf1_fsm* top = new Vf1_fsm;
  // init trace dump
  Verilated::traceEverOn(true);
  VerilatedVcdC* tfp = new VerilatedVcdC;
  top->trace (tfp, 99);
  tfp->open ("f1_fsm.vcd");
 
  // init Vbuddy
  if (vbdOpen()!=1) return(-1);
  vbdHeader("Lab 3: Task 2 (f1_fsm)");
  vbdSetMode(1);        // Flag mode set to one-shot

  // initialize simulation input 
  top->clk = 1;
  top->rst = 0;
  top->en = 1;


  int symcyc = 0;
  // run simulation for MAX_SIM_CYC clock cycles

  for (int timer=0; timer<1000000000; timer++) {
    if(vbdFlag()){
      // dump variables into VCD file and toggle clock
      for (tick=0; tick<2; tick++) {
        tfp->dump (2*simcyc+tick);
        top->clk = !top->clk;
        top->eval ();
      }
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