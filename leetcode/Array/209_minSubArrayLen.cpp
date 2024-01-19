#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    //暴力解法，时间复杂度O(n^2)
    int minSubArrayLen_1(int target, vector<int>& nums) {
        int sum = 0;
        int length = 0, min = INT32_MAX;
        for(int i = 0; i < nums.size(); ++i){
            sum = 0;
            length = 0;
            for(int j = i; j < nums.size(); ++j){
                sum += nums[j];
                length++;
                if(sum >= target){
                     min = min > length ? length : min;
                     break;
                }
            }
        }
        return min == INT32_MAX ? 0 : min;
    }
    //滑动窗口法，时间复杂度O(n)
    int minSubArrayLen_2(int target, vector<int>& nums) {
        int sum = 0; //滑动创建窗口数组之和
        int length = 0; //滑动创建窗口数组长度
        int min = INT32_MAX; //最小长度
        int i = 0;//滑动窗口起始位置
        for (int j = 0; j < nums.size(); ++j){
            sum += nums[j];
            while(sum >= target){
                length = j - i + 1;
                min = min > length ? length : min;
                sum -= nums[i++];
            }
        }
        return min == INT32_MAX ? 0 : min;

    }
};

int main(){
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    Solution s;
    cout << s.minSubArrayLen_2(target, nums) << endl;
    return 0;
}