#ifndef VEC_H
#define VEC_H
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>  
#include <algorithm>
#include <memory>
#include <utility>
#include <initializer_list>
using namespace std;
template <typename Type> 
class Vec{
    template <typename X>
    friend bool operator==(const Vec<X>&, const Vec<X>&);
    template <typename X> 
    friend bool operator!=(const Vec<X>&, const Vec<X>&);   
public:
    //默认构造函数，全为空
    Vec():elements(nullptr), first_free(nullptr), cap(nullptr){}
    Vec(const Vec<Type>&); //拷贝构造函数
    Vec(initializer_list<Type>);
    Vec<Type>& operator=(const  Vec<Type>&); //拷贝赋值运算符
    ~Vec(); //析构函数
    void push_back(const Type&); //添加元素,左值版本
    void push_back(Type&&); //添加元素，右值版本
    //size()返回当前真正在使用的元素数量
    size_t size() const{
        return first_free - elements; 
    }
    //capacity()返回StrVec可以保存的元素总数
    size_t capacity() const{
        return cap - elements;
    }
    //返回StrVec首元素指针
    Type* begin() const{
        return elements;
    }
    //返回StrVec尾元素指针（已经使用的）
    Type* end() const{
        return first_free;
    }
    void reserve(size_t n); //分配至少能容纳n个元素的空间
    void resize(size_t n); //将元素数量调整为n个
    void resize(size_t n, const Type& s); //将元素数量调整为n个，多余的用s初始化
private:
    void free(); //销毁并释放内存
    void reallocate(); //获得更多内存并拷贝已有元素
    //检查容量是否满了，满了就要重新分配内存
    void chk_n_alloc(){
        if(size() == capacity())
            reallocate();
    }
    //工具函数，被拷贝构造函数、赋值运算符和析构函数所使用
    pair<Type*, Type*> alloc_n_copy(const Type*, const Type*);

private:
    Type* elements; //指向数组首元素的指针
    Type* first_free; //指向数组第一个空闲元素的指针
    Type* cap; //指向数组尾后位置的指针
    allocator<Type> alloc; //分配的元素        

};

template <typename Type>
bool operator==(const Vec<Type>& rhs, const Vec<Type>& lhs){
    cout << "operator==" << endl;
    if(rhs.size() != lhs.size()){
        return false;
    }
    for(auto p = rhs.begin(), q = lhs.begin();
        p != rhs.end() && q != lhs.end();
        ++p, ++q){
            if(*p != *q){
                return false;
            }
        }
    return true;   
}

template <typename Type>
bool operator!=(const Vec<Type>& rhs, const Vec<Type>& lhs){
    cout << "operator!=" << endl;
    return !(rhs == lhs);
}

template <typename Type>
pair<Type*, Type*> Vec<Type>::alloc_n_copy(const Type* b, const Type* e){
    auto data = alloc.allocate(e - b);
    //返回一个pair，该pair由新空间的开始和拷贝的尾后元素构成
    return make_pair(data,uninitialized_copy(b ,e, data));    
}

template <typename Type>
Vec<Type>::Vec(const Vec<Type>& vecs){
    //新创建的刚好填满
    auto newdata = alloc_n_copy(vecs.begin(), vecs.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

template <typename Type>
Vec<Type>::Vec(initializer_list<Type> il){
    auto newdata = alloc_n_copy(il.begin(), il.end());
    elements = newdata.first;
    first_free = cap = newdata.second;    
}

template <typename Type>
Vec<Type>::~Vec(){
    free();
}

template <typename Type>
void Vec<Type>::push_back(const Type& s){
    chk_n_alloc();//确保有空间
    alloc.construct(first_free++, s);//在first_free指向的元素中构造s的副本
    cout << "添加元素,左值版本" << endl;
}

template <typename Type>
void Vec<Type>::push_back(Type&& s){
    chk_n_alloc();
    alloc.construct(first_free++,std::move(s));
    cout << "添加元素,右值版本" << endl;    
}

template <typename Type>
void Vec<Type>::reserve(size_t n){
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

template <typename Type>
void Vec<Type>::resize(size_t n, const Type& s){
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

template <typename Type>
void Vec<Type>::resize(size_t n){
    resize(n, Type());  
}

template <typename Type>
void Vec<Type>::free(){
    //传递给deallocate的值必须不为空
    if(elements){
        for(auto p = first_free; p != elements;){
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
    }    
}

template <typename Type>
void Vec<Type>::reallocate(){
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

template <typename Type>
Vec<Type>& Vec<Type>::operator=(const  Vec<Type>& rhs){
    auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = newdata.first;
    first_free = cap = newdata.second;
    return *this;
}

void print(const Vec<string> &svec) {
    for (string *it = svec.begin(); it != svec.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

Vec<string> getVec(istream &is) {
    Vec<string> svec;
    string s;
    while (is >> s)
        svec.push_back(s);
    return svec;
}

#endif