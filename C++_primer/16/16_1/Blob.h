#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <initializer_list>
#include <fstream>

using namespace std;


template <typename> class BlobPtr;
//12.2 
template <typename T>
class Blob{
    template <typename X>
    friend bool operator==(const Blob<X>&, const Blob<X>&);
    template <typename X> 
    friend bool operator!=(const Blob<X>&, const Blob<X>&);
public:
    using size_type = typename vector<T>::size_type;
    friend class BlobPtr<T>;

    Blob(): data(make_shared <vector<T>> ()){}
    Blob(initializer_list<T> il): data(make_shared<vector<T>>(il)){}
    size_type size() const {return data->size();}
    bool empty() const{return data->empty();}
    void push_back(const T &s){data->push_back(s);}
    void pop_back(){
        check(0,"pop_back on empty StrBlob");
        data->pop_back();
    }
    BlobPtr<T> begin() { return BlobPtr<T>(*this); }
    BlobPtr<T> end() {
        BlobPtr<T> ret = BlobPtr<T>(*this, data->size());
        return ret;
    }

    T& front(){
        check(0,"front on empty StrBlob");
        return data->front();
    }

    T& back(){
        check(0,"back on empty StrBlob");
        return data->back();
    }

    const T& front() const{
        check(0,"front on empty StrBlob");
        return data->front();
    }

    const T& back() const{
        check(0,"back on empty StrBlob");
        return data->back();
    }

private:
    shared_ptr <vector<T>> data;
    void check(size_type i ,const string &msg) const{
        if(i > data->size()){
            throw out_of_range(msg);
        }
    }
};

template <typename T>
bool operator==(const Blob<T> &lhs, const Blob<T> &rhs){
    return lhs.data == rhs.data;
}

template <typename T>
bool operator!=(const Blob<T> &lhs, const Blob<T> &rhs){
    return !(lhs == rhs);
}

//12.19
template <typename T>
class BlobPtr{
    template <typename X>
    friend bool operator==(const BlobPtr<X>&, const BlobPtr<X>&);
    template <typename X>
    friend bool operator!=(const BlobPtr<X>&, const BlobPtr<X>&);
public:
    BlobPtr():curr(0){}
    BlobPtr(Blob<T> &a, size_t sz =0):wptr(a.data), curr(sz){}
    T& deref() const{
        auto p = check(curr,"dereference past end");
        return (*p)[curr];
    }

    BlobPtr<T>& incr(){
        check(curr,"increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }
    size_t get_curr() const{
        return curr;
    }
    //14.27 添加++ and --
    BlobPtr<T>& operator++();
    BlobPtr<T>& operator--();
    BlobPtr<T>& operator+=(size_t);
    BlobPtr<T>& operator-=(size_t);

    //14。30 添加下标运算符
    T& operator*() const;
    T* operator->() const;

private:
    weak_ptr<vector<T>> wptr;
    size_t curr;
    shared_ptr<vector<T>> check(size_t i, const string &msg) const;

};

template <typename T>
shared_ptr<vector<T>> BlobPtr<T>::check(size_t i, const string &msg) const{
        auto ret = wptr.lock();
        if(!ret){
            throw runtime_error("unbound StrBlobPtr");
        }
        if(i >= ret->size()){
            throw out_of_range(msg);
        }
        return ret;
    }

template <typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs){
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if(l == r){
        return (!r || lhs.curr == rhs.curr);
    }else{
        return false;
    }
}

template <typename T>
bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs){
    return !(lhs == rhs);
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++(){
    check(curr,"increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--(){
    --curr;
    check(curr, "decrement past begin of StrBlobPtr");
    return *this;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator+=(size_t n){
    check(curr, "increment past end of StrBlobPtr");
    curr += n;
    return *this;    
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator-=(size_t n){
    curr -= n;
    check(curr, "increment past end of StrBlobPtr");
    return *this;  
}

template <typename T>
T& BlobPtr<T>::operator*() const{
    auto p = check(curr,"dereference past end");
    return (*p)[curr];
}

template <typename T>
T* BlobPtr<T>::operator->() const{
    return & this ->operator*();
}


