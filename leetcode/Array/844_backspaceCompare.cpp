#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return clear(s) == clear(t);
    }
    string clear(string s){
        int slow = 0, fast = 0;
        int size = s.size();
        for(; fast < size; ++fast){
            if(s[fast] != '#'){
                s[slow] = s[fast];
                ++slow;
            }else{
                --slow;
            }
        }
        return s.substr(0, slow);
    }
};

/*
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        changestring(s);
        changestring(t);
        return s==t;
    }
    void changestring(string &s)
    {
        int slow=0;
        for(int fast=0;fast<s.size();fast++)
        {
            if(s[fast]!='#')
            s[slow++]=s[fast];
            else if(slow!=0)
                slow--;
        }
        s.resize(slow);
    }
};*/

int main(){
    Solution sol;
    string s = "ab#c";
    string t = "ad#c";
    cout << sol.backspaceCompare(s, t) << endl;
    return 0;
    
}