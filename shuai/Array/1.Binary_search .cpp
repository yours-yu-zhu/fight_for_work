#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size() - 1;
        int middle;
        do{
            middle = (end + begin) / 2; //求中间
            if(nums[middle] == target){
                return middle;
            }
            else if(nums[middle] > target){
                end = middle - 1; //左闭合右闭区间，即每次取都要抛弃middle这个值
            }
            else{
                begin = middle + 1;
            }
        }while(begin <= end); //判断条件，即beggin和end之间有空，就不能停
        return -1;

    }
};

//int main() {
//    vector<int> nums = {-1,0,3,5,9,12};
//    int target = 2;
//    Solution a ;
//    cout<<a.search(nums,target);
//    return 0;
//}
