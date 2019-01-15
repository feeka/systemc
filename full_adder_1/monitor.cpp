#include "monitor.h"
#include <iostream>
#include <fstream>

void monitor::prc_monitor(){
    cout << "At time :: " << sc_time_stamp() << " :: "
    << "(a,b,carry_in): "<< m_a << m_b << m_cin << " (sum,carry_out) :: " <<  m_sum << m_cout << endl;
    
    ofstream myfile;
    myfile.open ("test.txt", std::ofstream::out | std::ofstream::app);
    myfile << "At time :: " << sc_time_stamp() << " :: "
    << "(a,b,carry_in): "<< m_a << m_b << m_cin << " (sum,carry_out) :: " <<  m_sum << m_cout << endl;
    

}