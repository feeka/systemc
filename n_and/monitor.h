#include "systemc.h"

SC_MODULE(monitor)
{
    sc_in<bool> A,B,F;
    sc_in<bool> Clk;

  void proc_monitor()
  {
    cout << "------------------------------" <<endl;
    cout <<  "Time" << "\t";
    cout << "A" << "\t";
    cout << "B" << "\t";
    cout << "F" << endl;
    while (true)
    {
      cout <<  sc_time_stamp() << "\t";
      cout << A.read() << "\t";
      cout <<  B.read() << "\t";
      cout <<  F.read() << endl;
      wait();    // wait for 1 clock cycle
    }
  }

  SC_CTOR(monitor)
  {
    SC_THREAD(proc_monitor);
    sensitive << Clk.pos();
  }
};