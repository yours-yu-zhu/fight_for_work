#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        //起始或者末尾有障碍直接返回0
        if(obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1) return 0;
        vector<int> dp(n, 0);
        for(int j = 0; j < n && obstacleGrid[0][j] == 0; ++j) dp[j] = 1;

        for(int i = 1; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(obstacleGrid[i][j] == 1) dp[j] = 0;
                else if(j > 0) dp[j] += dp[j - 1];
            }
            //打印dp
            for(auto i : dp) cout << i << " ";
            cout << endl;
        }
        return dp[n -1];
    }
};

int main(){
    vector<vector<int>> obstacleGrid = {{0,0},{1,0}};
    Solution s;
    cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}