#include "and_or_not_word.h"
#include "TextQuery.h"
#include "Query&base.h"

using namespace std;

void ex15_36(){
    ifstream ifs("/home/ubuntu/fight_for_work/C++_primer/15/15_9/data.txt");
    TextQuery tq(ifs);
    string s1 = "fiery", s2 = "bird", s3 = "wind";
    Query q = Query(s1) & Query(s2) | Query(s3);
    cout << "\nExecuting Query for: " << q << endl;
}

void ex15_39_wordQuery(){
    ifstream ifs("/home/ubuntu/fight_for_work/C++_primer/15/15_9/data.txt");
    TextQuery tq(ifs);
    string s1 = "Daddy";
    Query q = Query(s1);
    cout << "\nExecuting Query for: " << q << endl;
    QueryResult result = q.eval(tq);
    print(cout, result);
}

void ex15_39_NotQuery(){
    ifstream ifs("/home/ubuntu/fight_for_work/C++_primer/15/15_9/data.txt");
    TextQuery tq(ifs);
    string s1 = "Alice";
    Query q = ~Query(s1);
    cout << "\nExecuting Query for: " << q << endl;
    QueryResult result = q.eval(tq);
    print(cout, result); 
}

void ex15_39_OrQueur(){
    ifstream ifs("/home/ubuntu/fight_for_work/C++_primer/15/15_9/data.txt");
    TextQuery tq(ifs);
    string s1 = "Alice", s2 = "hair";
    Query q = Query(s1) | Query(s2);
    cout << "\nExecuting Query for: " << q << endl;
    QueryResult result = q.eval(tq);
    print(cout, result); 
}

void ex15_39_AndQueury(){
    ifstream ifs("/home/ubuntu/fight_for_work/C++_primer/15/15_9/data.txt");
    TextQuery tq(ifs);
    string s1 = "Alice", s2 = "hair";
    Query q = Query(s1) & Query(s2);
    cout << "\nExecuting Query for: " << q << endl;
    QueryResult result = q.eval(tq);
    print(cout, result); 
}

int main() {
    // ex15_36();
    // ex15_39_wordQuery();
     ex15_39_NotQuery();
    // ex15_39_OrQueur();
    // ex15_39_AndQueury();

}

