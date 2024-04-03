#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    class myQuene{
    public:
        deque<int> que;
        void pop(int value){
            if(!que.empty() && value == que.front()){
                que.pop_front();
            }
        }
        void push(int value){
            while(!que.empty() && value > que.back()){
                que.pop_back();
            }
            que.push_back(value);
        }
        int front(){
            return que.front();
        }
    };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        myQuene my_que;
        vector<int> result;
        for(int i = 0; i < k; ++i){
            my_que.push(nums[i]);
        }
        result.push_back(my_que.front());
        for(int i = k; i < nums.size(); ++i){
            my_que.pop(nums[i - k]);
            my_que.push(nums[i]);
            result.push_back(my_que.front());
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> result = s.maxSlidingWindow(nums, k);
    for(int i = 0; i < result.size(); ++i){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}