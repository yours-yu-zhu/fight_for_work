#include <iostream>
#include <string>
#include <algorithm>
#include <vector>   
#include <sstream>
#include <stack>

using namespace std;

class MyQueue {
public:
    stack<int> stin;
    stack<int> stout;
    MyQueue() {

    }
    
    void push(int x) {
        stin.push(x);
    }
    
    int pop() {
        if(stout.empty()){
            while(!stin.empty()){
                stout.push(stin.top());
                stin.pop();
            }
        }
        int result = stout.top();
        stout.pop();
        return result;
    }
    
    int peek() {
        int res = this->pop();
        stout.push(res);
        return res;
    }
    
    bool empty() {
        return stin.empty() && stout.empty();
    }
};


int main(){
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    cout << obj->pop() << endl;
    cout << obj->peek() << endl;
    cout << obj->empty() << endl;
    return 0;
}