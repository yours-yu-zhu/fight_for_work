#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

//13.30 
class HasPtr {
public:
    friend void swap(HasPtr&, HasPtr&);
    friend bool operator<(const HasPtr&, const HasPtr&);
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i) { }
    HasPtr& operator=(HasPtr hp) {
        swap(*this,hp);
        return *this;
    }
    ~HasPtr() {
        delete ps;
    } 
    
    void show() { std::cout << *ps << std::endl; }
private:
    std::string *ps;
    int i;
};

inline
void swap(HasPtr& lhs, HasPtr& rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    std::cout << "call swap(HasPtr& lhs, HasPtr& rhs)" << std::endl;
}

bool operator<(const HasPtr& lhs, const HasPtr& rhs)
{
    return *lhs.ps < *rhs.ps;
}

void ex_13_30(){
    //test swap
    HasPtr hp1("hello");
    HasPtr hp2("world");
    swap(hp1, hp2);
    hp1.show();
    hp2.show();
}

void ex_13_31(){
    //test < operator,using sort
    HasPtr hp1("hello");
    HasPtr hp2("world");
    HasPtr hp3("cpp");
    HasPtr hp4("primer");
    HasPtr hp5("hello");
    vector<HasPtr> vec{hp1,hp2,hp3,hp4,hp5};
    sort(vec.begin(),vec.end());
    for(auto &i : vec){
        i.show();
    }

}


int main() {
    // ex_13_30();
    ex_13_31();

    
}
