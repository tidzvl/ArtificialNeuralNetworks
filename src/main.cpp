#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

// #include "sformat/fmt_lib.h"
#include "tensor/xtensor_lib.h"
#include "ann/SampleA.h"
#include "ann/SampleB.h"
#include "tensor/SampleT.h"



int main(int argc, char** argv) {
    SampleA a;
    SampleB b;
    SampleT t;
    cout << a.get_name() << endl;
    cout << b.get_name() << endl;
    cout << t.get_name() << endl;
    
    return 0;
}

