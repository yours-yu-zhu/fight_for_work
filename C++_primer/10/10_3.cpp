#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

//10.27
void ex10_27()
{
    vector<int> vec = { 1, 1, 3, 3, 5, 5, 7, 7, 9 };
    list<int> lst;
    unique_copy(vec.begin(), vec.end(), back_inserter(lst));
    for (auto i : lst)
        cout << i << " ";
    cout << endl;
}
//10.28
void ex10_28()
{
    vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    //use inserter
    vector<int> vec1 = {1,2,3};
    copy(vec.begin(), vec.end(), inserter(vec1, vec1.end()));
    cout << "use inserter: ";
    for (auto i : vec1)
        cout << i << " ";   
    cout << endl;

    //use back_inserter
    vector<int> vec2 = {1,2,3};
    copy(vec.begin(), vec.end(), back_inserter(vec2));
    cout << "use back_inserter: ";
    for (auto i : vec2)
        cout << i << " ";   
    cout << endl;

    //use front_inserter
    list<int> vec3 = {1,2,3};
    copy(vec.begin(), vec.end(), front_inserter(vec3));
    cout << "use front_inserter: ";
    for (auto i : vec3)
        cout << i << " ";   
    cout << endl;
}
//10.29
void ex10_29(){
    ifstream ifs("/home/ubuntu/fight_for_work/C++_primer/10/1.txt");
    istream_iterator<string> in(ifs), eof;
    vector<string> vec;
    while(in != eof){
        vec.push_back(*in++);
    }
    for (auto i : vec)
        cout << i << " ";
    cout << endl;
}
//10.30
void ex10_30(){
    vector<int> vec;
    istream_iterator<int> in(cin), eof;
    ostream_iterator<int> out(cout, " ");
    copy(in,eof,back_inserter(vec));
    sort(vec.begin(),vec.end());
    copy(vec.begin(),vec.end(),out);
    cout << endl;
}
//10.31
void ex10_31(){
    vector<int> vec;
    istream_iterator<int> in(cin), eof;
    ostream_iterator<int> out(cout, " ");
    copy(in,eof,back_inserter(vec));
    sort(vec.begin(),vec.end());
    unique_copy(vec.begin(),vec.end(),out);
    cout << endl;
}

//10.33
void in_2out(const string &in_file, const string &out_file1, const string &out_file2)
{
    ifstream ifs(in_file);
    ofstream ofs1(out_file1), ofs2(out_file2);
    istream_iterator<int> in(ifs),eof;
    ostream_iterator<int> out1(ofs1," "), out2(ofs2, "\n");
    while(in != eof){
        if(*in % 2 == 0){
            *out2++ = *in++;
        }else{
            *out1++ = *in++;
        } 
    }
}
void ex10_33(){
    in_2out("/home/ubuntu/fight_for_work/C++_primer/10/1.txt","/home/ubuntu/fight_for_work/C++_primer/10/2.txt","/home/ubuntu/fight_for_work/C++_primer/10/3.txt");
}

//10.34
void ex10_34(){
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    ostream_iterator<int> out(cout," ");
    copy(v.crbegin(), v.crend(), out);
    cout << endl;
}

//10.35
void ex10_35(){
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    for(auto it = v.cend() - 1;true; --it){
        cout << *it << " ";
        if(it == v.cbegin()) break;
    }
}

void ex10_36(){
    list<int> lst = {1,2,3,4,5,6,7,0,8,0,9};
    auto it = find(lst.crbegin(), lst.crend(), 0);
    cout << distance(it,lst.crend()) << endl;
}

void ex10_37(){
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    list<int> lst;
    copy(v.crbegin() + 3, v.crbegin() + 8, back_inserter(lst));
    for(auto i : lst){
        cout << i << " ";
    }
    cout << endl;
}

void ex10_42(){
    list<string> lst = { "aa", "aa", "aa", "aa", "aasss", "aa" };
    lst.sort();
    lst.unique();
    for (auto i : lst)
        cout << i << " ";
    cout << endl;

}

int main(int argc, char **argv)
{
    // ex10_27();
    // ex10_28();
    // ex10_29();
    // ex10_30();
    // ex10_31();
    // ex10_33();
    // ex10_34();
    // ex10_35();
    // ex10_36();
    // ex10_37();
    ex10_42();
}


