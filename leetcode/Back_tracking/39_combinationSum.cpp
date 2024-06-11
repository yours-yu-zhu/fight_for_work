#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void back_tracking(vector<int>& candidates, int target, int sum, int strat_index){
        if(sum == target){
            result.push_back(path);
            return;
        }
        for(int i = strat_index; i < candidates.size() && sum + candidates[i] <= target; ++i){
            path.push_back(candidates[i]);
            back_tracking(candidates, target, sum + candidates[i], i);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        back_tracking(candidates, target, 0, 0);
        return result;
    }
};

int main(){
    Solution s;
    vector<int> candidates = {2, 3, 6, 7};
    vector<vector<int>> result = s.combinationSum(candidates, 7);
    for(auto& vec : result){
        for(auto& num : vec){
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}