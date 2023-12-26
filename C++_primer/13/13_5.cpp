#include "ex13_5.h"
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;

void StrVec::push_back(const string& s){
    chk_n_alloc();//确保有空间
    alloc.construct(first_free++, s);//在first_free指向的元素中构造s的副本
    cout << "添加元素,左值版本" << endl;
}
void StrVec::push_back(string&& s){
    chk_n_alloc();
    alloc.construct(first_free++,std::move(s));
    cout << "添加元素,右值版本" << endl;
}

pair<string*, string*> StrVec::alloc_n_copy(const string* a, const string* b){
    auto data = alloc.allocate(b -a);
    //返回一个pair，该pair由新空间的开始恶和拷贝的尾后元素构成
    return make_pair(data,uninitialized_copy(a ,b, data));
}

 //销毁并释放内存
void StrVec::free(){
    //传递给deallocate的值必须不为空
    if(elements){
        for(auto p = first_free; p != elements;){
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(const StrVec& vecs){
    //新创建的刚好填满
    auto newdata = alloc_n_copy(vecs.begin(), vecs.end());
    elements = newdata.first;
    first_free = cap = newdata.second;

}

StrVec::~StrVec(){
    free();
}

StrVec& StrVec::operator=(const StrVec& rhs){
    auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = newdata.first;
    first_free = cap = newdata.second;
    return *this;
}

void StrVec::reallocate(){
    //分配当前大小的两倍的内存空间
    auto newcapacity = size() ? 2*size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata; //指向新数组中下一个空闲位置
    auto elem = elements; //指向旧数组中下一个元素
    for(size_t i = 0; i != size(); ++i){
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;   
}

void StrVec::reserve(size_t n){
    if(n <= capacity()){
        return;
    }
    auto newdata = alloc.allocate(n);
    auto dest = newdata;
    auto elem = elements;
    for(size_t i = 0; i != size(); ++i){
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + n;
}

void StrVec::resize(size_t n, const string& s){
    if(n > size()){
        if(n > capacity()){
            reserve(n * 2);
        }
        for(size_t i = size(); i != n; ++i){
            alloc.construct(first_free++, s);
        }
    }else if(n < size()){
        while(first_free != elements + n){
            alloc.destroy(--first_free);
        }
    }
}

void StrVec::resize(size_t n){
    resize(n, string());
}

StrVec::StrVec(initializer_list<string> il){
    auto newdata = alloc_n_copy(il.begin(), il.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}    

int main() {
    StrVec vec;
    string s = "some string or another";
    vec.push_back(s); //左值版本
    vec.push_back("done"); //右值版本
    
}

/*
copy constructor
copy constructor
copy-assignment
copy constructor
hello
hello
temporary
temporary
copy constructor
copy constructor
copy constructor
copy constructor
copy constructor
copy constructor
copy constructor
copy constructor

hello
hello
hello
world
world
world
good job
*/