#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void back_tracking(vector<int>& candidates, int rest, int start_index){
        if(rest == 0){
            result.push_back(path);
            return;
        }
        for(int i = start_index; i < candidates.size() && rest >= 0; ++i){
            if(i > start_index && candidates[i] == candidates[i - 1]) continue;
            path.push_back(candidates[i]);
            back_tracking(candidates, rest - candidates[i], i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        back_tracking(candidates, target, 0);
        return result;
    }
};

int main(){
    Solution s;
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> result = s.combinationSum2(candidates, target);
    for(auto& vec : result){
        for(auto& num : vec){
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}