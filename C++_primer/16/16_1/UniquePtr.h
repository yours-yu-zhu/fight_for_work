#ifndef UniquePtr_H
#define UniquePtr_H

#include "DebugDelete.h"

template <typename T, typename D = DebugDelete>
class UniquePtr{
public:
    UniquePtr(T *p = nullptr, D d = DebugDelete()):ptr(p), deleter(d){}
    ~UniquePtr(){deleter(ptr);}

    UniquePtr(UniquePtr &&u):ptr(u.ptr), deleter(u.deleter){
        u.ptr = nullptr;
    }
    UniquePtr& operator=(UniquePtr &&u);

    T operator*() const{return *ptr;}
    T* operator->() const{return ptr;}

    void reset (T *p){
        deleter(ptr);
        ptr = p;
    }

    void reset (T *p, D d){
        deleter(ptr);
        ptr = p;
        deleter = d;
    }

private:
    T *ptr;
    D deleter;
};
template <typename T, typename D>
UniquePtr<T,D> &UniquePtr<T,D>::operator=(UniquePtr<T,D> &&u){
    if(this != &u){
        deleter(ptr);
        ptr = u.ptr;
        deleter = u.deleter;
        u.ptr = nullptr;
    }
    return *this;
}



#endif