#include "tensor/SampleT.h"

SampleT::SampleT(string name):m_sName(name) {
}

SampleT::SampleT(const SampleT& orig) {
    m_sName = orig.m_sName;
}

SampleT::~SampleT() {
}
string SampleT::get_name(){
    return m_sName;
}
