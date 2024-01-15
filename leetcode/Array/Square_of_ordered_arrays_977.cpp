#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
//暴力解法，先平方，再直接调用快速排序
    vector<int> sortedSquares_1(vector<int>& nums) {
        for(auto i = nums.begin(); i != nums.end(); ++i){
            *i *= *i;
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
//双指针法，从两端开始遍历，比较两端的平方值，将较大的值放入结果数组的末尾
    vector<int> sortedSquares_2(vector<int>& nums) {
        size_t k = nums.size() - 1;
        vector<int> result(nums.size(), 0);
        for(size_t i = 0, j = k; i <= j;){
            if(nums[i] * nums[i] < nums[j] * nums[j]){
                result[k--] = nums[j] * nums[j];
                --j;
            }else{
                result[k--] = nums[i] * nums[i];
                ++i;
            }
        }
        return result;
    }
};

int main(){
    vector<int> nums = {-4,-1,0,3,10};
    Solution s;
    vector<int> result = s.sortedSquares_2(nums);
    for(auto i = result.begin(); i != result.end(); ++i){
        cout << *i << " ";
    }
    cout << endl;
    return 0;
}