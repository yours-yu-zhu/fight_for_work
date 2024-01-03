#include "TextQuery.h"

using namespace std;
class QueryResult;
class TextQuery;


TextQuery::TextQuery(ifstream &ifs):file(new vector<string>){
    string text;
    while(getline(ifs, text)){
        file->push_back(text);
        int n = file->size();
        istringstream line(text);
        string word;
        while(line >> word){
            shared_ptr<set<line_no>> &lines = wm[word];
            if(!lines){
                lines = make_shared<set<line_no>>();
            }
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const string& s) const{
    static shared_ptr<set<line_no>> nodata(new set<TextQuery::line_no>);
    auto loc = wm.find(s);
    if(loc == wm.end()){
        return QueryResult(s, nodata, file);
    }else{
        return QueryResult(s, loc->second, file);
    }
}

ostream& print(ostream& os, const QueryResult& qr){
    os << qr.sought << " occurs " << qr.lines->size() << " "
       << "time(s)" << endl;
    for(auto num : *(qr.lines)){
        os << "\t(line" << num << ") "  
           << *(qr.file->begin() + num - 1) <<endl;
    }
    return os;
}