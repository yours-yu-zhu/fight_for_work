#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;    
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hash(nums1.begin(), nums1.end());
        unordered_set<int> result;
        for(int i : nums2){
            if(hash.find(i) != hash.end()){
                result.insert(i);
            }
        }
        return vector<int> (result.begin(), result.end());
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    vector<int> result = s.intersection(nums1, nums2);
    for(int i : result){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}