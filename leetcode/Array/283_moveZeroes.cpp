#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int fast = 0, slow = 0;
        int size = nums.size();
        for(; fast < size; ++fast){
            if(nums[fast] != 0){
                swap(nums[fast], nums[slow]);
                ++slow;
            }
        }
    }
};

int main(){
    vector<int> nums = {0,1,0,3,12};
    Solution sol;
    sol.moveZeroes(nums);
    for(int i = 0; i < nums.size(); ++i){
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}