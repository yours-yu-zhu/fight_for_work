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
private:
    size_t max_qty = 0;
    double discount = 0.0;
};

double print_total(ostream &os, const Quote &item, size_t n);