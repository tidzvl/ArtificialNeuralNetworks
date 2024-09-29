/*
 * A sample class
 */

#ifndef SAMPLEB_H
#define SAMPLEB_H
#include <string>
using namespace std;

class SampleB {
public:
    SampleB(string name="An Instance of SampleB");
    SampleB(const SampleB& orig);
    virtual ~SampleB();
    string get_name();
private:
    string m_sName;
};

#endif /* SAMPLEB_H */

