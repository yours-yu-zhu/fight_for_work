#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;    
class Solution {
public:
    bool isequal(const vector<int> &a, const vector<int> &b){
        if(a.size() != b.size())
            return false;
        for(int i = 0; i < a.size(); ++i){
            if(a[i] != b[i])
                return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> s_count(26,0);
        vector<int> p_count(26,0);
        vector<int> result({});
        if(s.size() < p.size()) return result;
        //构建哈希表p_count和滑动窗口
        for(int i = 0; i < p.size(); ++i){
            ++p_count[p[i] - 'a'];
            ++s_count[s[i] - 'a'];
        }
        //开始滑动窗口
        for(int slow = 0, fast = p.size() - 1; fast < s.size();){
            if(isequal(s_count, p_count)){
                result.push_back(slow);
            }
            s_count[s[slow++] - 'a']--;
            s_count[s[++fast] - 'a']++;
        }
        return result;

    }
};

int main(){
    Solution sol;
    string s = "abab";
    string p = "ab";
    vector<int> result = sol.findAnagrams(s,p);
    for(auto i : result){
        cout << i << " ";
    }
    cout << endl;
}