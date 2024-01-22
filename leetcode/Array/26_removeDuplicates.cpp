#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
using namespace std;

class Solution {
public:
//迭代器版本
    int removeDuplicates_1(vector<int>& nums) {
        if(nums.size() == 1){
            return 1;
        }
        auto fast = nums.begin() + 1;
        auto slow = fast;
        int curobj = *(nums.begin());
        for(;fast != nums.end(); ++fast){
            if(*fast != curobj){
                *slow = *fast;
                curobj = *fast;
                ++slow;
            }
        }
        return slow - nums.begin();
    }
    int removeDuplicates_2(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int fast = 1, slow = 1;
        while(fast < n){
            if(nums[fast] != nums[fast - 1]){
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};

int main(){
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    Solution s;
    int size = s.removeDuplicates(nums);
    cout << size << endl;
    for(int i = 0; i < size; ++i){
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}