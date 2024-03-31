#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(auto s : tokens){
            if(s == "+" || s == "-" || s == "*" || s == "/"){
                int num1 = stk.top();
                stk.pop();
                int num2 = stk.top();
                stk.pop();
                if(s == "+") stk.push(num2 + num1);
                if(s == "-") stk.push(num2 - num1);
                if(s == "*") stk.push(num2 * num1);
                if(s == "/") stk.push(num2 / num1);
            }else{
                stk.push(stoi(s));
            }
        }
        int result = stk.top();
        stk.pop();
        return result;
    }
};

int main(){
    Solution s;
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    cout << s.evalRPN(tokens) << endl;
    return 0;
}