#ifndef TEST_BASKET_H
#define TEST_BASKET_H

#include "/home/ubuntu/fight_for_work/C++_primer/15/15_4/15_4.h"
#include <memory>
#include <set>

using namespace std;

class Basket{
public:
    void add_item(const Quote &new_item){
        items.insert(shared_ptr<Quote>(new_item.clone()));
    }
    void add_item(Quote &&new_item){
        items.insert(shared_ptr<Quote>(std::move(new_item).clone()));
    }
    double total_receipt(ostream &os) const;
private:
    static bool compare(const shared_ptr<Quote> &lhs, const shared_ptr<Quote> &rhs){
        return lhs->isbn() < rhs->isbn();
    }
    multiset<shared_ptr<Quote>, decltype(compare)*> items{compare};
};

#endif