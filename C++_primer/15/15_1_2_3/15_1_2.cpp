#include "15_1_2.h"

double print_total(ostream &os, Quote &item, size_t n){
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " 
        << n << " total due: " << ret << endl;
    return ret;
}

double Bulk_quote::net_price(size_t n){
    if(n >= min_qty){
        return n * (1 - discount) * price;
    }else{
        return n * price;
    }
}

void ex15_6(){
    Quote item("978-7-121-15535-2", 100); 
    Bulk_quote bulk("978-7-121-15535-2", 100, 2, 0.2);
    print_total(cout, item, 2);
    print_total(cout, bulk, 2);

}
double Limit_quote::net_price(size_t n){
    if(n <= max_qty){
        return n * (1 - discount) * price;
    }else{
        return max_qty * (1 - discount) * price + (n - max_qty) * price;
    }
}

void ex15_7(){
    Quote item("978-7-121-15535-2", 100);         // 基类对象
    Limit_quote limited("978-7-121-15535-2", 100, 2, 0.2);    // 派生类对象
    ofstream log("15_7.log");
    print_total(log, item, 2);
    print_total(log, limited, 2);
    print_total(log, limited, 3);
}

void ex15_11(){
    Quote item("978-7-121-15535-2", 100);         // 基类对象
    Limit_quote limited("978-7-121-15535-2", 100, 2, 0.2);    // 派生类对象
    Bulk_quote bulk("978-7-121-15535-2", 100, 2, 0.2);
    item.debug();
    bulk.debug();
    limited.debug();
}



int main() {
    // ex15_6();
    // ex15_7();
    ex15_11();

    return 0;

}
