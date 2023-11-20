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

//7.53作业：定义自己的Debug类
class Debug
{
private:
    /* data */
    bool hw;
    bool io;
    bool other;
public:
    constexpr Debug(bool b = true):hw(b), io(b), other (b){};
    constexpr Debug(bool h, bool i, bool o):
                    hw(h), io(i), other(o){};
    constexpr bool any(){
        return hw || io || other;
    };
    void set_io(bool b){io = b;};
    void set_hw(bool b){hw = b;};
    void set_other(bool b){other = b;};
};

//作业7.57 定义自己的Account类，定义static成员
class Account{
public:
    void calculate(){amount += amount * intersstRate;}
    static double rate(){return intersstRate;}
    static void rate(double newRate){intersstRate = newRate;}
private:
    string owner;
    double amount;
    static double intersstRate;
    static constexpr double todayrate = 42.42;
    static double initRate(){return todayrate;}

};

double Account::intersstRate = initRate();

class Example {
public:
	static  double rate;
	static const int vecSize = 20;
	static vector<double> vec;
};
double Example::rate ;
vector<double> Example::vec(vecSize);


int main(){
    X a(10,5);
    string s ;
    cout<<a.base<<endl;
    cout<<a.rem<<endl;
    Example::rate = 1;
    cout<< Example::rate <<endl;
    
}