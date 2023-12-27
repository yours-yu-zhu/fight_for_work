#include "14_1.h"

Sales_data::Sales_data(istream &is):Sales_data(){
    is >> *this;
    cout << "Sales_data(istream &is)" << endl; 

}

Sales_data& Sales_data::operator+=(const Sales_data& a){
    units_sold += a.units_sold;
    revenue += a.revenue;
    return *this;
}

istream& operator>>(istream &is, Sales_data &item){
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    if(is)
        item.revenue = price * item.units_sold;
    else
        item = Sales_data();
    return is;
}

ostream& operator<<(ostream &os, const Sales_data &item){
    os << item.isbn() << " " << item.units_sold << " " 
        << item.revenue << " " << item.avg_price();  
    return os;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs){
    Sales_data sum = lhs;
    sum += rhs;
    return sum; 
}

Sales_data& Sales_data::operator=(const string &s){
    bookNo = s;
    return *this;
}

void ex_14_20(){
    Sales_data b1("978-7-121-15535-2", 1, 97.9);
    Sales_data b2("978-7-121-15535-2", 1, 99.9);

    std::cout << b1 + b2 << std::endl;
    b1 += b2;
    std::cout << b1 << std::endl;
    std::cout << b1 + b2 << std::endl;
}

void ex_14_22(){
    std::string s = "C++ Primer 5th";
    Sales_data b1("c++ primer", 10, 97.9);

    b1 = s;             // b1.operator=(s);
    std::cout << b1 << std::endl;
}

void ex_14_45(){
    Sales_data b1("c++ primer", 10, 97.09);
    string s = static_cast<string>(b1);
    double d = static_cast<double>(b1);
    cout << s << std::endl;
    cout << d << std::endl;
}
int main() {
    // ex_14_20();
    // ex_14_22();
    ex_14_45();
}
