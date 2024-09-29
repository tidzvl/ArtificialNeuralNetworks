/*
 * A sample class
 */

#ifndef SAMPLET_H
#define SAMPLET_H
#include <string>
using namespace std;

class SampleT {
public:
    SampleT(string name="An Instance of SampleT");
    SampleT(const SampleT& orig);
    virtual ~SampleT();
    string get_name();
private:
    string m_sName;
};

#endif /* SAMPLET_H */

