#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <deque>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//10.9
void elimDups(vector<string> &s){
    for (auto i : s)
        cout << i << " ";
    cout << endl;
    sort(s.begin(), s.end());
    for (auto i : s)
        cout << i << " ";
    cout << endl;
    auto end_unique = unique(s.begin(), s.end());
    for (auto i : s)
        cout << i << " ";   
    cout << endl;
    s.erase(end_unique, s.end());
    for (auto i : s)
        cout << i << " ";
    cout << endl;
}

//10.10
    bool isShorter(const string &s1, const string &s2){
        return s1.size() < s2.size();
    }

//10.13
    bool predict_5(const string &s){
        return s.size() >= 5;
    }

int main(int argc, char **argv)
{
//10.1
    //生成一个int的vector，并初始化，要求一些重复元素
    // vector<int> v = { 1, 2, 3, 4, 5, 6, 6, 6, 2 };
    // int i;
    // cout << "input a number: ";
    // cin >> i;
    // cout << "the number " << i << " appears " << count(v.cbegin(), v.cend(),i)<< " times" << endl;
//10.2
    // list<string> l = { "a", "b", "c", "d", "e", "f", "a", "a", "b" };
    // string s;
    // cout << "input a string: ";
    // cin >> s;
    // cout << "the string " << s << " appears " << count(l.cbegin(), l.cend(), s) << " times" << endl;
//10.3
    // vector<int> v = { 1, 2, 3, 4, 5, 6, 6, 6, 2 };
    // cout << "求和："<< accumulate(v.cbegin(), v.cend(), 0) << endl;
//10.4,需要为0.0 否则会只会计算出整数
    // std::vector<double> vd = { 1.1, 0.5, 3.3 };
    // std::cout   << "ex 10.04: "
    //             << std::accumulate(vd.cbegin(), vd.cend(), 0)
    //             << std::endl;  
//10.6
    // vector<int> vec{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    // for (auto i : vec)
    //     cout << i << " ";
    // cout << endl;   
    // fill_n(vec.begin(), vec.size(),0);
    // for (auto i : vec)
    //     cout << i << " ";
    // cout << endl;

//10.9 测试elimDups
    // vector<string> svec = { "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "quick", "turtle" };
    // elimDups(svec);
    // return 0;

//10.10 测试
    // vector<string> svec = { "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "quick", "turtle" };
    // elimDups(svec);
    // stable_sort(svec.begin(), svec.end(), isShorter);
    // for (auto i : svec)
    //     cout << i << " ";
    // cout << endl;

//10.13
    // vector<string> svec = { "thesssasad", "quick", "red", "fox", "jumps", "over", "the", "slow", "quick", "turtle" };
    // auto pos = partition(svec.begin(), svec.end(), predict_5);
    // for(auto i = svec.begin(); i != pos; ++i)
    //     cout << *i << " ";
    // cout << endl;

}