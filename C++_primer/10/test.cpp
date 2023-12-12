#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <deque>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


int main(int argc, char **argv)
{
    string a[] = {"hello"};
    string b[] = {"hell"};
    // cout << equal(begin(a), end(a), begin(b)) << endl;

    auto f = []()->int{return 1;};
    cout << f() << endl;
}