#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for(int j = 0; j <= s.size(); ++j){
            cout << "--------j: " << j << endl;
            for(int i = 0; i < wordDict.size(); ++i){
                string word = s.substr(j, wordDict[i].size());
                cout << "word: " << word << endl;
                if(word == wordDict[i] && dp[j] == true) dp[j + wordDict[i].size()] = true;
                //cout dp
                for(int i = 0; i < dp.size(); ++i){
                    cout << dp[i] << " ";
                }
                cout << endl;
                }

        }
        return dp[s.size()];
    }
};

int main(){
    Solution sol;
    string s = "applepenapple";
    vector<string> wordDict = {"apple", "pen"};
    cout << sol.wordBreak(s, wordDict) << endl;
    return 0;
}