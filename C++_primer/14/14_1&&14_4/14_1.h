#include <iostream>
#include <string>

using namespace std;

class Sales_data{
    friend istream& operator>>(istream&, Sales_data&);
    friend ostream& operator<<(ostream&, const Sales_data&);
    friend Sales_data operator+(const Sales_data&, const Sales_data&);

public:
    Sales_data() = default;
    Sales_data(const string &s, unsigned n, double p):bookNo(s), units_sold(n), revenue(p*n){
        cout << "Sales_data(const string &s, unsigned n, double p)" << endl;
    } 
    Sales_data(const string &s):bookNo(s){
        cout << "Sales_data(const string &s)" << endl;
    }
    Sales_data(istream &is);
    Sales_data& operator+=(const Sales_data&);
    string isbn() const {return bookNo;}
    //12.22 
    Sales_data& operator=(const string&);
private:
    string bookNo;
    unsigned units_sold = 0; //数量
    double revenue = 0.0; //销售额

    inline double avg_price() const;

};

istream& operator>>(istream&, Sales_data&);
ostream& operator<<(ostream&, const Sales_data&);
Sales_data operator+(const Sales_data&, const Sales_data&);

inline double Sales_data::avg_price() const{
    return units_sold ? revenue/units_sold : 0;
}