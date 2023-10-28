#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main(){
    int i = 5.0;
    double d = 5;
    i *= static_cast<int>(d);
    cout<< i<<endl;
}
