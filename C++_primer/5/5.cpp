#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main() {
    int i, j;
    cin>> i>> j;
    if(j == 0){
        throw runtime_error("di is 0");
    }
    cout << i/j<<endl;


}