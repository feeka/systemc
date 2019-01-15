#include "half_adder.h"

SC_MODULE(full_adder){
    //full adder takes 3 inputs and produces 2 outputs
    sc_in<bool> a,b, carry_in;
    sc_out<bool> sum, carry_out;

    //full adder consists of two half_adder instances
    half_adder *ha1;
    half_adder *ha2;

    //these variables are results of intermidiate findings
    sc_signal<bool> c1,c2, s1;

    //we have to find c1 OR c2 = carry_out
    void prc_or();
    

    SC_CTOR(full_adder){
        //associate every element of ha_1
        ha1 = new half_adder("half_adder_1");
        ha1->a(a);
        ha1->b(b);
        ha1->sum(s1);
        ha1->carry(c1);
        
        //associate every element of ha_2
        ha2 = new half_adder("half_adder_2");
        ha2->a(s1);
        ha2->b(carry_in);
        ha2->sum(sum);
        ha2->carry(c2);

        //since carry1 and carry2 are inputs of OR-ing
        SC_METHOD(prc_or);
        sensitive << c1 << c2;

    } 

    ~full_adder(){
        delete ha1;
        delete ha2;

    }
};