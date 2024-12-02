#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> hash;
        for(int i = 0; i < s.size(); ++i){
            hash[s[i]] = i;
        }
        int slow = 0, fast = 0;
        vector<int> result;
        for(int i = 0; i < s.size(); ++i){
            fast = max(fast, hash[s[i]]);
            if(i == fast){
                result.push_back(fast - slow + 1);
                slow = i + 1;
                fast = i + 1;
            }
        }
        return result;
        
    }
};
int main(){
    string s = "ababcbacadefegdehijhklij";
    Solution sol;
    vector<int> result = sol.partitionLabels(s);
    for(auto i : result){
        cout << i << " ";
    }
    
    return 0;
}