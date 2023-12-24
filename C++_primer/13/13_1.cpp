#include <iostream>
#include <string>
#include <vector>

using namespace std;

//13.5
class HasPtr {
public:
	HasPtr(const string& s = string()):ps(new string(s)), i(0) { }
    HasPtr(const HasPtr& hp): ps(new string(*(hp.ps))), i(hp.i){ cout << "copy constructor" << endl; }
    string get_ps() const { return *ps; }
    HasPtr& operator=(const HasPtr& hp){
        cout << "copy assignment" << endl;
        if(this != &hp){
            delete ps;
            ps = new string(*(hp.ps));
            i = hp.i;              
        }
        return *this;
    }
    ~HasPtr(){
        cout << "destructor" << endl;
        delete ps;
    }
private:
	string *ps;
	int i;
};

void ex_13_5() {
    HasPtr hp("hello");
    HasPtr hp2 = hp;
    cout << hp2.get_ps() << endl;
}

void ex_13_8() {
    HasPtr hp("hello");
    HasPtr hp2("world");
    hp2 = hp;
    cout << hp2.get_ps() << endl;
}

//13.13
struct X {
    X() { std::cout << "X()" << std::endl; }
    X(const X&) { std::cout << "X(const X&)" << std::endl; }
    X& operator=(const X&) { std::cout << "X& operator=(const X&)" << std::endl; return *this; }
    ~X() { std::cout << "~X()" << std::endl; }
};

void f(const X &rx, X x)
{
    std::vector<X> vec;
    vec.reserve(2);
    vec.push_back(rx);
    vec.push_back(x);
}
/*输出为：
X()-------X *px = new X; 触发
X(const X&)-------f(const X &rx, X x)的X x触发
X(const X&)-------vec.push_back(rx);触发
X(const X&)-------vec.push_back(x);触发
~X()
~X()
~X()
~X()
*/
void ex_13_13()
{
    X *px = new X; 
    f(*px, *px); 
    delete px;
}

class Employee{
public:
    Employee():id(s_increment++){}
    Employee(const string& s):name(s), id(s_increment++){}
    Employee(const Employee& ) = delete;
    Employee& operator=(const Employee& ) = delete;
    int get_id() const { return id; }
    string get_name() const { return name; }
private:
    string name;
    int id;
    static int s_increment;
};

int Employee::s_increment = 0;

void ex_13_18(){
    Employee e1;
    Employee e2 = e1;
    cout << e1.get_id() << endl;
    cout << e2.get_id() << endl;
    cout << e2.get_name() << endl;
}

int main() {
    
    //  ex_13_5();
    //  ex_13_8();
    // ex_13_13();
    ex_13_18();
}
