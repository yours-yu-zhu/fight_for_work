#ifndef SHAREDPTR_H
#define SHAREDPTR_H

#include "DebugDelete.h"
#include <functional>
template <typename T>
class SharedPtr {
    template <typename X>
    friend bool operator==(const SharedPtr<X> &lhs, const SharedPtr<X> &rhs);
    template <typename X>
    friend bool operator!=(const SharedPtr<X> &lhs, const SharedPtr<X> &rhs);
public:
    SharedPtr(): ptr(nullptr), cnt(nullptr), deleter(DebugDelete()){}
    SharedPtr(T *p, function<void(T*)> d = DebugDelete())
        :ptr(p), cnt(new size_t(1)), deleter(d){}
    //拷贝控制
    SharedPtr(const SharedPtr &sp):ptr(sp.ptr),cnt(sp.cnt), deleter(sp.deleter){
        ++(*cnt);
        debug();   
    }
    //
    SharedPtr& operator=(const SharedPtr &sp);
    T operator*() const{return *ptr;}
    T* operator->() const{return ptr;}
    bool operator()() const{return ptr == nullptr;}
    ~SharedPtr();

    void reset(T *p);
    void reset(T *p, function<void(T*)> d);

    void debug() const{
        if(cnt){
            cout << "cnt = " << *cnt << endl;
        }else{
            cout << "cnt = nullptr" << endl;
            throw std::runtime_error("should not happen");
        }
    }
private:
    T *ptr;
    function<void(T*)> deleter; //函数对象
    size_t *cnt;
};

template <typename T>
bool operator==(const SharedPtr<T> &lhs, const SharedPtr<T> &rhs){
    return lhs.ptr == rhs.ptr;
}

template <typename T>
bool operator!=(const SharedPtr<T> &lhs, const SharedPtr<T> &rhs){
    return !(lhs == rhs);
}

template <typename T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<T> &sp){
    ++(*(sp.cnt));
    if(--(*cnt) == 0){
        deleter ? deleter(ptr) : delete ptr;
    }
    ptr = sp.ptr;
    cnt = sp.cnt;
    deleter = sp.deleter;
    debug();
    return *this; 
}

template <typename T>
void SharedPtr<T>::reset(T *p){
    if(cnt && --(*cnt) == 0){
        deleter ? deleter(ptr) : delete ptr;
        delete cnt;
    }
    ptr = p;
    cnt = new size_t(1);
}

template <typename T>
void SharedPtr<T>::reset(T *p, function<void(T*)> d){
    reset(p);
    deleter = d;
}

template <typename T>
SharedPtr<T>::~SharedPtr(){
    if(cnt && --(*cnt) == 0){
        deleter ? deleter(ptr) : delete ptr;
        delete cnt;
    }
}

template <typename T>
SharedPtr<T> make_shared(){
    SharedPtr<T> s(new T);
    return s;
}


#endif