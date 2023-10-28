#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    vector<int> v(10,1);
    for (auto i = v.begin(); i != v.end(); i++)
    {
        *i +=6;
    }
    
    for(auto a :v){
        cout << a <<endl;
    }
}
