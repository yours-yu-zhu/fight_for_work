#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        //双指针要排序
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i){//第一层循环
            //对第一个i进行剪枝
            if(nums[i] > target && target > 0) break;
            //去重i
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            //二层循环
            for(int j = i + 1; j < nums.size(); ++j){
                //第二次剪枝
                if(nums[i] + nums[j] > target && nums[i] + nums[j] >=0) break;
                 //去重j
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                //开始双指针
                int left = j + 1;
                int right = nums.size() - 1;
                while(left < right){
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum > target) --right;
                    else if(sum < target) ++left;
                    else{
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        //right去重
                        while(left < right && nums[right] == nums[right - 1]) --right;
                        //left去重
                        while(left < right && nums[left] == nums[left + 1]) ++left;
                        // push_back以后还有缩小双指针范围
                        --right;
                        ++left;
                    }
                }
            }
        }
        return result;
    }
};

int main(){ 
    vector<int> nums = {0,0,0,1000000000,1000000000,1000000000,1000000000};
    Solution s;
    vector<vector<int>> result = s.fourSum(nums, 1000000000);
    for(int i = 0; i < result.size(); ++i){
        for(int j = 0; j < result[i].size(); ++j){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}