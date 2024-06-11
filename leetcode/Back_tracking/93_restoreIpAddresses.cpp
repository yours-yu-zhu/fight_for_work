#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> result;
    bool isvaild(string::iterator begin, string::iterator end){ //左闭右开
        string str(begin, end);
        if(str.size() == 0) return false;
        if(str[0] == '0' && str.size() != 1) return false;
        if(str.size() > 3) return false;
        if(std::stoi(str) > 255 || stoi(str) < 0) return false;
        for(auto c : str){
            if(c < '0' || c > '9') return false;
        }
        return true;
    }

    void back_tacking(string s, int start_index, int point_sum){
        //cout << s << " " << start_index << " " << point_sum << endl;
        if(point_sum == 3 && isvaild(s.begin() + start_index, s.end())){
            result.push_back(s);
            return;
        }
        for(int i = start_index; i < s.size(); ++i){
            if(isvaild(s.begin() + start_index, s.begin() + i + 1)){
                s.insert(s.begin() + i + 1, '.'); //插入的位置注意，i+1是因为插入了一个'.'
                ++point_sum;
                back_tacking(s, i + 2, point_sum);//i+2是因为插入了一个'.'
                s.erase(s.begin() + i + 1);
                --point_sum;
            }else break;

        }
    }
    vector<string> restoreIpAddresses(string s) {
        back_tacking(s, 0, 0);
        return result;
    }
};

int main(){
    Solution s;
    vector<string> result = s.restoreIpAddresses("25525511135");
    for(auto str : result){
        cout << str << endl;
    }
    return 0;
}