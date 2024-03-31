//用单独一个栈来不断进出，如果栈顶元素和当前元素相同，就弹出栈顶元素，否则就入栈
class Solution {
public:
    string removeDuplicatesremoveDuplicates(string s) {
        string result;
        for(auto c : s){
            if(result.empty() || result.back() != c){
                result.push_back(c);
            }else{
                result.pop_back();
            }
        }
        return result;

    }
};

//递归方法，相当于不断删除。。
class Solution {
public:
    stack<char> stk;
    string remove_s(string &s){

        for(auto c = s.begin(); c != s.end(); ++c){
            if(stk.empty()){
                stk.push(*c);
            }else{
                if(stk.top() == *c){
                    s.erase(c - 1, c + 1);
                    stk.pop();
                    return remove_s(s);
                }else{
                    stk.pop();
                    stk.push(*c);
                }
            }
        }
        return s;
    }

    string removeDuplicates(string s) {
        return remove_s(s);

    }
};

