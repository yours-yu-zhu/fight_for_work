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

using namespace std;

class QueryResult;

class TextQuery{
public:
    using line_no = vector<string>::size_type;
    TextQuery(ifstream& ifs);
    QueryResult query(const string& s) const;
private:
    shared_ptr<vector <string>> file;
    map<string, shared_ptr<set<line_no>>> wm;

};

class QueryResult{
friend ostream& print(ostream& os, const QueryResult& qr);
public:
    QueryResult(string s, shared_ptr<set<TextQuery::line_no>> p,shared_ptr<vector<string>> f):
                sought(s),lines(p),file(f){}
    shared_ptr<vector<string>> get_file() const{
        return file;
    }
    set<TextQuery::line_no>::iterator begin(){
        return lines->begin();
    }
    set<TextQuery::line_no>::iterator end(){
        return lines->end();
    }

private:
    string sought;
    shared_ptr<set<TextQuery::line_no>> lines;
    shared_ptr<vector<string>> file;
};

ostream& print(ostream& os, const QueryResult& qr);

#endif