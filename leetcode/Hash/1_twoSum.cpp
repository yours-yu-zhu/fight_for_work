#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for(int i = 0; i < nums.size(); ++i){
            auto iter = hash.find(target - nums[i]);
            if(iter != hash.end()){
                return {iter->second, i};
            }
            hash[nums[i]] = i;
        }
        return {};
    }
};
int main(){
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = sol.twoSum(nums, target);
    for(int i = 0; i < result.size(); ++i){
        cout << result[i] << " ";
    }
    return 0;
}