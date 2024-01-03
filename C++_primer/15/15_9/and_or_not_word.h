#ifndef AND_OR_NOT_WORD_H
#define AND_OR_NOT_WORD_H

#include "Query&base.h"
using namespace std;

//wordquery查询
class WordQuery: public Query_base{
    friend class Query;
    WordQuery(const string &s):query_word(s){
        cout << "WordQuery(const std::string&) -- " << "query_word: " << query_word << endl;
    }
    QueryResult eval(const TextQuery &t) const override{
        return t.query(query_word);
    }
    string rep() const override{
        return query_word;
    }
    string query_word;
};


//NotQuery查询
class NotQuery: public Query_base{
    friend Query operator~(const Query &);
    NotQuery(const Query &q):query(q){}
    string rep() const override{
        return "~(" + query.rep() + ")";
    } 
    QueryResult eval(const TextQuery &t) const override;    
    Query query;
};


//BinaryQuery
class BinaryQuery: public Query_base{
protected:
    Query lhs, rhs;
    string opSym;
    BinaryQuery(const Query &l, const Query &r, string s):lhs(l), rhs(r), opSym(s){
        cout << "BinaryQuery(const Query&, const Query&, string) -- "
            << "(" << l << ", " << r << ", " << s << ")" << endl;
    }
    string rep() const override{
        return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
    }
};

//AndQuery查询
class AndQuery: public BinaryQuery{
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query &left, const Query &right):BinaryQuery(left, right, "&"){
        cout << "AndQuery(const Query&, const Query&) -- "
            << "(" << left << ", " << right << ")" << endl;    
    }
    QueryResult eval(const TextQuery &t) const override;    
};



//OrQuery查询
class OrQuery: public BinaryQuery{
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query &left, const Query &right):BinaryQuery(left, right, "|"){
        cout << "OrQuery(const Query&, const Query&) -- "
            << "(" << left << ", " << right << ")" << endl;    
    }
    QueryResult eval(const TextQuery &t) const override;
};



#endif