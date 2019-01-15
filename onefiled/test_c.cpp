#include <iostream>
using namespace std;

struct printer{
    double a;
    double b;
    double divide(){
        return a*b;
    }
    printer(){
        a =999;
        b= 990; 
    }

    
};

struct test_c
{
    double x;
    double y;
    printer _printer;

    double add(){
        return x+y;
    }

    double multiply(){
        return x*y;
    }

    test_c(){
        x=5;
        y=9;
    }


};

main(int argc, char const *argv[])
{
    test_c test;
    /*test.x=9;
    test.y=3;
    */
    printer p = test._printer;
    double c = p.divide();
    cout << c << endl;
    return 0;
}
