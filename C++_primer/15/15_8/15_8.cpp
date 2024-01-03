#include "/home/ubuntu/fight_for_work/C++_primer/15/15_4/15_4.h"
#include <vector>
#include <memory>

//需要编译/home/ubuntu/fight_for_work/C++_primer/15/15_4/15_4.cpp

void ex15_28(){
    // 不少于 2 本打折
    Bulk_quote bulk1("978-7-121-15535-2", 100, 2, 0.2);    // 派生类对象
    // 不少于 5 本打折
    Bulk_quote bulk2("978-7-121-15535-1", 100, 5, 0.5);    // 派生类对象

    print_total(std::cout, bulk1, 4);
    print_total(std::cout, bulk2, 6);
    std::cout << bulk1.net_price(4) + bulk2.net_price(6)
              << std::endl;
    //ex15_28
    vector<Quote> QuoteVec;
    QuoteVec.push_back(bulk1);
    QuoteVec.push_back(bulk2);
    print_total(cout, QuoteVec[0], 4);
    print_total(cout, QuoteVec[1], 6);
    cout << QuoteVec[0].net_price(4) + QuoteVec[1].net_price(6)
         << endl;
    //给vector<Quote>传入Bulk_quote，会发生切割，只会保留Quote部分
}

void ex15_29(){
    // 不少于 2 本打折
    shared_ptr<Bulk_quote> bulk1 = make_shared<Bulk_quote>("978-7-121-15535-2", 100, 2, 0.2);
    // 不少于 5 本打折
    shared_ptr<Bulk_quote> bulk2 = make_shared<Bulk_quote>("978-7-121-15535-1", 100, 5, 0.5);

    print_total(std::cout, *bulk1, 4);
    print_total(std::cout, *bulk2, 6);
    std::cout << bulk1->net_price(4) + bulk2->net_price(6)
              << std::endl;
    //ex15_29
    vector<shared_ptr<Quote>> QuoteVec;
    QuoteVec.push_back(bulk1);
    QuoteVec.push_back(bulk2);
    print_total(std::cout, *QuoteVec[0], 4);
    print_total(std::cout, *QuoteVec[1], 6);
    std::cout << QuoteVec[0]->net_price(4) + QuoteVec[1]->net_price(6)
              << std::endl;    


}

int main() {
    ex15_29();
}
