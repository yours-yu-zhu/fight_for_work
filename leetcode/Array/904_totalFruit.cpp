#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0, right = 0;
        int size = fruits.size();
        //用unordered_map来存储水果的种类和数量
        unordered_map<int, int> basket;
        int result = 0;
        for(; right < size; ++right){
            ++basket[fruits[right]];
            while(basket.size() > 2){
                auto it = basket.find(fruits[left]);
                --it->second;
                if(it->second == 0){
                    basket.erase(it);
                }
                ++left;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};
int main(){
    Solution sol;
    vector<int> fruits = {0,1,2,2};
    cout << sol.totalFruit(fruits) << endl;
    return 0;
    
}