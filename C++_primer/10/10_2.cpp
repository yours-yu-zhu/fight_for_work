#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <deque>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std;

//10.9
void elimDups(vector<string> &s){
    sort(s.begin(), s.end());
    auto end_unique = unique(s.begin(), s.end());
    s.erase(end_unique, s.end());
}

//10.16
void zuida(vector<string>& s, vector<string>::size_type sz){
    //消除重复元素
    elimDups(s);
    //按照长度大小排序，和字典序列
    stable_sort(s.begin(), s.end(), [](const string &a, const string &b) -> bool {return a.size() < b.size();});
    auto pos = find_if(s.begin(), s.end(), [sz](const string &a) -> bool {return a.size() >= sz;});
    for_each(pos, s.end(), [](const string &a) -> void{ cout << a << " ";});

}
//10.18
void zuida_2(vector<string>& s, vector<string>::size_type sz){
    //消除重复元素
    elimDups(s);
    //按照长度大小排序，和字典序列
    stable_sort(s.begin(), s.end(), [](const string &a, const string &b) -> bool {return a.size() < b.size();});
    auto pos = partition(s.begin(), s.end(), [sz](const string &a) -> bool {return a.size() >= sz;});
    for_each(s.begin(), pos, [](const string &a) -> void{ cout<< a << " ";});
}

//10.18
void zuida_3(vector<string>& s, vector<string>::size_type sz){
    //消除重复元素
    elimDups(s);
    //按照长度大小排序，和字典序列
    //stable_sort(s.begin(), s.end(), [](const string &a, const string &b) -> bool {return a.size() < b.size();});
    auto pos = stable_partition(s.begin(), s.end(), [sz](const string &a) -> bool {return a.size() >= sz;});
    for_each(s.begin(), pos, [](const string &a) -> void{ cout<< a << " ";});
}

//10.20
int bigger6(vector<string> &s){
    return count_if(s.begin(), s.end(), [](const string &a)-> bool {return a.size() >= 6;} );
}

//10.21
bool dijian(int &a){
    return [&a]() -> bool {
        if (a > 0){
            --a;
            return false;
        }
        else
            return true;
    }();
    };
//10.22
bool islargeerThanOrEqualTo6(const string &s,string::size_type sz){
    return s.size() >= sz;
}
int bigger6_2(vector<string> &s){
    auto x = bind(islargeerThanOrEqualTo6, placeholders::_1, 6);
    return count_if(s.begin(), s.end(), x);
}
//10.23 
bool check_size(const string &s, string::size_type sz){
    return s.size() < sz;
}
void find_first_bigger(vector<int> &v, const string &s){
    auto x = find_if(v.begin(), v.end(), bind(check_size,s,placeholders::_1));
    if (x != v.end())
        cout << *x << endl;
    else
        cout << "not found" << endl;
}

//10.24
void zuida_4(vector<string>& s, vector<string>::size_type sz){
    //消除重复元素
    elimDups(s);
    //按照长度大小排序，和字典序列
    //stable_sort(s.begin(), s.end(), [](const string &a, const string &b) -> bool {return a.size() < b.size();});
    auto pos = stable_partition(s.begin(), s.end(), bind(check_size,placeholders::_1,sz));
    for_each(pos, s.end(), [](const string &a) -> void{ cout<< a << " ";});
}

int main(int argc, char **argv)
{
//10.14
    // auto f = [](int a ,int b) {return a + b;};
    // cout << f(1,1)<<endl;
//10.15
    // int x = 10;size
    // auto f = [x](int a) -> int {return a + x;};
    // cout << f(1)<<endl;

//10.16 测试zuida函数
    // vector<string> v = {"1234", "1234", "1234", "hi~", "alan", "alan", "cp"};
    // zuida(v, 3);
    // cout << endl;
    // return 0;
//10.18 
    vector<string> v = {"1234", "1234", "1234", "hi~", "alan", "alan", "cp"};
    zuida_2(v, 3);
    cout << endl;

//10.19
    // vector<string> v = {"1234", "1234", "1234", "hi~", "alan", "alan", "cp"};
    // zuida_3(v, 3);
    // cout << endl;
    // return 0;
//10.20 测试bigger6函数
    // vector<string> v = {"alan","moophy","1234567","1234567","1234567","1234567"};
    // cout << bigger6(v) << endl;
    // return 0;
//10.21 循环测试dijian函数
    // int a = 10;
    // while(!dijian(a))
    //     cout << a << endl;
    // cout <<"final: "<< dijian(a) << endl;
    // return 0;
//10.22 test
    // vector<string> v = {"alan","moophy","1234567","1234567","1234567","1234567"};
    // cout << bigger6_2(v) << endl;
    // return 0;
//测试10.24
    // vector<int> v = {1,2,3,4,5,6,7,8,9};
    // string s = "alansadaddasdfad";
    // find_first_bigger(v, s);
    // return 0;
//10.25 test
    vector<string> v2 = {"1234", "1234", "1234", "hi~", "alan", "alan", "cp"};
    zuida_4(v2, 3);
    cout << endl;

    
}