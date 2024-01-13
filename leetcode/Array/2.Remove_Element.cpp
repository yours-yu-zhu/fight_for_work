#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int right = nums.size() - 1;
        int left = 0;
        while(left <= right){
            if(nums[right] == val ){//双指针，找到右边不为val的
                right--;
                continue;
            }
            if(nums[left] != val ){//找到左边为val的
                left++;
                continue;
            }
            if(nums[left] == val){//交换他们
                int a = nums[left];
                nums[left] = nums[right];
                nums[right] = a;
                left++;
            }
        }
        return left;
    }

};

//int main() {
//    vector<int> nums = {0,1,2,2,2,0,4,2};
//    int target = 2;
//    Solution a ;
//    cout<<a.removeElement(nums,target)<<endl;
//    for (auto i : nums)
//        std::cout << i << ' ';
//
//    return 0;
//}
