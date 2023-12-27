#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <initializer_list>
#include <fstream>

using namespace std;

class StrBlobPtr;
//12.2 
class StrBlob{
    friend bool operator==(const StrBlob&, const StrBlob&); 
    friend bool operator!=(const StrBlob&, const StrBlob&);
public:
    using size_type = vector<string>::size_type;
    friend class StrBlobPtr;
    StrBlobPtr begin();
    StrBlobPtr end();

    StrBlob(): data(make_shared <vector<string>> ()){}
    StrBlob(initializer_list<string> il): data(make_shared<vector<string>>(il)){}

    size_type size() const {return data->size();}
    bool empty() const{return data->empty();}
    void push_back(const string &s){data->push_back(s);}
    void pop_back(){
        check(0,"pop_back on empty StrBlob");
        data->pop_back();
    }

    string& front(){
        check(0,"front on empty StrBlob");
        return data->front();
    }

    string& back(){
        check(0,"back on empty StrBlob");
        return data->back();
    }

    const string& front() const{
        check(0,"front on empty StrBlob");
        return data->front();
    }

    const string& back() const{
        check(0,"back on empty StrBlob");
        return data->back();
    }



private:
    shared_ptr <vector<string>> data;
    void check(size_type i ,const string &msg) const{
        if(i > data->size()){
            throw out_of_range(msg);
        }
    }
};


//12.19
class StrBlobPtr{
    friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
public:
    StrBlobPtr():curr(0){}
    StrBlobPtr(StrBlob &a, size_t sz =0):wptr(a.data), curr(sz){}
    string& deref() const{
        auto p = check(curr,"dereference past end");
        return (*p)[curr];
    }

    StrBlobPtr& incr(){
        check(curr,"increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }
    size_t get_curr() const{
        return curr;
    }
    //14.27 添加++ and --
    StrBlobPtr& operator++();
    StrBlobPtr& operator--();
    StrBlobPtr operator++(int);
    StrBlobPtr operator--(int);
    StrBlobPtr& operator+=(size_t);
    StrBlobPtr& operator-=(size_t);

private:
    weak_ptr<vector<string>> wptr;
    size_t curr;
    shared_ptr<vector<string>> check(size_t i, const string &msg) const{
        auto ret = wptr.lock();
        if(!ret){
            throw runtime_error("unbound StrBlobPtr");
        }
        if(i >= ret->size()){
            throw out_of_range(msg);
        }
        return ret;
    }

};