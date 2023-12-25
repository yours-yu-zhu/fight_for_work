#ifndef EX12_3_H
#define EX12_3_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <memory>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <initializer_list>

using namespace std;

class QueryResult;


class StrVec{
public:
    //默认构造函数，全为空
    StrVec():elements(nullptr), first_free(nullptr), cap(nullptr){}
    StrVec(const StrVec&); //拷贝构造函数
    StrVec(initializer_list<string>);
    StrVec& operator=(const StrVec&); //拷贝赋值运算符
    ~StrVec(); //析构函数
    void push_back(const string&); //添加元素
    //size()返回当前真正在使用的元素数量
    size_t size() const{
        return first_free - elements; 
    }
    //capacity()返回StrVec可以保存的元素总数
    size_t capacity() const{
        return cap - elements;
    }
    //返回StrVec首元素指针
    string* begin() const{
        return elements;
    }
    //返回StrVec尾元素指针（已经使用的）
    string* end() const{
        return first_free;
    }
    void reserve(size_t n); //分配至少能容纳n个元素的空间
    void resize(size_t n); //将元素数量调整为n个
    void resize(size_t n, const string& s); //将元素数量调整为n个，多余的用s初始化
private:
    void free(); //销毁并释放内存
    void reallocate(); //获得更多内存并拷贝已有元素
    //检查容量是否满了，满了就要重新分配内存
    void chk_n_alloc(){
        if(size() == capacity())
            reallocate();
    }
    //工具函数，被拷贝构造函数、赋值运算符和析构函数所使用
    pair<string*, string*> alloc_n_copy(const string*, const string*);

private:
    string* elements; //指向数组首元素的指针
    string* first_free; //指向数组第一个空闲元素的指针
    string* cap; //指向数组尾后位置的指针
    allocator<string> alloc; //分配的元素        

};

class TextQuery{
public:
    using line_no = vector<string>::size_type;
    TextQuery(ifstream& ifs);
    QueryResult query(const string& s) const;
private:
    shared_ptr<StrVec> file;
    map<string, shared_ptr<set<line_no>>> wm;

};

class QueryResult{
friend ostream& print(ostream& os, const QueryResult& qr);
public:
    QueryResult(const string s, shared_ptr<set<TextQuery::line_no>> p,shared_ptr<StrVec> f):
                sought(s),lines(p),file(f){}

private:
    string sought;
    shared_ptr<set<TextQuery::line_no>> lines;
    shared_ptr<StrVec> file;
};

ostream& print(ostream& os, const QueryResult& qr);

#endif