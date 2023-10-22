#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <limits.h>
#define MAX 100000
using namespace std;
class Solution {
public:
//    int minSubArrayLen(int target, vector<int>& nums) {/////////暴力解法，两个for循环。
//        int begin ;
//        int minlength=0;
//        int length = 0;
//        int total = 0;
//        for (begin = 0; begin < nums.size(); begin++){ //起始位置
//            for(int j = begin; j < nums.size(); j++){ //终止位置
//                length++;
//                total += nums[j];
//                if(total >= target && minlength == 0){
//                    minlength = length;
//                    break;
//                }
//                else if(total >= target && length < minlength){
//                    minlength = length;
//                    break;
//                }
//            }
//
//            length = 0;
//            total = 0;
//
//        }
//        return minlength;
//    }
//};

    int minSubArrayLen(int target, vector<int>& nums) { //滑动窗口
        int begin = 0;
        int minlength = INT_MAX; //记住INT最大为宏INT_MAX
        int total = 0;
        for(int end = 0; end < nums.size(); end++){
            total+=nums[end];
            while(total >= target){
                minlength = min(minlength, end - begin + 1);
                total -= nums[begin];
                begin++;
            }
        }
        if(minlength == INT_MAX){
            return 0;
        }
        else{
            return minlength;
        }
        }
    };

//int main() {
//    vector<int> nums = {2,3,1,2,4,3};
//    int target = 7;
//    Solution a ;
//    cout << a.minSubArrayLen(target,nums);
////    for (auto i : nums)
////        std::cout << i << ' ';
//
//    return 0;
//}
