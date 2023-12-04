#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <deque>
#include <vector>
#include <forward_list>
#include <stack>

using namespace std;
//9.27 编写程序，查找并删除forward_list<int>中的奇数元素。
void find_and_delete(forward_list<int> &data){
    auto prev = data.before_begin();
    auto curr = data.begin();
    while(curr != data.end()){
        if(*curr % 2 != 0){
            curr = data.erase_after(prev);
        }else{
            prev = curr;
            ++curr;
        }
    }
    
}

//9.28
void find_and_insert(forward_list<string>& flst, const string& s1, const string& s2){
    auto prev = flst.before_begin();
    auto curr = flst.begin();
    while (curr != flst.end()) 
    {
        if(*curr == s1){
            flst.insert_after(curr,s2);
            break;
        }
        prev = curr;
        ++curr;
    }
    if(curr == flst.end()){
        flst.insert_after(prev,s2);
    }
    
}

//9.43 
void replace_with(string& s,const string& oldVal,const string& newVal){
    auto curr =s.begin();
    while(curr <= s.end() - oldVal.size()){  //这里小于等于很重要，因为curr可能会指向s.end()，这时候curr + oldVal.size()就会越界
        if (oldVal == string{ curr, curr + oldVal.size() })
        {
            curr = s.erase(curr,curr + oldVal.size());
            curr = s.insert(curr,newVal.begin(),newVal.end());
            curr += newVal.size();
        }else{
            ++curr;
        }
        
    }
    cout << s << endl;
    
}

//9.44
void replace_witn_number(string& s,const string& oldVal,const string& newVal){
    size_t i = 0;
    while(i <= s.size() - oldVal.size()){
        if(s.substr(i,oldVal.size()) == oldVal){
            s.replace(i,oldVal.size(),newVal);
            i += newVal.size();
        }else{
            ++i;
        }
    }
}

//9.45
string add_pre_and_suffix(string& name,const string&pre,const string& suffix){
    name.insert(name.begin(),pre.begin(),pre.end());
    name.append(suffix);
    return name;
}

//9.46
string add_pre_and_suffix2(string& name,const string&pre,const string& suffix){
    name.insert(0,pre);
    name.insert(name.size(),suffix);
    return name;
}

//9.51
class My_Date{
private:
    unsigned year;
    unsigned month;
    unsigned day;
public:
    My_Date(const string& s){
        int format = 0;
        //是否为 xx/xx/xxx 
        if (s.find_first_of("/") != string::npos){
            format =1;
        }

        //是否为 xxx xxx,xxx
        if (s.find_first_of(",") != string::npos && s.find_first_of(',') >= 4){
            format = 2;
        }
        else if (s.find_first_of(" ") != string::npos && s.find_first_of(' ') >= 3){
            format = 3;
        }
        cout << "format = " << format << endl;
        switch (format)
        {
        case 1:
            day = stoi(s.substr(0,s.find_first_of("/")));
            month = stoi(s.substr(s.find_first_of("/") +1,s.find_last_of("/") - s.find_first_of("/") - 1));
            year = stoi(s.substr(s.find_last_of("/") + 1));
            break;
        
        case 2:
            year = stoi(s.substr(s.find_last_of(",") + 1));
            day = stoi(s.substr(s.find_first_of(" ") + 1,s.find_first_of(",") - s.find_first_of(" ") - 1));
            if( s.find("Jan") < s.size() )  month = 1;
            if( s.find("Feb") < s.size() )  month = 2;
            if( s.find("Mar") < s.size() )  month = 3;
            if( s.find("Apr") < s.size() )  month = 4;
            if( s.find("May") < s.size() )  month = 5;
            if( s.find("Jun") < s.size() )  month = 6;
            if( s.find("Jul") < s.size() )  month = 7;
            if( s.find("Aug") < s.size() )  month = 8;
            if( s.find("Sep") < s.size() )  month = 9;
            if( s.find("Oct") < s.size() )  month =10;
            if( s.find("Nov") < s.size() )  month =11;
            if( s.find("Dec") < s.size() )  month =12;
            break;
        case 3:
            year = stoi(s.substr(s.find_last_of(" ") + 1));
            day = stoi(s.substr(s.find_first_of(" ") + 1,s.find_last_of(" ") - s.find_first_of(" ") - 1));
            if( s.find("Jan") < s.size() )  month = 1;
            if( s.find("Feb") < s.size() )  month = 2;
            if( s.find("Mar") < s.size() )  month = 3;
            if( s.find("Apr") < s.size() )  month = 4;
            if( s.find("May") < s.size() )  month = 5;
            if( s.find("Jun") < s.size() )  month = 6;
            if( s.find("Jul") < s.size() )  month = 7;
            if( s.find("Aug") < s.size() )  month = 8;
            if( s.find("Sep") < s.size() )  month = 9;
            if( s.find("Oct") < s.size() )  month =10;
            if( s.find("Nov") < s.size() )  month =11;
            if( s.find("Dec") < s.size() )  month =12;
            break;
        default:
            cout << "输入格式错误" << endl;
            break;
        }

    }
    void print(){
        cout << "year = " << year << endl;
        cout << "month = " << month << endl;
        cout << "day = " << day << endl;
    }
};


    


