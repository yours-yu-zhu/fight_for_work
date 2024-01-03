#include <iostream> 
#include <vector>

using namespace std;

int main(){
    vector<int> v1{1,2,3,4,5,6,7,8,9};
    for (size_t n = 0; n != v1.size(); ++n){
        cout << n << endl;
    }
}