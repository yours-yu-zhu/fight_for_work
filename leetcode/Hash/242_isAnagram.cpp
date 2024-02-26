#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        int hash[26] = {0};
        for(int i = 0; i < s.size(); i++){
            ++hash[s[i] - 'a'];
        }
        for(int i = 0; i < t.size(); i++){
            --hash[t[i] - 'a'];
        }
        for(int i = 0; i < 26; i++){
            if(hash[i] != 0){
                return false;
            }
        }
        return true;
    }
    bool isAnagram1(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

int main(){
    Solution s;
    string s1 = "angram";
    string s2 = "nagaram";
    cout << s.isAnagram(s1, s2) << endl;
    return 0;
}