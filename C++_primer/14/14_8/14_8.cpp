#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <functional>
#include <map>

using namespace std;

//ex14.34
class Test{
public:
    int operator()(bool b, int i, int j){
        return b ? i : j;
    }
};

void ex14_34(){
    Test t;
    cout << t(false, 1, 2) << endl;    
}

//ex14.35
class PrintString{
public:
    PrintString(istream& i = cin): is(i){}
    string operator()(){
        string s;
        getline(is, s);
        return is ? s : string();
    }
private:
    istream& is;
};

void ex14_35(){
    PrintString ps;
    cout << ps() << endl;
}

void ex14_36(){
    PrintString ps;
    vector<string> vs;
    for(string s; !((s = ps()).empty()); vs.push_back(s)){}
    for(auto& s : vs){
        cout << s << endl;
    }

}

//ex14.37
class isEqual{
public:
    isEqual(int i): val(i){}
    bool operator()(int i){
        return i == val;
    }
private:
    int val;
};

void ex14_37(){
    vector<int> vi{1, 2, 3, 4, 5, 6, 7, 8, 9};
    replace_if(vi.begin(), vi.end(), isEqual(5), 0);
    for(auto& i : vi){
        cout << i << endl;
    }
}

//ex14.38
class StrLenIs{
public:
    StrLenIs(int i):len(i){}
    bool operator()(const string& s){
        return s.length() == len;
    }
private:
    int len;
};

void ex14_38(){
    vector<string> vs;
    fstream fs("/home/ubuntu/fight_for_work/C++_primer/14/14_8/data.txt");
    string line;
    string word;
    while(getline(fs, line)){
        istringstream iss(line);
        while(iss >>word){
            vs.push_back(word);
        }
    }
    const int minLen = 1;
    const int maxLen = 10;
    for(int i = minLen; i <= maxLen; ++i){
        cout << "len:" << i << " ,count:" << count_if(vs.begin(), vs.end(), StrLenIs(i)) << endl;
    }   
}

//14.39 
class StrLenBetween{
public:
    StrLenBetween(int i, int j):minlen(i), maxlen(j){}
    bool operator()(const string& s){
        return s.length() >= minlen && s.length() <= maxlen;
    }
private:
    int minlen;
    int maxlen;
};

class StrLenLongerThan{
public:
    StrLenLongerThan(int i):minlen(i){}
    bool operator()(const string& s){
        return s.length() >= minlen;
    }
private:
    int minlen;
};

void ex14_39(){
    vector<string> vs;
    fstream fs("/home/ubuntu/fight_for_work/C++_primer/14/14_8/data.txt");
    string line;
    string word;
    while(getline(fs, line)){
        istringstream iss(line);
        while(iss >>word){
            vs.push_back(word);
        }
    }
    cout << "len between 1 and 9:" << count_if(vs.begin(), vs.end(), StrLenBetween(1, 9)) << endl;
    cout << "len longer than 10:" << count_if(vs.begin(), vs.end(), StrLenLongerThan(10)) << endl;
}

void ex14_42(){
    //// 统计大于 1024 的值有多少个
    vector<int> ivec{1000, 2000, 3000, 4000, 5000};
    cout << "大于1024的个数:" << count_if(ivec.begin(), ivec.end(), bind(greater<int>(), placeholders::_1, 1024)) << endl;
    // 找到第一个不等于 pooth 的字符串
    vector<std::string> svec{"pooth", "pooth", "abc", "pooth"};
    cout << "第一个不等于pooth的字符串:" << *find_if(svec.begin(), svec.end(), bind(not_equal_to<string>(), placeholders::_1, "pooth")) << endl;
    // 将所有的值乘以2
    transform(ivec.begin(), ivec.end(),ivec.begin(),bind(multiplies<int>(), placeholders::_1, 2));
    for(auto& i : ivec){
        cout << i << endl;
    }
}

class Isdivisible{
public:
    Isdivisible(modulus<int> i):mod(i){}
    bool operator()(int x) const{
        return mod(100,x) == 0;
    }

private:
    modulus<int> mod;
};

void ex14_43(){
    vector<int> ivec{1, 2, 4, 5, 10};
    modulus<int> mod;
    Isdivisible a(mod);
    for(auto& i : ivec){
        if(!a(i)){
           cout << "no" << i << endl;
           return;
        }
    } 
    cout << "yes" << endl;  
}

int add(int i, int j){
    return i + j;
}

using minusInt = minus<int>;

auto mod = [](int i, int j){return i % j;};

class divideInt{
    public:
        int operator()(int i, int j){
            return i / j;
        }
};

map<string, function<int(int, int)>> binops = {
    {"+", add},
    {"-", minusInt()},
    {"*", [](int i, int j){return i*j;}},
    {"/", divideInt()},
    {"%", mod}
};

void ex14_44(){
    cout << binops["+"](10, 5) << endl;
    cout << binops["-"](10, 5) << endl;
    cout << binops["*"](10, 5) << endl;
    cout << binops["/"](10, 5) << endl;
    cout << binops["%"](10, 5) << endl;
}



int main() {
    // ex14_34();
    // ex14_35();
    // ex14_36();
    // ex14_37();
    // ex14_38();
    // ex14_39();
    // ex14_42();
    // ex14_43();
    ex14_44();
}
