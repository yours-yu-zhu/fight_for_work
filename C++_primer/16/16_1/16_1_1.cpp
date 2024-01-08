#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include "/home/ubuntu/fight_for_work/C++_primer/14/14_1_4/14_1.h"

using namespace std;

//ex16.2
template <typename T>
int compare(const T &a, const T &b){
    if(a < b ) return -1;
    if(b < a ) return 1;
    return 0;
}

template <unsigned N, unsigned M>
int comparr(const char (&p1)[N], const char (&p2)[M]){
    return strcmp(p1, p2);
}

void ex16_2(){
    cout << compare(1, 0) << endl;
    cout << compare(1.0, 0.0) << endl;
    cout << compare(string("hello"), string("world")) << endl;
    cout << comparr("hi", "mom") << endl;
}

//16.4
template <typename I, typename T>
I Find(I begin, I end, const T &val){
    while(begin != end){
        if(*begin == val){
            return begin;
        }
        begin++;
    }
    return end;
}

void ex16_4(){
    vector<int> vec{1, 2, 3, 4, 5};
    auto iter1 = Find(vec.begin(), vec.end(), 3);
   if (iter1 == vec.end())
        std::cout << "Can not find 3" << std::endl;
    else
        std::cout << "Find 3 at position "
                  << iter1 - vec.begin() << std::endl;

    std::list<std::string> slis{"c++", "primer", "5th"};
    auto iter2 = Find(slis.begin(), slis.end(), "5th");
    if (iter2 == slis.end())
        std::cout << "Can not find 5th" << std::endl;
    else
        std::cout << "Find \"5th\"" << std::endl;
}


//16.5
template <typename T, size_t N>
void print(const T (&arr)[N]){
    for(const auto &elem : arr){
        cout << elem << " ";
    }
    cout << endl;
}

void ex16_5(){
    int a[6] = {0, 2, 4, 6, 8, 10};
    std::string s[3] = {"c++", "primer", "5th"};

    print(a);
    print(s);
}

//16.6
template <typename T, size_t N>
const T* begin(const T (&arr)[N]){
    return arr;
}

template <typename T, size_t N>
const T* end(const T (&arr)[N]){
    return arr + N;
}

void ex16_6(){
    int a[6] = {0, 2, 4, 6, 8, 10};
    std::string s[3] = {"c++", "primer", "5th"};  
    std::cout << *begin(a) << std::endl;
    std::cout << *(end(a) - 1) << std::endl;
    std::cout << *begin(s) << std::endl;
    std::cout << *(end(s) - 1) << std::endl;  
}

template <typename T, size_t N> constexpr
size_t size(const T (&arr)[N]){
    return N;
}

void ex16_7(){
    int a[] = {0, 2, 4, 6, 8, 10};
    std::cout << size(a) << std::endl;
}

int main(){
    // ex16_4();
    // ex16_5();
    // ex16_6();
    ex16_7();
    return 0;
}
