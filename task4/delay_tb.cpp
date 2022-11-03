#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vtop.h"

#include "vbuddy.cpp"     // include vbuddy code
#define MAX_SIM_CYC 100000

int main(int argc, char **argv, char **env) {
  int simcyc;     // simulation clock count
  int tick;       // each clk cycle has two ticks for two edges
  int lights = 0; // state to toggle LED lights

  Verilated::commandArgs(argc, argv);
  // init top verilog instance
  Vtop * top = new Vtop;
  // init trace dump
  Verilated::traceEverOn(true);
  VerilatedVcdC* tfp = new VerilatedVcdC;
  top->trace (tfp, 99);
  tfp->open ("top.vcd");
 
  // init Vbuddy
  if (vbdOpen()!=1) return(-1);
  vbdHeader("L3T2:top challege");
  vbdSetMode(1);        // Flag mode set to one-shot

  // initialize simulation inputs
  top->clk = 1;
  top->rst = 0;
  int prev_val = 0;
  bool timer = false;
  
  // run simulation for MAX_SIM_CYC clock cycles
  for (simcyc=0; simcyc<MAX_SIM_CYC; simcyc++) {
    // dump variables into VCD file and toggle clock
    if(vbdFlag()){
            top->trigger = 1;
    }
    else{
      top->trigger = 0;
    }

    for (tick=0; tick<2; tick++) {
      tfp->dump (2*simcyc+tick);
      top->clk = !top->clk;
      top->eval ();
    }
    if ((top->data_out == 0) && (prev_val == 255)){
      bool timer = true;
      vbdInitWatch();
    }

    if(vbdFlag() && timer){
      std::cout << vbdElapsed;
      timer = false;
    }
    
    

    // Display toggle neopixel
    
    // set up input signals of testbench
    top->rst = (simcyc < 2);    // assert reset for 1st cycle
    //top->en = (simcyc > 2);
    //top->N = vbdValue();
    vbdBar(top->data_out & 0xFF);
    vbdCycle(simcyc);

    prev_val = top->data_out;

    if (Verilated::gotFinish())  exit(0);
  }

  vbdClose();     // ++++
  tfp->close(); 
  exit(0);
}
