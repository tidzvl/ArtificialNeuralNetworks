#include "ann/SampleB.h"

SampleB::SampleB(string name):m_sName(name) {
}

SampleB::SampleB(const SampleB& orig) {
    m_sName = orig.m_sName;
}

SampleB::~SampleB() {
}
string SampleB::get_name(){
    return m_sName;
}

