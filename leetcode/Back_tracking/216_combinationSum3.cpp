#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void back_tracking(int rest_sum, int rest_layer,int start_index){
        if(rest_layer == 0 && rest_sum == 0){
            result.push_back(path);
            return;
        }  
        if(rest_sum < 0) return;

        for(int i = start_index; i <= 9 - rest_layer + 1; ++i){
            path.push_back(i);
            back_tracking(rest_sum - i, rest_layer - 1, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        back_tracking(n, k, 1);
        return result;
    }
};

int main(){
    Solution s;
    vector<vector<int>> result = s.combinationSum3(3,9);
    for(auto vec : result){
        for(auto num : vec){
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}