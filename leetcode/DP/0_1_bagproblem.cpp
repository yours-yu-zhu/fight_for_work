#include <iostream>
#include <vector>
using namespace std;

int solve(int item_num, int bag_size, vector<int>& weight, vector<int>& value){
    vector<vector<int>> dp(item_num, vector<int>(bag_size + 1, 0));
    //初始化第一行，第一列已经默认初始化
    for(int j = 0; j < dp[0].size(); ++j){
        if(j >= weight[0]) dp[0][j] = value[0];
    }
    
    for(int i = 1; i < dp.size(); ++i){
        for(int j = 1; j < dp[0].size(); ++j){
            if(j - weight[i] < 0) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
        }
        
    }
    
    return dp[item_num - 1][bag_size];
    
    
}


int main(){
    int item_num, bag_size;
    cin >> item_num >> bag_size;
    vector<int> weight(item_num, 0);
    vector<int> value(item_num, 0);
    for(int i = 0; i < weight.size(); ++i){
        cin >> weight[i];
    }
    for(int i = 0; i < value.size(); ++i){
        cin >> value[i];
    }
    cout << solve(item_num, bag_size, weight, value);
    
}