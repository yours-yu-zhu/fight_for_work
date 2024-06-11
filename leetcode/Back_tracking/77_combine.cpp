#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path; 
    int const_k;
    void back_tracking(int n, int k, int start_index){
        if(k == 0){
            result.push_back(path);
            return;
        }

        for(int i = start_index; n - i + 1 >= (const_k - path.size()); ++i){
            path.push_back(i);
            back_tracking(n, k - 1, i + 1);
            path.pop_back();
        } 
    }
    vector<vector<int>> combinecombine(int n, int k) {
        const_k = k;
        back_tracking(n, k, 1);
        return result;
    }
};

int main(){
    Solution s;
    vector<vector<int>> result = s.combinecombine(4, 2);
    for(auto i : result){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0; 
}