#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> result(temperatures.size(), 0);
        st.push(0);
        for(int i = 1; i < temperatures.size(); ++i){
            if(temperatures[i] <= temperatures[st.top()]) st.push(i);
            else{
                while(!st.empty() && (temperatures[i] > temperatures[st.top()])){
                    result[st.top()] = i - st.top();
                    st.pop();
                }
                st.push(i);
            }
            
        }
        return result;
    }
};

int main(){
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    Solution s;
    vector<int> result = s.dailyTemperatures(temperatures);
    for(int i = 0; i < result.size(); ++i){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}