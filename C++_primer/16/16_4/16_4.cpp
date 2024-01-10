#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "/home/ubuntu/fight_for_work/C++_primer/16/16_1/Vec.h"
#include "/home/ubuntu/fight_for_work/C++_primer/16/16_1/SharedPtr.h"
using namespace std;

template <typename T,typename ... Args>
void foo(const T &t, const Args& ... rest){
    cout << "sizeof...(Args)"<< sizeof...(Args) << endl;
    cout << "sizeof...(rest)"<< sizeof...(rest) << endl;
    cout << endl;
    // cout << "sizeof...(args)"<< sizeof...(args) << endl;
}

void ex16_52(){
    int i = 0;
    double d = 3.14;
    string s = "how now brown cow";
    foo(i, s, 42, d);                   // 包中有三个参数
    foo(s, 42, "hi");                   // 包中有两个参数
    foo(d, s);                          // 包中有一个参数
    foo("hi");                          // 空包
    foo(i, s, s, d);                    // 包中有三个参数
}

//ex16_53
template <typename T>
ostream &print(ostream &os, const T &t){
    return os << t << endl;
}

template <typename T, typename ... Args>
ostream &print(ostream &os, const T &t, const Args& ... rest){
    os << t << ",";
    return print(os, rest...);
}

void ex16_53(){
    int i = 0;
    std::string s = "Hello";

    print(std::cout, i);
    print(std::cout, i, s);
    print(std::cout, i, s, 42.1, 'A', "End");
}

//ex16.56
template <typename T>
string debug_rep(const T &t){
    ostringstream ret;
    ret << t;
    return ret.str();
} 

template <typename ... Args>
ostream &errorMsg(ostream &os, const Args& ... args){
    return print(os, debug_rep(args)...);
}

void ex16_56(){
    int i = 0;
    std::string s = "Hello";

    errorMsg(std::cout, i);
    errorMsg(std::cout, i, s);
    errorMsg(std::cout, i, s, 42.1, 'A', "End");

    // std::vector<std::string> svec{"error: 0", "warning: 0"};
    // errorMsg(std::cout, svec);
}

// ex16.58
void ex16_58(){
    Vec<string> svec = getVec(cin);
    print(svec);
    cout << "emplace " << svec.size() << endl;
    svec.emplace_back("End");
    svec.emplace_back(3, '!');
    print(svec);
}

//ex16.59
// 

int main(){
    // ex16_52();
    // ex16_53();
    // ex16_56();
    // ex16_58();
    return 0;
}  