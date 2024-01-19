#ifndef _COMPLEX_H_
#define _COMPLEX_H_
#include <iostream>
using namespace std;    
class complex{
public:
    complex(double r = 0, double i = 0): re(r), im(i){} //构造函数
    complex& operator+=(const complex&); //operator+=成员函数
    double real() const {return re;} //real()成员函数
    double imag() const {return im;} //imag()成员函数
private:
    double re, im; 

    friend complex& __doapl(complex*, const complex&); //友元函数

};

inline complex& __doapl(complex* ths, const complex& r){
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}

inline complex& complex::operator+=(const complex& r){
    return __doapl(this, r);
}

inline complex operator+(const complex& lhs, const complex& rhs){
    return complex(lhs.real() + rhs.real(), lhs.imag() + rhs.imag());
}

inline complex operator+(const complex& lhs, double rhs){
    return complex(lhs.real() + rhs, lhs.imag());
}

inline complex operator+(double lhs, const complex& rhs){
    return complex(lhs + rhs.real(), rhs.imag());
}

ostream& operator<<(ostream& os, const complex& x){
    return os << '(' << x.real() << ',' << x.imag() << ')';
}


#endif