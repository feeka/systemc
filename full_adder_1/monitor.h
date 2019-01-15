#include "systemc.h"

SC_MODULE(monitor){
    sc_in<bool> m_a,m_b,m_cin,m_cout,m_sum;

    ofstream myfile;

    void prc_monitor();
    
    
    
    SC_CTOR(monitor){
        SC_METHOD(prc_monitor);
        sensitive << m_a << m_b << m_cin << m_sum << m_cout;
    }
};