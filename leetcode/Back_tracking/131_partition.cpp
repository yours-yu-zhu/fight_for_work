#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> result;
    vector<string> path;
    bool is_huiwen(string::iterator a, string::iterator b){
        for(auto i = a, j = b; i < j; ++i, --j){
            if(*i != *j) return false;
        }
        return true;
    }
    void back_tacking(string s, int start_index){
        if(start_index >= s.size()){
            result.push_back(path);
            return;
        }

        for(int i = start_index; i < s.size(); ++i){
            if(is_huiwen(s.begin() + start_index, s.begin() + i)){
                string str(s.begin() + start_index, s.begin() + i + 1);
                path.push_back(str);
            }else{
                continue;
            }
            back_tacking(s, i + 1);
            path.pop_back();

        }
    }
    vector<vector<string>> partition(string s) {
        back_tacking(s, 0);
        return result;
    }
};

int main(){
    Solution s;
    vector<vector<string>> result = s.partition("aab");
    for(auto i : result){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}