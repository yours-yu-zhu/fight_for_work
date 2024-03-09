#include <iostream>
#include <string>
#include <algorithm>
#include <vector>   
#include <sstream>

using namespace std;
class Solution {
public:
//方案一，全部手动
    string reverseWords(string s) {
        //第一步，先反转整体字符串
        reverse(s.begin(), s.end());
        //第二步，去除多余的空格‘ ’
        int slow = 0, fast = 0;
        //他的移除单词其实是以单词为单位的。
        for(; fast < s.size(); ++fast){
            //fast排除不是空格
            if(s[fast] != ' '){
                if(slow != 0){
                    s[slow++] = ' ';
                    //首个单词不加空格
                }
                //对接下来的一个单词直接填充
                while(fast < s.size() && s[fast] != ' '){
                    s[slow++] = s[fast++];
                }
            }
        }
        s.resize(slow);
        int start = 0;
        //再针对每个单词单独反转
        for(int i = 0; i <= s.size(); ++i){
            if(i == s.size() || s[i] == ' '){
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }

        return s;
    }
    string reverseWords1(string s) {
        istringstream is(s);
        vector<string> vec;
        string word;
        string result;
        while(is >> word){
            vec.push_back(word);
        }
        for(int i = vec.size() - 1; i >= 0; --i){
            result += vec[i];
            if(i > 0){
                result += " ";
            }       
        } 
        return result;   
    } 
};


int main(){
    Solution s;
    string str = " the sky is blue ";
    cout << s.reverseWords1(str) << endl;
    return 0;
}