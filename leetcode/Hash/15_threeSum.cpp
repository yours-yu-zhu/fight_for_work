#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        //先排序
        sort(nums.begin(), nums.end());
        //再遍历
        for(int i = 0; i < nums.size(); ++i){
            //必须开头为负数才能相加为0
            if(nums[i] > 0){
                return result;
            }
            //去重
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right){
                int sum = nums[left] + nums[right] + nums[i];
                if(sum > 0) --right;
                else if(sum < 0) ++left;
                else{
                    result.push_back({nums[i], nums[left], nums[right]});
                    // 去重逻辑应该放在找到一个三元组之后，对b 和 c去重
                    while(left < right && nums[right] == nums[right - 1]) --right;
                    while(left < right && nums[left] == nums[left + 1]) ++right;
                    // 找到答案时，双指针同时收缩
                    --right;
                    ++left;
                }
            }
        }
        return result;
    }
};

int main(){

}