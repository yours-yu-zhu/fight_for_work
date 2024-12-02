#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //求target
        int sum = 0;
        for(auto num : nums) sum += num;
        //排除显而易见的情况
        if(abs(target) > sum || (target + sum) % 2 == 1) return 0;
        int bag_size = (target + sum) /2;
        vector<int> dp(bag_size + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < nums.size(); ++i){
            for(int j = bag_size; j >= nums[i]; --j){
                dp[j] += dp[j - nums[i]];
            }
            //打印dp
            for(auto num : dp) cout << num << " ";
            cout << endl;
        }
        return dp[bag_size];
    }
};

int main(){
    Solution s;
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    cout << s.findTargetSumWays(nums, target) << endl;
    return 0;
}