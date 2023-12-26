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

std::pair<char*, char*> String::alloc_n_copy(const char* a, const char* b){
    auto newstr = alloc.allocate(b - a);
    return make_pair(newstr, uninitialized_copy(a, b, newstr));
} 

void String::range_initializer(const char* first, const char* last){
    auto newstr = alloc_n_copy(first, last);
    elements = newstr.first;
    end = newstr.second;
}

String::String(const char *s){
    char *sl = const_cast<char*>(s);
    while(*sl)
        ++sl;
    range_initializer(s, ++sl);
}

String::String(const String& rhs){
    range_initializer(rhs.elements, rhs.end);
    std::cout << "copy constructor" << std::endl;
}

String::String(String&& s) noexcept: elements(s.elements), end(s.end){
    s.elements = s.end = nullptr;
    std::cout << "move constructor" << std::endl;
}

String& String::operator=(String&& rhs) noexcept{
    if(this != &rhs){
        free();
        elements = rhs.elements;
        end = rhs.end;
        rhs.elements = rhs.end = nullptr;
        cout << "move assignment" << endl;
    }
    return *this;
}


void String::free(){
    if(elements){
        for(auto p = end; p != elements;){
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, end - elements);
    }
}

String::~String(){
    free();
}

String& String::operator=(const String& rhs){
    auto newstr = alloc_n_copy(rhs.elements, rhs.end);
    free();
    elements = newstr.first;
    end = newstr.second;
    std::cout << "copy-assignment" << std::endl;
    return *this;
}

void foo(String x)
{
    std::cout << x.c_str() << std::endl;
}

void bar(const String& x)
{
    std::cout << x.c_str() << std::endl;
}

String baz()
{
    String ret("world");
    return ret;
}

void ex13_44(){
    char text[] = "world";

    String s0; // 调用默认构造函数,在调用String("")构造函数，没有打印东西
    String s1("hello");//调用String(const char *)构造函数 ，没有打印
    String s2(s0); //调用拷贝构造函数，打印copy constructor第一次
    String s3 = s1; //调用拷贝构造函数，打印copy constructor第二次
    String s4(text);
    s2 = s1;

    foo(s1);
    bar(s1);
    foo("temporary");
    bar("temporary");
    String s5 = baz(); //调用移动构造函数，打印move constructor

    cout << "______"    << endl;
    std::vector<String> svec;
    svec.reserve(8);
    svec.push_back(s0); //''
    svec.push_back(s1); //hello
    svec.push_back(s2); //hello
    svec.push_back(s3); //hello
    svec.push_back(s4); //world
    svec.push_back(s5); //world
    svec.push_back(baz()); //world
    svec.push_back("good job");

    for (const auto &s : svec) {
        std::cout << s.c_str() << std::endl;
    }
}

int main()
{

}