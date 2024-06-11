#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void back_tracking(vector<int>& nums, int start_index){
        if(start_index >= nums.size()) return;

        for(int i = start_index; i < nums.size(); ++i){
            path.push_back(nums[i]);
            result.push_back(path);
            back_tracking(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        back_tracking(nums, 0);
        return result;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = s.subsets(nums);
    for(auto& vec : result){
        for(auto& num : vec){
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}