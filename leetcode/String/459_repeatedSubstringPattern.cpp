#include <iostream>
#include <string>
#include <algorithm>
#include <vector>   
#include <sstream>

using namespace std;
    class Solution {
    public:
        void getNext(const string& s, vector<int>& next){
            next[0] = 0;
            for(int i = 1; i < s.size(); ++i){
                int j = next[i - 1];
                while(j > 0 && s[i] != s[j]){
                    j = next[j - 1];
                }
                if(s[i] == s[j]){
                    next[i] = j + 1;
                }else{
                    next[i] = 0;
                }
            }
        }
        bool repeatedSubstringPattern(string s) {
            vector<int> next(s.size(), 0);
            getNext(s, next);
            //cout next
            for(int i = 0; i < next.size(); ++i){
                cout << next[i] << " ";
            }
            cout << endl;
            return false;
            
        }

    };

int main(){
    Solution sol;
    string s = "abab";
    cout << sol.repeatedSubstringPattern(s) << endl;
    return 0;
}