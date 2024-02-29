#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;    
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> hash;
        for(auto i : nums1){
            for(auto j : nums2){
                ++hash[i + j];
            }
        }
        int count = 0;
        for(auto i : nums3){
            for(auto j : nums4){
                if(hash.find(-(i + j)) != hash.end()){
                    count += hash[-(i + j)];
                }
            }
        }
        return count;
    }
};

int main(){
    Solution sol;
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {-2, -1};
    vector<int> nums3 = {-1, 2};
    vector<int> nums4 = {0, 2};
    cout << sol.fourSumCount(nums1, nums2, nums3, nums4) << endl;
    return 0;
}