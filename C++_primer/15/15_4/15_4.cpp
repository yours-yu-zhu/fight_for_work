#include "15_4.h"

// 15.15
double print_total(ostream &os, Quote &item, size_t n){
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " 
        << n << " total due: " << ret << endl;
    return ret;
}

double Bulk_quote::net_price(size_t n){
    if(n >= quantity){
        return n * (1 - discount) * price;
    }else{
        return n * price;
    }
}

void ex15_15(){
    Quote item("978-7-121-15535-2", 100);         // 基类对象
    Bulk_quote bulk("978-7-121-15535-2", 100, 2, 0.2);    // 派生类对象，不少于 2 本打折
    print_total(std::cout, item, 2);
    print_total(std::cout, bulk, 2);
}

//15.16
double Limit_quote::net_price(size_t n){
    if(n <= quantity){
        return n * (1 - discount) * price;
    }else{
        return quantity * (1 - discount) * price + (n - quantity) * price;
    }
}

void ex15_16(){
    Quote item("978-7-121-15535-2", 100);         // 基类对象
    Limit_quote limited("978-7-121-15535-2", 100, 2, 0.2);    // 派生类对象
    // 不超过两本全部有折扣，超过两本的话，超出部分按原价
    print_total(std::cout, item, 2);
    print_total(std::cout, limited, 2);
    print_total(std::cout, limited, 3);
}

// 15.17
void ex15_17(){
    // Disc_quote disc_quote;
}

// int main() {
//     // ex15_15();
//     // ex15_16();
//     return 0;

// }
