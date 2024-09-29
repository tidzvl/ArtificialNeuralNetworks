/*
 * A sample class
 */

#ifndef SAMPLEA_H
#define SAMPLEA_H
#include <string>
using namespace std;

class SampleA {
public:
    SampleA(string name="An Instance of SampleA");
    SampleA(const SampleA& orig);
    virtual ~SampleA();
    string get_name();
private:
    string m_sName;
};

#endif /* SAMPLEA_H */

