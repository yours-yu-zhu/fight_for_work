#include <list>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cstdio>  
#include "main_test.h"

using namespace std;
void test_list(long& value){
	cout << "\ntest_list().......... \n";
    list<string> c;
    char buf[10];

    clock_t timeStart = clock();
    srand(time(NULL));

    for(long i = 0; i < value; ++i){
        try{
            snprintf(buf, 10, "%d", rand());
            c.push_back(string(buf));
        }catch(exception& p){
            cout << "i=" << i << " " << p.what() << endl;
            abort();
        }
    }
    cout << "milli-seconds: " << double(clock() - timeStart) / CLOCKS_PER_SEC * 1000 << endl;
    cout << "list.max_size() = " << c.max_size() << endl;
    cout << "list.size() = " << c.size() << endl;
    cout << "list.front() = " << c.front() << endl;
    cout << "list.back() = " << c.back() << endl;

    string target = get_a_target_string();
    timeStart = clock();
    auto pItem = find(c.begin(), c.end(), target);
    cout << "find(), milli-seconds: " << double(clock() - timeStart) / CLOCKS_PER_SEC * 1000 << endl;

    if(pItem != c.end()){
        cout << "found, " << *pItem << endl;
    }else{
        cout << "not found! " << endl;
    }

    timeStart = clock();
    c.sort();
    cout << "sort(), milli-seconds: " << double(clock() - timeStart) / CLOCKS_PER_SEC * 1000 << endl;

    

}
