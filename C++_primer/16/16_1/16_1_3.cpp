#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

//ex 16.19
template <typename container>
void print(ostream &os, const container &c){
    using sp = typename container::size_type;
    for(sp i = 0; i < c.size(); ++i){
        os << c[i] << " ";
    }
    os << endl;
}

void ex16_19(){
    vector<int> ivec{1, 2, 3, 4, 5, 6};
    print(cout ,ivec);

}

template <typename container>
void print_it(ostream &os, const container &c){
    for(auto it = c.begin(); it != c.end(); ++it){
        os << *it << " ";
    }
    os << endl;
}

void ex16_20(){
    vector<int> ivec{1, 2, 3, 4, 5, 6};
    print_it(cout ,ivec);
    list<string> slis{"c++", "primer", "5th"};
    print_it(cout, slis);

}


int main() {
    // ex16_19();
    ex16_20();
    return 0;
}
