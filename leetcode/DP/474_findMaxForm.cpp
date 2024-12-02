#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(auto str : strs){
            int one_num = 0;
            int zero_num = 0;
            for(auto ch : str){
                if(ch == '0') ++zero_num;
                else ++one_num;
            }
            for(int i = m; i >= zero_num; --i){
                for(int j = n; j >= one_num; --j){
                    dp[i][j] = max(dp[i][j], dp[i - zero_num][j - one_num] + 1);
                }
            }
            //打印dp
            for(int i = 0; i <= m; ++i){
                for(int j = 0; j <= n; ++j){
                    cout << dp[i][j] << " ";
                }
                cout << endl;
            }
            cout <<"________" <<endl;
        }
        return dp[m][n];
    }
};

int main(){
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    int m = 5;
    int n = 3;
    Solution s;
    cout << s.findMaxForm(strs, m, n) << endl;
    return 0;
}