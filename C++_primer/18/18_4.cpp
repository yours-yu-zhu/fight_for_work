#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

struct Base1 {
	void print(int) const;
protected:
	int ival;
	double dval;
	char cval;
private:
	int *id;
};
struct Base2 {
	void print(double) const;
    void dulicishi(){
        cout << "Base2::dulicishi()" << endl;
    }
protected:
	double fval;
    double ceshi = 1.0;
private:
	double dval;
    
};
struct Derived : public Base1 {
public:
	void print(std::string) const;
protected:
	std::string sval;
	double dval;
};
struct MI : public Derived, public Base2 {
	void print(std::vector<double>);
    void print(int a){
        Base1::print(a);
    }
    void pceshi(){
        cout << ceshi << endl;
    }
protected:
	int *ival;
	std::vector<double> dvec;
};

int main()
{
    MI mi;
    mi.dulicishi();
    mi.pceshi();
    // mi.print(42); //ambiguous
    // mi.Base1::print(42); //ok
    // mi.Base2::print(42); //ok
    // mi.Derived::print(42); //ok
    return 0;
}
