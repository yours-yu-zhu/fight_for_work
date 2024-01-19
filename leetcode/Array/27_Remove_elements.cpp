#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
using namespace std;

class Solution {
public:
    //库函数法，不能直接用
    int removeElement_ku(vector<int>& nums, int val) {
        for(auto i = nums.begin(); i != nums.end(); i++){
            if(*i == val){
                nums.erase(i);
                i--;
            }
        }
        int size = nums.size();
        return size;
    }
    //暴力的解法，找到以后把后面所有的往前面移动
    int removeElement_baoli(vector<int>& nums, int val) {
        int size = nums.size();
        for(int i = 0; i < size; ++i){
            if(nums[i] == val){
                for(int j = i ; j < size; ++j){
                    nums[j] = nums[j + 1];
                }
                --i;    
                --size;
            }
        }
        return size;
    }
    //双指针法,迭代器版本，快慢指针的方法，很巧妙
    int removeElement(vector<int>& nums, int val) {
        auto fast = nums.begin();
        auto slow = nums.begin();
        for(;fast != nums.end(); ++fast){
            if(*fast != val){
                *slow = *fast;
                ++slow;
            }
        }
        return slow - nums.begin();
    }

};





int main(){
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    Solution s;
    int size = s.removeElement(nums, val);
    cout << size << endl;
    for(int i = 0; i < size; ++i){
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}