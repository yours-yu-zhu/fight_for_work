#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;    
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int, int> hash;
        for(const auto &i : nums1){
            hash[i]++;
        }
        for(const auto& j : nums2){
            if(hash[j] > 0){
                result.push_back(j);
                hash[j]--;
            }
        }
        return result;
    }
};
int main(){
    Solution s;
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    vector<int> result = s.intersect(nums1, nums2);
    for(const auto &i : result){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}