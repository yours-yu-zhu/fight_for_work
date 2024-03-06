#include <iostream>
#include <vector>

using namespace std;

    class Solution {
    public:
        void reverseString(vector<char>& s) {
            int slow = 0;
            int fast = s.size() -  1;
            while(slow < fast){
                char tmp = s[slow];
                s[slow] = s[fast];
                s[fast] = tmp;
                ++slow;
                --fast;
            }
        }
    };

int main(){
    Solution sol;
    vector<char> s = {'h','e','l','l','o'};
    sol.reverseString(s);
    for(auto c : s){
        cout << c << " ";
    }
    cout << endl;
    return 0;
}