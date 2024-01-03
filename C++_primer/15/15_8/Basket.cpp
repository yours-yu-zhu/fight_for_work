#include "Basket.h"

//需要编译/home/ubuntu/fight_for_work/C++_primer/15/15_4/15_4.cpp
double Basket::total_receipt(ostream &os) const{
    double sum = 0.0;
    for(auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter)){
        sum += print_total(os, **iter, items.count(*iter)); 
    }
    os << "Total Sale: " << sum << endl;
    return sum;
}

int main(){
    Basket item;
    for (auto i = 0; i < 4; ++i)
        // 不少于 2 本打折
        item.add_item(Bulk_quote("978-7-121-15535-2", 100, 2, 0.2));
    for (auto i = 0; i < 6; ++i)
        // 不少于 5 本打折
        item.add_item(Bulk_quote("978-7-121-15535-1", 100, 5, 0.5));
    item.total_receipt(std::cout);    
}