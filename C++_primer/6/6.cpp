#include <iostream>
#include <string>
#include <vector>

using namespace std;

int fun(int a ,int b);
vector<decltype(fun)*> v;

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return b != 0 ? a / b : 0; }

int main(int argc, char **argv)
{
    v.push_back(add);
    v.push_back(subtract);
    v.push_back(multiply);
    v.push_back(divide);
    for(auto a : v){
        cout << a(2,2) <<endl;
    }

}