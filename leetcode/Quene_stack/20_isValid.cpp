class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 != 0) return false;
        stack<char> stk;
        for(auto c = s.begin(); c != s.end(); ++c){
            if(*c == '(' || *c == '{' || *c == '['){
                stk.push(*c);
            }else{
                if(stk.empty()) return false;
                else if(stk.top() == '(' && *c == ')') stk.pop();
                else if(stk.top() == '[' && *c == ']') stk.pop();
                else if(stk.top() == '{' && *c == '}') stk.pop();
                else return false;
            }
        }
        return stk.empty();
    }
};