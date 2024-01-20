#include "String.h"

using namespace std;

String::String(const char* cstr ){
    if(cstr){
        m_data = new char[strlen(cstr) + 1];
        strcpy(m_data, cstr);
    }else{
        m_data = new char[1];
        *m_data = '\0';
    }
}

String::~String(){
    delete[] m_data;
}

String::String(const String& str){
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(this->m_data, str.m_data);
}

String& String::operator=(const String& str){
    if(this == &str){
        return *this;
    }
    delete[] m_data;
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(this->m_data, str.m_data);
    return *this;
} 


int main(){
    String s1("hello");
    String s2("world");
    String s3(s1);
    cout << s3.get_c_str() << endl;    
    s3 = s2;
    cout << s3.get_c_str() << endl;
    return 0;
}