// file main.cpp
#include "systemc.h"
SC_MODULE(Adder)
{
  sc_in<int> x;
  sc_in<int> y;
  sc_out<int> s;

  void add()
  {
    int a,b;
    int count=0;
    for (;;){
      wait();
      a = x;
      b=y;
      s=a+b;
      cout<< "a = " << a << " and b =" << b <<endl;
      
      }
  }
  void multiply(){
    int a,b;
    int count=0;
    for (;;){
      wait();
      a = x;
      b=y;
      s=a*b;
      cout<< "a = " << a << " and b =" << b <<endl;
      
      }
  }

  char mul_or_add;
  SC_CTOR(Adder)
  {
    mul_or_add = 'b';
    if (mul_or_add=='a') {
      SC_THREAD(add);
      }
    else SC_THREAD(multiply);
    sensitive << x << y;
  }
  
};


SC_MODULE(Testbench)
{ 
  
  // a top level module; no ports
  sc_signal<int> ch_x, ch_y, ch_s;  // channels
  void stim()  // SC_THREAD
  {
    wait(3, SC_NS);
    ch_x = 3; ch_y = 4;   // first stimulus
    
    wait(3, SC_NS);
    ch_x = 0; ch_y = 7;   // first stimulus
   
    wait(3, SC_NS);
    ch_x = 3; ch_y = 4;   // first stimulus
   
    wait(3, SC_NS);      // wait (no sensitivity!)
    ch_x = 8; ch_y = -4;
   
    wait(3, SC_NS);
    ch_x = 8; ch_y = -4;
  }
  void check() // SC_METHOD
  {
    cout << ch_x << "*" << ch_y << "=" << ch_s;  // debug output
    if( ch_s != ch_x*ch_y ) sc_stop();     // stop simulation
    else {
      cout << " -> OK" << endl;
      cout<< "------- -------- -------- --------" << endl;

      }
    
  }Adder uut;						// Adder instance
  SC_CTOR(Testbench)
  : uut("uut"), ch_x("ch_x")
  {
    

    SC_THREAD(stim);				// without sensitivity
    SC_METHOD(check);
    sensitive << ch_s;				// sensitivity for check()
    uut.x(ch_x);					// port x of uut bound to ch_x
    uut.y(ch_y);					// port y of uut bound to ch_y
    uut.s(ch_s);					// port s of uut bound to ch_s
    
  }
  
  };


int sc_main(int argc, char *argv[])  // cf. C++ main()
{
  Testbench tb("tb");
  sc_trace_file *handle;
  handle=sc_create_vcd_trace_file("waveforms");
  sc_trace(handle,tb.ch_x,"ch_x");
  sc_trace(handle,tb.ch_y,"ch_y");
  sc_trace(handle,tb.ch_s,"s"); 
  sc_start();
  cout << "simulation finished" << endl;
  sc_close_vcd_trace_file(handle);
  return 0;
}
