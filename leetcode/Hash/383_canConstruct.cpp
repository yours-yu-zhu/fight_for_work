#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;    
class Solution {
public:
    //unoreder_map解法
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> hash;
        for(char c : magazine){
            ++hash[c];
        }
        for(char c : ransomNote){
            --hash[c];
            if(hash[c] < 0){
                return false;
            }
        }
        return true;
    }
    //数组哈希解法
    bool canConstruct(string ransomNote, string magazine) {
        int hash[26] = {0};
        for(auto c : magazine){
            ++hash[c - 'a'];
        }
        for(auto c : ransomNote){
            --hash[c - 'a'];
            if(hash[c - 'a'] < 0){
                return false;
            }
        }
        return true;
    }   
};


int main(){
    Solution sol;
    string ransomNote = "aa";
    string magazine = "aab";
    cout << sol.canConstruct(ransomNote, magazine) << endl;
}