#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Quote{
    friend bool operator!=(const Quote &lhs, const Quote &rhs){
        return lhs.bookNo != rhs.bookNo && lhs.price != rhs.price;
    }
public:
    Quote() {
        cout << "Quote()" << endl;
    }
    Quote(const string &book, double sales_price):
        bookNo(book), price(sales_price){
            cout << "Quote(const string &book, double sales_price)" << endl;
        }
    string isbn() const {return bookNo;}
    virtual double net_price(size_t n) {
        return n * price;
    }
    virtual ~Quote() {
        cout << "~Quote()" << endl;
    };
    //拷贝构造函数
    Quote(const Quote &q): bookNo(q.bookNo), price(q.price){
        cout << "Quote(const Quote &q)" << endl;
    }
    //拷贝赋值运算符
    Quote& operator=(const Quote &q){
        cout << "Quote& operator=(const Quote &q)" << endl;
        bookNo = q.bookNo;
        price = q.price;
        return *this;
    }
    //移动构造函数
    Quote(Quote &&q) noexcept:
        bookNo(std::move(q.bookNo)), price(std::move(q.price)){
            cout << "Quote(Quote &&q)" << endl;
        }
    
    //移动赋值运算符
    Quote& operator=(Quote &&q) noexcept{
        cout << "Quote& operator=(Quote &&q)" << endl;
        if(*this != q){
            bookNo = std::move(q.bookNo);
            price = std::move(q.price);
        }
        return *this;
    }
private:
    string bookNo;
protected:
    double price = 0.0;

};


class Bulk_quote : public Quote{
public:
    Bulk_quote(){
        cout << "Bulk_quote()" << endl;
    }
    Bulk_quote(const string &book, double p, size_t qty, double disc):
        Quote(book, p), min_qty(qty), discount(disc){
            cout << "Bulk_quote(const string &book, double p, size_t qty, double disc)" << endl;
        }
    Bulk_quote(const Bulk_quote &b): 
        Quote(b), min_qty(b.min_qty), discount(b.discount){
            cout << "Bulk_quote(const Bulk_quote &b)" << endl;
        }
    Bulk_quote& operator=(const Bulk_quote &rhs){
        cout << "Bulk_quote& operator=(const Bulk_quote &rhs)" << endl;
        Quote::operator=(rhs);
        min_qty = rhs.min_qty;
        discount = rhs.discount;
        return *this;
    }
    Bulk_quote(Bulk_quote &&rhs) noexcept:
        Quote(rhs), min_qty(std::move(rhs.min_qty)), discount(std::move(rhs.discount)){
            cout << "Bulk_quote(Bulk_quote &&b)" << endl;
        }
    Bulk_quote& operator=(Bulk_quote &&rhs) noexcept{
        cout << "Bulk_quote& operator=(Bulk_quote &&rhs)" << endl;
        if(*this != rhs){
            Quote::operator=(rhs);
            min_qty = std::move(rhs.min_qty);
            discount = std::move(rhs.discount);
        }
        return *this;
    }
    double net_price(size_t n) override ;
    ~Bulk_quote() override {
        cout << "~Bulk_quote()" << endl;
    }
    

private:
    size_t min_qty = 0;
    double discount = 0.0;

};
