#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        if(prices.size() == 1) return result;
        int buy_time;
        bool holds = false;
        int pre_diff = 0;
        int cur_diff = 0;
        for(int i = 0; i < prices.size() - 1; ++i){
            cur_diff = prices[i + 1] - prices[i];
            if(holds == false){
                if(pre_diff <= 0 && cur_diff > 0) {
                    buy_time = i;
                    holds = true;
                }
            }else{
                if(i == prices.size() - 2 && cur_diff >= 0){
                    result += prices[i + 1] - prices[buy_time];
                    holds = false;
                }
                if(pre_diff >=0 && cur_diff <= 0){
                    result += prices[i] - prices[buy_time];
                    holds = false;                
                }
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> prices = {7,6,4,3,1};
    cout << s.maxProfit(prices) << endl;
    return 0;
}