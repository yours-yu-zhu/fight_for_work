#include <array>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "main_test.h"

using namespace std;
const long ASIZE  =   500000L;


void test_array(){
    cout << "\ntest_array().......... \n"; 
    array<long, ASIZE> c;

    srand(time(NULL));

    clock_t timeStart = clock();
    for(long i = 0; i < ASIZE; ++i){
        c[i] = rand();
    }
    cout << "milli-seconds: " << double(clock() - timeStart) / CLOCKS_PER_SEC * 1000 << endl;
    cout << "array.size()= " << c.size() << endl;
    cout << "array.front()= " << c.front() << endl;
    cout << "array.back()= " << c.back() << endl;
    cout << "array.data()= " << c.data() << endl;

    long target = get_a_target_long();
    timeStart = clock();
    ::qsort(c.data(), ASIZE, sizeof(long), compareLongs);

    long* pItem = (long*)::bsearch(&target, (c.data()), ASIZE, sizeof(long), compareLongs);
    cout << "qsort()+bsearch(), milli-seconds: " << double(clock() - timeStart) / CLOCKS_PER_SEC * 1000 << endl;
    if(pItem != nullptr){
        cout << "found, " << *pItem << endl;
    }else{
        cout << "not found! " << endl;
    }
}

