# 字符串

# kmp算法详解

这个链接完美解释了kmp算法。  

https://www.zhihu.com/question/21923021/answer/281346746    

## 理论

  

# 344.反转字符串

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        int slow = 0;
        int fast = s.size() -  1;
        while(slow < fast){
            char tmp = s[slow];
            s[slow] = s[fast];
            s[fast] = tmp;
            ++slow;
            --fast;
        }
    }
};
```

用双指针十分简单。。

# 541.反转字符串II

```cpp
class Solution {
public:
//全部手动实现的版本。
    void reverse(string &s, int begin, int end){
        while(begin < end){
            char tmp = s[begin];
            s[begin] = s[end];
            s[end] = tmp;
            ++begin;
            --end;
        }
    }
    string reverseStr(string s, int k) {
        for(int i = 0; i < s.size(); i += 2 * k){
            if(i + k < s.size()){
                reverse(s, i, i + k - 1);
            }else{
                reverse(s, i, s.size() - 1);
            }
        }
        return s;
    }
};
//标准库版本
class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i = 0; i < s.size(); i += 2 * k){
            if(i + k < s.size()){
                //标准库处理的是左闭右开区间！
                reverse(s.begin() + i, s.begin() + i + k);
            }else{
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};

```

这道题也是比较简单的，主要就是模拟题目的要求。同时，i每次增加2*k也保证了符合要求！！

# km54.**替换数字**

```cpp
#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    int count = 0;
    cin >> s;
    int oldsize = s.size();
    //获取数字的数量
    for(int i = 0; i < oldsize; ++i){
        if(s[i] >= '0' && s[i] <= '9'){
            ++count;
        }
    }
    s.resize(oldsize + 5 * count);
    for(int slow = oldsize - 1, fast = s.size() - 1;slow > 0 ; --slow, --fast){
        if(s[slow] >= 'a' && s[slow] <= 'z'){
            s[fast] = s[slow];
        }else{
            s[fast] = 'r';
            s[fast - 1] = 'e';
            s[fast - 2] = 'b';
            s[fast - 3] = 'm';
            s[fast - 4] = 'u';
            s[fast - 5] = 'n';
            fast -= 5;            
        }
    }
    cout << s << endl;
    
}
```

简单来说就是直接计算字符串要扩充的的大小，然后从后向前填进去就可以了。

**从后填避免了从开头开始的对剩余元素的移动问题，节约了时间复杂度！**                                    

# 151.反转字符串中的单词🌟🌟

     

```cpp
class Solution {
public:
//方案一，全部手动
    string reverseWords(string s) {
        //第一步，先反转整体字符串
        reverse(s.begin(), s.end());
        //第二步，去除多余的空格‘ ’
        int slow = 0, fast = 0;
        //他的移除单词其实是以单词为单位的。
        for(; fast < s.size(); ++fast){
            //fast排除不是空格
            if(s[fast] != ' '){
                if(slow != 0){
                    s[slow++] = ' ';
                    //首个单词不加空格
                }
                //对接下来的一个单词直接填充
                while(fast < s.size() && s[fast] != ' '){
                    s[slow++] = s[fast++];
                }
            }
        }
        s.resize(slow);
        int start = 0;
        //再针对每个单词单独反转
        for(int i = 0; i <= s.size(); ++i){
            if(i == s.size() || s[i] == ' '){
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }

        return s;
    }
    //方案二，使用stringstream流自动跳过空格。       
    string reverseWords1(string s) {
        istringstream is(s);
        vector<string> vec;
        string word;
        string result;
        while(is >> word){
            vec.push_back(word);
        }
        for(int i = vec.size() - 1; i >= 0; --i){
            result += vec[i];
            if(i > 0){
                result += " ";
            }       
        } 
        return result;   
    }    
};
```

综合考察字符串操作的好题。感觉这道题，十分有意思，两种方法都十分考验思维。

- 第一种全部手动，采用先反转整体字符串，然后去除多余空格，再分单个单词的反转，设计十分巧妙。时间复杂度为O(n)
- 第二种则是自己想的C++的stringstream流的特性，会自动跳过空格。也十分巧妙，只是空间复杂度为O(n)。

# km55.右旋转字符串

```
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int n = 0;
    string s;
    cin >> n;
    cin >> s;
    //整体反转字符串
    reverse(s.begin(), s.end());
    //局部反转0~n - 1
    reverse(s.begin(), s.begin() + n);
    //局部反转n~s.size() - 1
    reverse(s.begin() + n, s.end());
    cout << s << endl;
}
```

 思路还是十分简单的。

先就是更具题目要求把字符串分为两个子字符串。

随后先整体反转字符串，再分别反转对应的字串。

达到负负为正的效果。                                                           

# 28.找到字符串中第一个匹配项目（kmp）🌟🌟

```
class Solution {
public:
    void getNext(const string& needle, vector<int>& next){
		    //初始位置置为0   
        next[0] = 0;
        for(int i = 1; i < needle.size(); ++i){
		        //j每次只代表前一个的next数字     
            int j = next[i - 1];
            while(j > 0 && needle[i] != needle[j]){
                j = next[j - 1];
            }
            if(needle[i] == needle[j]){
                next[i] = j + 1;
            }else{
                next[i] = 0;
            }
        }
    }

    int strStr(string haystack, string needle){
        vector<int> next(needle.size(), 0);
        getNext(needle, next);
        int i = 0, j = 0;
        //i代表haystack的指针，j代表只想needle的指针         
        for(i = 0; i < haystack.size(); ++i){
            while(j > 0 && haystack[i] != needle[j]){
                j = next[j - 1];
            }
            if(haystack[i] == needle[j]){
                ++j;
            }
            if(j == needle.size()){
                return i - j + 1;
            }
        }
        return -1;
    }

};

```

典型的kmp算法。  

# 459.**重复的子字符串**

```cpp
    class Solution {
    public:
    //移动构造方法  
        bool repeatedSubstringPattern(string s) {
            string t = s + s;
            t.erase(t.begin());
            t.erase(t.end() - 1);
            if(t.find(s) != std::string::npos){
                return true;
            }
            return false;
        }
        //kmp的解法  
        void getNext(const string& s, vector<int>& next){
            next[0] = 0;
            for(int i = 1; i < s.size(); ++i){
                int j = next[i - 1];
                while(j > 0 && s[i] != s[j]){
                    j = next[j - 1];
                }
                if(s[i] == s[j]){
                    next[i] = j + 1;
                }else{
                    next[i] = 0;
                }
            }
        }
        bool repeatedSubstringPattern(string s) {
            vector<int> next(s.size(), 0);
            getNext(s, next);
            int len = s.size();
            if(next[len - 1] != 0 && len % (len - next[len - 1]) == 0){
                return true;
            }else{
                return false;
            }            
        }

    };
```

第一种移动构造方法十分巧妙：

如 果s是由它的一个子串 n 重复多次构成的字符串，那么s可以分为两部分：s = k*n + n 即s1 = k*n; s2 = n;

- S = s + s = s1 + s2 + s1 + s2
- 去掉第一个字符和最后一个字符 S’ = s3 + s2 + s1 + s4
- 如果s是由一个子串重复多次构成的字符串 ，则s2 + s1 = n + k*n = n + (k-1)*n + n = k*n + n = s1 + s2 --> s2 + s1 = s1 + s2 = s
- 故如果s是由一个子串重复多次构成的字符串，则S‘中包含s。

第二种kmp的解法，也是利用了kmp算法的next数组。

找到一个规律，即最长相等前后缀不包含的那一小撮串，就是重复的字串，没见过还真不知道怎么做这种题。