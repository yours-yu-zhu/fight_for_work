#ifndef __STRING_H__
#define __STRING_H__
#include <iostream>
#include <cstring>
using namespace std;

class String{
public:
    String(const char* cstr = nullptr);
    String(const String& str);
    String& operator=(const String& str);
    ~String();
    char* get_c_str() const {return m_data;}
private:
    char* m_data;

};

#endif