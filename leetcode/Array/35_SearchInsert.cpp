#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //左闭右开二分法
        int left = 0;
        int right = nums.size();
        while(left < right){
            int middle = left + (right - left) / 2;
            if(nums[middle] > target){
                right = middle;
            }else if(nums[middle] < target){
                left = middle + 1;
            }else if(nums[middle] == target){
                return middle;
            }
        }
        return left;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,3,5,6};
    int target = 5;
    cout << s.searchInsert(nums, target) << endl;
    return 0;
}