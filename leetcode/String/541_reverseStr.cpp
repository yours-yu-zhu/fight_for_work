#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
//全部手动实现的版本。
    void reverse(string &s, int begin, int end){
        while(begin < end){
            char tmp = s[begin];
            s[begin] = s[end];
            s[end] = tmp;
            ++begin;
            --end;
        }
    }
    string reverseStr(string s, int k) {
        for(int i = 0; i < s.size(); i += 2 * k){
            if(i + k < s.size()){
                reverse(s, i, i + k - 1);
            }else{
                reverse(s, i, s.size() - 1);
            }
        }
        return s;
    }
};

int main(){
    Solution solution;
    string s = "abcdefg";
    int k = 2;
    cout << solution.reverseStr(s, k) << endl;
    return 0;
}