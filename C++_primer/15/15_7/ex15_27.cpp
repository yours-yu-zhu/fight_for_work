#include "ex15_27.h"

double Bulk_quote::net_price(size_t n){
    if(n >= quantity){
        return n * (1 - discount) * price;
    }else{
        return n * price;
    }
}

// 15.15
double print_total(ostream &os, Quote &item, size_t n){
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " 
        << n << " total due: " << ret << endl;
    return ret;
}

int main() {
    return 0;

}
