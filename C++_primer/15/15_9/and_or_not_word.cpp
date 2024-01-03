#include "and_or_not_word.h"
#include <algorithm>
using namespace std;

Query::Query(const string& s):q(new WordQuery(s)){
    cout << "Query(const string& s) -- " << "s: " << s << endl;
}

Query operator~(const Query &operand){
    return shared_ptr<Query_base>(new NotQuery(operand));
}

Query operator&(const Query &lhs, const Query &rhs){
    return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

Query operator|(const Query &lhs, const Query &rhs){
    return shared_ptr<Query_base>(new OrQuery(lhs ,rhs));
}

QueryResult NotQuery::eval(const TextQuery &t) const {
    auto result = query.eval(t);
    auto ret_lines = make_shared<set<TextQuery::line_no>>();
    auto beg = result.begin(), end = result.end();
    auto sz = result.get_file()->size();
    cout << "sz: " << sz << endl; 
    for (size_t n = 1; n < sz + 1; ++n) {
        bool exist = false;
        for(auto i = beg; i != end; ++i){
            if(n == *i){
                exist = true;
                break;
            }
        }
        if(!exist){
            ret_lines->insert(n);
        }
    }
    return QueryResult(rep(), ret_lines, result.get_file());
}

QueryResult AndQuery::eval(const TextQuery &t) const {
    auto left = lhs.eval(t), right = rhs.eval(t);
    auto ret_lines = make_shared<set<TextQuery::line_no>>();
    set_intersection(left.begin(), left.end(), 
                    right.begin(), right.end(), 
                    inserter(*ret_lines, ret_lines->begin()));
    return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult OrQuery::eval(const TextQuery &t) const {
    auto left = lhs.eval(t), right = rhs.eval(t);
    auto ret_lines = make_shared<set<TextQuery::line_no>>(left.begin(), left.end());
    ret_lines->insert(right.begin(), right.end());
    return QueryResult(rep(), ret_lines, left.get_file());
}