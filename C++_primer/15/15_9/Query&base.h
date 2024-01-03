#ifndef QUER_AND_BASE_H
#define QUER_AND_BASE_H

#include "TextQuery.h"
#include <string>
#include <memory>

class Query;

class Query_base{
    friend class Query;
protected:
    using line_no = TextQuery::line_no;
    virtual ~Query_base() = default;
private:
    //eval纯虚函数
    virtual QueryResult eval(const TextQuery&) const = 0;
    //rep纯虚函数
    virtual string rep() const = 0;

};

class Query{
    friend Query operator~(const Query&);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);
public:
    Query(const string& s);//构造函数
    QueryResult eval(const TextQuery &t) const {
        return q->eval(t);
    }
    string rep() const {
        return q->rep();
    }
private:
    shared_ptr<Query_base> q;
    Query(shared_ptr<Query_base> query):q(query){
        cout << "Query(shared_ptr<Query_base> query)" << endl;
    } //构造函数

};
//重载<<运算符
inline
ostream& operator<<(ostream& os, const Query& query){
    return os << query.rep();
}


#endif