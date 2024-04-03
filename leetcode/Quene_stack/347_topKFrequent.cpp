#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
 using namespace std;

class Solution {
public:
    class mycomparison{
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs){
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //使用map统计出现的次数
        unordered_map<int, int> map;
        for(auto i : nums){
            ++map[i];
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pq;
        for(auto i : map){
            pq.push(i);
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<int> result;
        while(!pq.empty()){
            result.push_back(pq.top().first);
            pq.pop();
        }
        return result;
    }
};

int main(){
    vector<int> nums{1,1,1,2,2,3};
    Solution s;
    vector<int> result = s.topKFrequent(nums, 2);
    for(auto i : result){
        cout << i << " ";
    }
    return 0;
}