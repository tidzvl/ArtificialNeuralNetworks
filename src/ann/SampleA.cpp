#include "ann/SampleA.h"

SampleA::SampleA(string name):m_sName(name) {
}

SampleA::SampleA(const SampleA& orig) {
    m_sName = orig.m_sName;
}

SampleA::~SampleA() {
}
string SampleA::get_name(){
    return m_sName;
}

