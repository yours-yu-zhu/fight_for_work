#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    const vector<string> letter_map{
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
    };
    vector<string> result;

public:
    void back_tracking(const string& digits, int index, string path){
        if(index == digits.size()) {
            result.push_back(path);
            return;
        }
        int cur_num = digits[index] - '0';
        for(int i = 0; i < letter_map[cur_num].size(); ++i){
            back_tracking(digits, index + 1, path + letter_map[cur_num][i]);
        }



    }
    vector<string> letterCombinations(string digits) {
        back_tracking(digits, 0, "");
        return result;
    }
};

int main(){
    Solution s;
    vector<string> result = s.letterCombinations("23");
    for(auto& str : result){
        cout << str << endl;
    }
    return 0;
}