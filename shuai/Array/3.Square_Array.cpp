#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//方法一：暴力求平方随后排序
//class Solution {
//public:
//    vector<int> sortedSquares(vector<int>& nums) {
//        for(int i = 0; i<nums.size(); i++){
//            nums[i] = nums[i]*nums[i];
//        }
//        sort(nums.begin(), nums.end());
//        return nums;
//    }
//};
//方法二：双指针法，考虑到一个特性即，这个已经排序的数组左右两边的值一定是绝对值相对大的，中间绝对值小，所以不断两边往中间去靠就可以。
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0,right = nums.size() - 1;   //定义左右指针
        vector<int> result(nums.size(),0);  //定义新的数组
        for(int i = nums.size() - 1; i >= 0; i--){  //只需要把新数组填满，所以循环O(n)次
            if(nums[left] * nums[left] >= nums[right] * nums[right]){
                result[i] = nums[left] * nums[left];
                left++;
            }
            else if(nums[left] * nums[left] < nums[right] * nums[right]){
                result[i] = nums[right] * nums[right];
                right--;
            }
        }
        return result;

    }
};

//int main() {
//    vector<int> nums = {-4,-1,0,3,10};
//    int target = 2;
//    Solution a ;
//    nums = a.sortedSquares(nums);
//    for (auto i : nums)
//        std::cout << i << ' ';
//
//    return 0;
//}
