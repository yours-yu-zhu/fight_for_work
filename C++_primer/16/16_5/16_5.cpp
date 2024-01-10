#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

//ex16.63
template <typename T>
size_t count(const vector<T> &vec, const T &val){
    size_t cnt = 0;
    for(auto beg = vec.begin(); beg != vec.end(); ++beg){
        if(*beg == val){
            ++cnt;
        }
    }
    return cnt;
}

template <>
size_t count(const vector<char*> &vec,   char* const&val){
    cout  << "count(const vector<const char*> &vec, const char* const &val)" << endl;
    size_t cnt = 0;
    for(auto beg = vec.begin(); beg != vec.end(); ++beg){
        if(strcmp(*beg, val) == 0){
            ++cnt;
        }
    }
    return cnt;
}

void ex16_63_64(){
    vector<double> dvec = {1.1, 3.14, 2.2, 3.14, 3.3, 4.4};
    cout << count(dvec, 3.14) << endl;

    vector<int> ivec = {0, 1, 2, 3, 4, 5};
    cout << count(ivec, 0) << endl;

    vector<string> svec = {"Hello", "World", "!"};
    cout << count(svec, string("end")) << endl;

    // 练习 16.64
    vector<char*> pvec;
    pvec.push_back(new char[6]);
    pvec.push_back(new char[6]);
    pvec.push_back(new char[2]);
    strcpy(pvec[0], "Hello");
    strcpy(pvec[1], "World");
    strcpy(pvec[2], "!");
    char *w = new char[6];
    strcpy(w, "World");
    cout << count(pvec, w) << endl;
    delete[] w;
    delete pvec[2];
    delete pvec[1];
    delete pvec[0];
}

int main(){
    ex16_63_64();
    return 0;
}  