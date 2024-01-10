#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <tuple>
#include <bitset>
using namespace std;



int main(){
    vector<int> v = { 1, 2, 3, 5, 8, 13, 21 };
    bitset<32> bset;
    for(auto i : v){
        bset.set(i);
    }
    bitset<32> bset2;
    for(auto i = 0; i < 32; ++i){
       bset2.set(i, bset[i]);
    }
    cout << bset << endl;
    cout << bset2 << endl;

}  