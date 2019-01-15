#include "systemc.h"
#include "stim.h"
#include "ex_or.h"
#include "monitor.h"

int sc_main(int argc, char* argv[])
{
    
  sc_signal<bool> ASig, BSig, FSig;
  sc_clock TestClk("TestClock", 10, SC_NS,0.5,1,SC_NS);

  stim Stim1("Stimulus");
  Stim1.A(ASig);
  Stim1.B(BSig);
  Stim1.Clk(TestClk);

  ex_or DUT("exor");
  DUT.A(ASig);
  DUT.B(BSig);
  DUT.F(FSig);

  monitor Monitor1("Monitor");
  Monitor1.A(ASig);
  Monitor1.B(BSig);
  Monitor1.F(FSig);
  Monitor1.Clk(TestClk);
sc_trace_file* Tf;
  Tf = sc_create_vcd_trace_file("traces");
  sc_trace(Tf, ASig  , "A" );
  sc_trace(Tf, BSig  , "B" );
  sc_trace(Tf, FSig  , "F" );
  sc_trace(Tf, DUT.S1, "S1");
  sc_trace(Tf, DUT.S2, "S2");
  sc_trace(Tf, DUT.S3, "S3");
  sc_trace(Tf, TestClk, "Clk");

  sc_start();  // run forever
  sc_close_vcd_trace_file(Tf);

  return 0;

}