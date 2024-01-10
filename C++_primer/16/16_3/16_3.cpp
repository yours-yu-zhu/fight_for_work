#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>
using namespace std;

//exercise context
template <typename T>
string debug_rep(const T &t){
    ostringstream ret;
    ret << t;
    return ret.str();
} 

template <typename T>
string debug_rep(T *p){
    ostringstream ret;
    ret << "pointer: " << p;
    if(p){
        ret << " " << debug_rep(*p);
    }else{
        ret << " null pointer";
    }
    return ret.str();
}
string debug_rep(const string &s){
    return '"' + s + '"';
}

void ex_16_context(){
    string s("hi");
    cout << debug_rep(s) << endl;
    cout << debug_rep(&s) << endl;
    const string *sp = &s;
    cout << debug_rep(sp) << endl; 
    cout << debug_rep("hi world!") << endl;
}

//ex16_50
template <typename T> void f(T){
    cout << typeid(T).name() << "\ttemplate 1" << endl;
}
template <typename T> void f(const T*){
    cout << typeid(T).name() << "\ttemplate 2" << endl;   
}
template <typename T> void g(T){
    cout << typeid(T).name() << "\ttemplate 3" << endl;   
}
template <typename T> void g(T*){
    cout << typeid(T).name() << "\ttemplate 4" << endl;   
}

void ex16_50(){
    int i = 42, *p = &i;
    const int ci = 0, *p2 = &ci;
    g(42);
    g(p);
    g(ci);
    g(p2);
    f(42);
    f(p);
    f(ci);
    f(p2);    
}
int main(){
    // ex_16_context();
    ex16_50();
    return 0;
}  