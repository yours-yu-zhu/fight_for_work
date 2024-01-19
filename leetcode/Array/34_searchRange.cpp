#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //寻找左右边界
    vector<int> searchRange(vector<int>& nums, int target) {
       int leftbound = binarySearch(nums, target, true);
       int rightbound = binarySearch(nums, target, false); 
       return {leftbound, rightbound};

    }
    //找到一个target后，向左右两边扩展
    vector<int> searchRang_1(vector<int>& nums, int target) {
        int middle = binarySearch(nums, target, true);
        int leftbound = middle, rightbound = middle;
        if(middle == -1){
            return {-1, -1};
        }
        while(leftbound >= 0 && nums[leftbound] == target){
            leftbound--;
        }
        while(rightbound < nums.size() && nums[rightbound] == target){
            rightbound++;
        }
        return {leftbound + 1, rightbound - 1};
    }
private:
//二分法寻找左右边界，flag为true时寻找左边界，flag为false时寻找右边界
    int binarySearch(vector<int>& nums, int target, bool flag){
        int left = 0;
        int right = nums.size();
        int result = -1;
        while(left < right){
            int middle = left + (right - left) / 2;
            if(nums[middle] > target){
                right = middle;
            }else if(nums[middle] < target){
                left = middle + 1;
            }else if(nums[middle] == target){
                if (flag == true){
                    right = middle;
                    result = middle;
                }else if(flag == false){
                    left = middle + 1;
                    result = middle;
                }
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    vector<int> result = s.searchRange(nums, target);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}