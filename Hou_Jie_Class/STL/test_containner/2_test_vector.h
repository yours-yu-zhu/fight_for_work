#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cstdio>  
#include "main_test.h"

using namespace std;
void test_vector(long& value){
    cout << "\ntest_vector().......... \n";

    vector<string> c;
    char buf[10];
    clock_t timestart = clock();
    srand(time(NULL));

    for(long i = 0; i <value; ++i){
        try{
            snprintf(buf, 10, "%d", rand());
            c.push_back(string(buf));
        }
        catch(exception& p){
            cout << "i = " << i << " " << p.what() << endl;
            abort();
        }
    }

    cout << "milli-seconds: " << (clock() - timestart) << endl;
    cout << "vector.max_size() = " << c.max_size() << endl;
    cout << "vector.size() = " << c.size() << endl;
    cout << "vector.capacity() = " << c.capacity() << endl;
    cout << "vector.front() = " << c.front() << endl;
    cout << "vector.back() = " << c.back() << endl;
    cout << "vector.data() = " << c.data() << endl; 

    string target = get_a_target_string();
    {
        timestart = clock();
        auto pItem = find(c.begin(), c.end(), target);
        cout << "find(), milli-seconds: " << (clock() - timestart) << endl; 
        if(pItem != c.end()){
            cout << "found, " << *pItem << endl;
        }else{
            cout << "not found! " << endl;
        }
    } 

    {
        timestart = clock();
        sort(c.begin(), c.end());
        string* pItem = (string*)::bsearch(&target, (c.data()), c.size(), sizeof(string), comepareStrings);
        cout << "sort()+bsearch(), milli-seconds: " << (clock() - timestart) << endl;
        if(pItem != nullptr){
            cout << "found, " << *pItem << endl;
        }else{
            cout << "not found! " << endl;
        }
    }

}
