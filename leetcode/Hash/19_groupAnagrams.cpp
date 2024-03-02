#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    //自己想的方法
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        //每个字符串排序后作为key，原字符串作为value
        for(auto s : strs){
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            hash[tmp].push_back(s);
        }
        //再把hash表的value放到result中
        vector<vector<string>> result;
        for(const auto &pair : hash){
            result.push_back(pair.second);
        }
        return result;
    }
    //第二种方法，大体思路差不多，但是用了一个sub来记录要插入result的位置，就不用再遍历hash表了
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> hash;
        int sub = 0;
        vector<vector<string>> result;
        for(auto s : strs){
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            if(hash.find(tmp) == hash.end()){
                hash[tmp] = sub++;
                result.push_back({s});
            }else{
                result[hash[tmp]].push_back(s);
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    s.groupAnagrams(strs);
    return 0;
}