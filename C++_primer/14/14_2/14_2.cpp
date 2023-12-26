#include "14_2.h"


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

ostream& operator<<(ostream& os, const String& s){
    os << "operator<<: " << s.c_str();
    return os;
}

void ex_14_7(){
    String str("Hello World");
	cout << str << endl;
}

int main()
{
    ex_14_7();
}