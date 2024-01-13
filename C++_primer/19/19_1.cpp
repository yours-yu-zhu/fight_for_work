#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>

using namespace std;

int main(){
    int a[10];
    cout << typeid(a).name() << endl;
    cout << typeid(4).name() << endl;
    cout << typeid(string).name() << endl;
    vector <int> v; 

}