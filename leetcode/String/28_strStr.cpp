#include <iostream>
#include <string>
#include <algorithm>
#include <vector>   
#include <sstream>

using namespace std;
class Solution {
public:
    void getNext(const string& needle, vector<int>& next){
		    //初始位置置为0   
        next[0] = 0;
        for(int i = 1; i < needle.size(); ++i){
		        //j每次只代表前一个的next数字     
            int j = next[i - 1];
            while(j > 0 && needle[i] != needle[j]){
                j = next[j - 1];
            }
            if(needle[i] == needle[j]){
                next[i] = j + 1;
            }else{
                next[i] = 0;
            }
        }
    }

    int strStr(string haystack, string needle){
        vector<int> next(needle.size(), 0);
        getNext(needle, next);
        //输出next
        for(int i = 0; i < next.size(); ++i){
            cout << next[i] << " ";
        }
        cout << endl;
        int i = 0, j = 0;
        //i代表haystack的指针，j代表只想needle的指针         
        for(i = 0; i < haystack.size(); ++i){
            while(j > 0 && haystack[i] != needle[j]){
                j = next[j - 1];
            }
            if(haystack[i] == needle[j]){
                ++j;
            }
            if(j == needle.size()){
                return i - j + 1;
            }
        }
        return -1;
    }

};


int main(){
    Solution sol;
    string haystack = "abababab";
    string needle = "abcabc";
    cout << sol.strStr(haystack, needle) << endl;
    return 0;
}