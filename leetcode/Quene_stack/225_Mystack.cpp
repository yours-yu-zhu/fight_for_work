#include <iostream>
#include <string>
#include <algorithm>
#include <vector>   
#include <sstream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> que;
    queue<int> que_backup;
    MyStack() {

    }
    
    void push(int x) {
        que.push(x);
    }
    
    int pop() {
        for(int size = que.size(); size > 1; --size){
            que_backup.push(que.front());
            que.pop();
        }
        int result = que.front();
        que.pop();
        while(!que_backup.empty()){
            que.push(que_backup.front());
            que_backup.pop();
        }
        return result;
    }
    
    int top() {
        return que.back();
    }
    
    bool empty() {
        return que.empty();
    }
};


int main(){
    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    cout << obj->pop() << endl;
    cout << obj->top() << endl;
    cout << obj->empty() << endl;
    return 0;
}