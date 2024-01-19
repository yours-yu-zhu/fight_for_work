#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
using namespace std;

class Solution {
public:
    //区间为左闭右闭区间，不能用size_t，因为size_t是无符号数，当right = 0时，right - 1会溢出
    int search_1(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1; //起始区间为[0, nums.size() - 1]
        while(left <= right){
            int middle = left + ((right - left) / 2);
            if(nums[middle] > target){
                right = middle - 1; //target在左区间
            }else if(nums[middle] < target){
                left = middle + 1;  //target在右区间
            }else if(nums[middle] == target){
                return middle;
            }
        }
        return -1;
    }
    //区间为左闭右开区间，
    int search_2(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size(); //起始区间为[0, nums.size()]
        while(left < right){
            int middle = left + ((right - left) / 2);
            if(nums[middle] > target){
                right = middle ; //target在左区间
            }else if(nums[middle] < target){
                left = middle + 1;  //target在右区间
            }else if(nums[middle] == target){
                return middle;
            }
        }
        return -1;
    }
};

int main(){
    vector<int> nums = {-1,0,3,5,9,12};
    Solution s;
    cout << s.search_1(nums, 9) << endl;
    cout << s.search_2(nums, 9) << endl;
    return 0;
}