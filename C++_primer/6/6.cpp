#include <iostream>
#include <string>
#include <vector>

using namespace std;
int fact(int a){
    if(a==0 || a==1){
        return 1;
    }else{
        return a*fact(a - 1);
    }
}
int main() {

    cout << abs(-1.4)<<endl;

}