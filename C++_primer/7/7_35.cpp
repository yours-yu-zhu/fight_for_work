#include <vector>
#include <iostream>
#include <string>
using namespace std;

typedef int Type;
// Type initVal(); 
class Exercise {
    Type i;
    int j;
public:
    
    // Type setVal(Type);
    Exercise(int val):j(val), i(j){};
    // Type initVal(){
    //     string a = "sdadad";
    //     return a;
    // }; 
};

//7.40作业
struct X {
	X (int i, int j): base(i), rem(base % j) {}
	int rem, base;
};
// Type Exercise::setVal(Type parm) { 
//     val = parm + initVal();     
//     return val;
// }

//7.42作业
class Book 
{
public:
    Book(unsigned isbn, std::string const& name, std::string const& author, std::string const& pubdate)
        :isbn_(isbn), name_(name), author_(author), pubdate_(pubdate)
    { }

    Book(unsigned isbn):Book(isbn, "","",""){};
    explicit Book(std::istream &in) 
    { 
        in >> isbn_ >> name_ >> author_ >> pubdate_;
    }

private:
    unsigned isbn_;
    std::string name_;
    std::string author_;
    std::string pubdate_;
};

int main(){
    X a(10,5);
    string s ;
    cout<<a.base<<endl;
    cout<<a.rem<<endl;
    
}