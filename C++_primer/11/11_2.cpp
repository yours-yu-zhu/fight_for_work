#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void ex11_7(){
    map<string, vector<string>> family;
    string last_name, first_name;
    
    while(cout << "Please input last name: " << endl && cin >> last_name ){
        while(cout << "Please input first name: " << endl && cin >> first_name){
            family[last_name].push_back(first_name);
        }
    }

    for(auto &i : family){
        cout << i.first << ": ";
        for(auto &j : i.second){
            cout << j << " ";
        }
        cout << endl;
    }
}



int main() {
    ex11_7();


}
