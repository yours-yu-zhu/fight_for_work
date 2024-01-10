#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <tuple>
#include <bitset>
#include <regex>
#include <random>

using namespace std;

unsigned random_gen(){
    static default_random_engine e(time(0));
    static uniform_int_distribution<unsigned> u;
    return u(e);
}

unsigned random_gen(unsigned seed){
    static default_random_engine e(seed);
    static uniform_int_distribution<unsigned> u;
    return u(e);
}

unsigned random_gen(unsigned seed, unsigned min, unsigned max){
    static default_random_engine e(seed);
    static uniform_int_distribution<unsigned> u(min, max);
    return u(e);
}

int main(){
    cout << random_gen() << endl;
    cout << random_gen(10) << endl;
    cout << random_gen(10, 0, 9) << endl;
    return 0;
}  