int main(){
    //9.27
    // forward_list<int> data = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    // find_and_delete(data);
    // for(auto i : data){
    //     cout << i << endl;
    // }

    //9.28 测试find_and_insert函数功能
    // forward_list<string> data = {"hello","world","!"};
    // find_and_insert(data,"a","test");
    // for(auto i : data){
    //     cout << i << endl;
    // }

    // //9.41
    // vector<char> vc = {'a','b','c','d','e'};
    // string s(vc.begin(),vc.end());
    //  cout << s << endl;   

    //9.43 测试replace_with函数功能
    // string s = "tho thru tho!";
    // replace_with(s,"tho","though");
    
    //9.44 测试replace_witn_number函数功能
    // string s = "tho thru tho!";
    // replace_witn_number(s,"tho","though");
    // cout << s << endl;

    //9.45 测试add_pre_and_suffix函数功能
    // string name = "Bob";
    // cout << add_pre_and_suffix(name,"Mr.","Jr.") << endl;

    //9.46 测试add_pre_and_suffix2函数功能
    // string name = "Bob";
    // cout << add_pre_and_suffix2(name,"Mr.","Jr.") << endl;

    // //9.47
    // string numbers = "0123456789";
    // string s = "ab2c3d7R4E6";
    // cout << "s中数字字符有：" << endl;
    // for(size_t pos = 0;(pos = s.find_first_of(numbers,pos)) != string::npos;++pos){
    //     cout << s[pos] << " ";
    // }
    // cout << endl;
    // cout <<"s中的字母字符有：" << endl;
    // for(size_t pos = 0;(pos = s.find_first_not_of(numbers,pos)) != string::npos;++pos){
    //     cout << s[pos] << " ";
    // }

    //9.49
    // ifstream ifs("/home/ubuntu/fight_for_work/C++_primer/9/test.txt");
    // if (!ifs)
    // {
    //     cout << "打开文件失败" << endl;
    //     return -1;
    // }
    // string logest_word;
    // string cur;
    // while (ifs >> cur){
    //     if ((cur.find_first_not_of("aceimnorsuvwxz")) == string::npos && cur.size() > logest_word.size()){
    //         logest_word = cur;
    //     }
    // }
    // cout << "最长的单词是：" << logest_word << endl;

    
    //9.50
    //int
    // vector<string> v = {"1","2","3","4","5.5"};
    // int sum = 0;
    // for(auto i : v){
    //     sum += stoi(i);
    // }
    // cout << "sum = " << sum << endl;

    //float
    // vector<string> v = {"1","2","3","4","5.5"};
    // float sum = 0;
    // for(auto i : v){
    //     sum += stof(i);
    // }
    // cout << "sum = " << sum << endl;
    
    //9.51 测试My_Date类
    // My_Date date("12/1/1990");  
    //测试第二种格式
    // My_Date date("December 22,1990");
    //测试第三种格式
    // My_Date date("Dec 22 1990");
    // date.print();

    //9.52
    string expression{ "This is (pezy)." };
    bool bSeen = false;
    stack<char> stk;
    for (const auto &s : expression)
    {
        if (s == '(') { bSeen = true; continue; }
        else if (s == ')') bSeen = false;
        
        if (bSeen) stk.push(s);
    }
    
    string repstr;
    while (!stk.empty())
    {
        repstr += stk.top();
        stk.pop();
    }
    
    expression.replace(expression.find("(")+1, repstr.size(), repstr);
    
    cout << expression << endl;
}