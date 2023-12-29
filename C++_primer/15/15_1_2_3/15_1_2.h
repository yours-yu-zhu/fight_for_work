#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Quote{
public:
    Quote() = default;
    Quote(const string &book, double sales_price):
        bookNo(book), price(sales_price){}
    string isbn() const {return bookNo;}
    virtual double net_price(size_t n) {
        return n * price;
    }
    ~Quote() = default;
    //ex15.11
    virtual void debug(){
        cout << "Quote's data members:\n" 
            << "\tbookNo: " << bookNo << "\n\tprice: " << price << endl;
    }
private:
    string bookNo;
protected:
    double price = 0.0;

};

class Bulk_quote : public Quote{
public:
    Bulk_quote() = default;
    Bulk_quote(const string &book, double p, size_t n, double disc):
        Quote(book, p), min_qty(n), discount(disc){}
    double net_price(size_t n) override;
    ~Bulk_quote() = default;
    //ex15.11
    void debug() override{
        cout << "Bulk_quote's data members:\n" 
            << "\tbookNo: " << isbn() << "\n\tprice: " << price 
            << "\n\tmin_qty: " << min_qty << "\n\tdiscount: " << discount << endl;
    }
private:
    size_t min_qty = 0;
    double discount = 0.0;
};

class Limit_quote : public Quote{
public:
    Limit_quote() = default;
    Limit_quote(const string &book, double p, size_t n, double disc):
        Quote(book, p), max_qty(n), discount(disc){}
    double net_price(size_t n) override;
    ~Limit_quote() = default;
    //ex15.11 
    void debug() override{
        cout << "Limit_quote's data members:\n" 
            << "\tbookNo: " << isbn() << "\n\tprice: " << price 
            << "\n\tmax_qty: " << max_qty << "\n\tdiscount: " << discount << endl;
    }
private:
    size_t max_qty = 0;
    double discount = 0.0;
};

double print_total(ostream &os, const Quote &item, size_t n);