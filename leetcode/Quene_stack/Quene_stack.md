# 栈和队列

# 232.用栈实现队列

```cpp
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
```

双栈来实现的队列

# 225.**用队列实现栈**

```cpp
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

```

双队列实现栈。

# 20.有效的括号

```cpp
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
```

简单的，直接A出来。

# 1047. **删除字符串中的所有相邻重复项**

```cpp
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

```

# **150. 逆波兰表达式求值+**

```cpp
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
```

还是十分简单的，大二的数据结构课印象深刻。

但是实现的时候，一个十分致命的小错误就是s == "+" || s == "-" || s == "*" || s == "/"，s是字符串，右边必须是双引号（string），否则单引号为char。

# **239. 滑动窗口最大值🌟🌟**

```cpp
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

```

设计并实现了一个被称为“单调队列”的东西，他的元素里面是单调递减的，也就是说，front一定是最大的。

底层使用了deque，可以高效地从两端进出。

- 对于pop，每次是弹出滑动窗口的最左边，因为push是不是最大的都已经弹出了，所以只有最大额需要弹出时才弹出了。
- 对于push，是从back侧压进去，要保证单调性，所以back侧小于窗口最右边的元素都被弹出。因为也不是最大的，所以弹出也不影响。

设计十分巧妙啊～～

# **347.前 K 个高频元素🌟**

```cpp
class Solution {
public:
    class mycomparison{
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs){
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //使用map统计出现的次数
        unordered_map<int, int> map;
        for(auto i : nums){
            ++map[i];
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pq;
        for(auto i : map){
            pq.push(i);
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<int> result;
        while(!pq.empty()){
            result.push_back(pq.top().first);
            pq.pop();
        }
        return result;
    }
};
```

这道题难点不在算法的实现，而是对于数据结构的构造。

要先想到使用map来统计次数，然后如何排序呢？

直接sort为快排，时间复杂度为O(nlogn).

所以要想到用小顶堆，但是小顶堆也有问题，就是如何构造，要想到使用priority_queue，并且要把priority_queue默认的大顶堆转换为小顶堆，又是一个难点！

这些用法要记住～～