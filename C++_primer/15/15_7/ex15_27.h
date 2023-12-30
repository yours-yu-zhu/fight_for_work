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

class Disc_quote : public Quote{
public:
    Disc_quote() = default;
    Disc_quote(const string &book, double p, size_t qty, double disc):
       Quote(book, p), quantity(qty), discount(disc){}
    double net_price(size_t n ) = 0;
    ~Disc_quote() = default;
protected:
    size_t quantity = 0;
    double discount = 0.0;

};

class Bulk_quote : public Disc_quote{
public:
    using Disc_quote::Disc_quote;
    double net_price(size_t n) override;
};

