#include <systemc.h>

SC_MODULE (events) {
  

  sc_event  e1;
 // sc_event  e1;
  void p1(){
      cout<<"In p1.1 "<< sc_time_stamp() << " delta " << sc_delta_count() << endl;
      e1.notify(10,SC_NS);
      
      cout<<"In p1.2 "<< sc_time_stamp() << " delta " << sc_delta_count() << endl;
      e1.notify(5,SC_NS);
      
      cout<<"In p1.3 "<< sc_time_stamp() << " delta " << sc_delta_count()<<endl;
      
      e1.notify(); //-->
      
      cout<<"In p1.4 "<< sc_time_stamp() << " delta " << sc_delta_count() <<endl;
      e1.notify(0,SC_NS);//-->
      
      cout<<"In p1.5 "<< sc_time_stamp() << " delta " << sc_delta_count()<<endl;
      
      
      wait(5,SC_NS);
      wait(1,SC_NS);
      cout<<"In p1.6 "<< sc_time_stamp()<< " delta " << sc_delta_count()  <<endl;
      
      e1.notify(5,SC_NS);
      
      cout<<"In p1.7 "<< sc_time_stamp() << " delta " << sc_delta_count()<<endl;
      
      wait(5,SC_NS);
      
      cout<<"In p1.8 "<< sc_time_stamp() << " delta " << sc_delta_count()<<endl;
      
      e1.notify();
      
      cout<<"In p1.9 "<< sc_time_stamp()<< " delta " << sc_delta_count() <<endl;
      
            e1.notify(1,SC_NS);
      
       cout<<"In p1.10 "<< sc_time_stamp()<< " delta " << sc_delta_count() <<endl;
      
       wait(10,SC_NS); 
      
        e1.notify(0,SC_NS);
      
        cout<<"In p1.11 "<< sc_time_stamp() << " delta " << sc_delta_count()<<endl;
      
    }
    void p2(){
        cout<<"In p2.0 "<< sc_time_stamp() << " delta " << sc_delta_count()  <<endl;
        
        wait(10,SC_NS);
        cout<<"In p2.1 "<< sc_time_stamp() << " delta " << sc_delta_count()  <<endl;
        e1.notify(1,SC_NS); // ->
        
        cout<<"In p2.2 "<< sc_time_stamp()<< " delta " << sc_delta_count() <<endl;
        
        e1.notify(10,SC_NS);
        
        cout<<"In p2.3 "<< sc_time_stamp() << " delta " << sc_delta_count() <<endl;
        
        wait(5,SC_NS); 
        
        cout<<"In p2.4 "<< sc_time_stamp()<< " delta " << sc_delta_count()<<endl;
        
         wait(10,SC_NS);

       cout<<"In p2.5 "<< sc_time_stamp()<< " delta " << sc_delta_count() <<endl;
        
        e1.notify(0,SC_NS);
        
        cout<<"In p2.6 "<< sc_time_stamp() << " delta " << sc_delta_count()<<endl;
    }
  void p3(){
      cout<<"evt1 @ "<< sc_time_stamp() <<" simulation time " << name() << endl;
  }
    



  SC_CTOR(events) {
    
    SC_THREAD(p1);
     SC_THREAD(p2);
    
    SC_METHOD(p3);
    sensitive << e1;
    

    dont_initialize();
  }
}; 

int sc_main (int argc, char* argv[]) {

  events  object("events");

  
  sc_start();  // Run the simulation till sc_stop is encountered
  return 0;// Terminate simulation
}