#ifndef DEBUG_DELETE
#define DEBUG_DELETE
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <memory>
using namespace std;

//ex 16.21
class DebugDelete{
public:
    DebugDelete(const string &t, ostream &s = cerr): tyoe(t),os(s){}
    template <typename T> 
    void operator()(T *p)const{
        os << "deleting "<< tyoe << endl;
        delete p;
    }
private:
    ostream &os;
    string tyoe;
};

#endif