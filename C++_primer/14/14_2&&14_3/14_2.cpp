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

bool operator==(const String& lhs, const String& rhs){
    cout << "operator==" << endl;
    if(lhs.size() != rhs.size()){
        return false;
    }
    for(auto p = lhs.elements, q = rhs.elements;
        p != lhs.end && q != rhs.end;
        ++p, ++q){
            if(*p != *q){
                return false;
            }
        }
    return true;
}

bool operator!=(const String& lhs, const String& rhs){
    cout << "operator!=" << endl;
    return !(lhs == rhs);
}

bool operator<(const String &s1, const String &s2){
    cout << "operator<" << endl;
    return lexicographical_compare(s1.elements, s1.end,
            s2.elements, s2.end);
}

bool operator>(const String &s1, const String &s2){
    cout << "operator>" << endl;
    return s2 < s1;
}

bool operator<=(const String &s1, const String &s2){
    cout << "operator<=" << endl;
    return !(s2 < s1);
}

bool operator>=(const String &s1, const String &s2){
    cout << "operator>=" << endl;
    return !(s1 < s2);
}

void ex_14_7(){
    String str("Hello World");
	cout << str << endl;
}

void ex_14_16(){
    String str1("Hello World");
    String str2("Hello World");
    cout << (str1 == str2) << endl;
    cout << (str1 != str2) << endl;
}

void ex_14_19(){
    String s1("One"), s2("Oneone");
    String s3(s2);
    if (s1 < s2)
        cout << "s1 < s2" << endl;
    else
        cout << "s1 >= s2 " << endl;
    if (s3 >= s2)
        cout << "s3 >= s2" << endl;
    else
        cout << "s3 < s2 " << endl;
}

int main()
{
    // ex_14_7();
    // ex_14_16();
    ex_14_19();
}