#include <memory>
#include <algorithm>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
class String
{
    //ex14.16
    friend bool operator==(const String&, const String&);
    friend bool operator!=(const String&, const String&);
    //ex14.19 
    friend bool operator<(const String &s1, const String &s2);
    friend bool operator<=(const String &s1, const String &s2);
    friend bool operator>(const String &s1, const String &s2);
    friend bool operator>=(const String &s1, const String &s2);
public:
    String() : String("") { }
    String(const char *);
    String(const String&);
    String& operator=(const String&);
    ~String();
    String(String&&) noexcept; // 移动构造函数
    String &operator=(String&&) noexcept; // 移动赋值运算符

    const char *c_str() const { return elements; }  // 返回字符串首地址
    size_t size() const { return end - elements; } // 实际空间大小，包括一个结尾字符
    size_t length() const { return end - elements - 1; } // 字符串长度，不包括结尾字符

private:
    std::pair<char*, char*> alloc_n_copy(const char*, const char*); //拷贝到新地方
    void range_initializer(const char*, const char*); // 根据输入输出初始化
    void free();

private:
    char *elements;
    char *end;
    std::allocator<char> alloc;
};

ostream& operator<<(ostream& os, const String& s);
