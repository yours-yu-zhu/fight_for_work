#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    //检查是否满足left左移条件
    bool check(unordered_map<char, int> &dict){
        for(const auto &p : dict){
            if(p.second > 0){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        unordered_map<char, int> dict;
        for(auto &c : t){
            ++dict[c];
        }
        int left = 0, right = 0;//滑动窗口的左右边界
        int size = s.size();//字符串s的长度
        int length = INT32_MAX;//最小子串的长度
        int result = 0;//最小子串的起始位置
        for(; right < size; ++right){
            if(dict.find(s[right]) != dict.end()){
                --dict[s[right]];
            }
            while(check(dict)){
                //每次找到新的最小字串记得保存他的起始位置和长度
                if(length > right - left + 1){
                    length = right - left + 1;
                    result = left;
                }
                if(dict.find(s[left]) != dict.end()){
                    ++dict[s[left]];
                }
                ++left;                
            }
        }
        return length == INT32_MAX ? string() : s.substr(result, length);

    }
};


int main(){
    Solution sol;
    string s = "cabwefgewcwaefgcf";
    string t = "cae";
    cout << sol.minWindow(s, t) << endl;
    return 0;
}