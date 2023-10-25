#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    vector<int> v ;
    for(int i ; i <100; i++){
        v.push_back(i);
    }
    for(auto &i : v){
        i *= i; 
    }
    for(auto i : v){
        cout << i<<endl; 
    }
}