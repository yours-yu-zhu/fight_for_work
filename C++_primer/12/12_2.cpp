#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <cstring>
using namespace std;

void ex_12_23(){
    const char *c1 = "Hello ";
    const char *c2 = "World!";
    unsigned len = strlen(c1) + strlen(c2) + 1;
    char *r = new char[len];
    strcpy(r, c1);  // copy c1 to r
    strcat(r, c2);  // add c2 to r
    cout << r << endl;

    string s1 = "Hello ";
    string s2 = "World!";
    unsigned len2 = s1.size() + s2.size() + 1;
    char *r2 = new char[len2];
    strcpy(r2, (s1 + s2).c_str());
    cout << r2 << endl;
    delete []r;
    delete []r2;
 }

void ex_12_24(){
    cout << "Enter the size of the string: ";
    int size;
    cin >> size;
    char *r = new char[size + 1];
    cin.ignore();
    cout << "Enter the string: ";
    cin.get(r, size + 1);
    cout << r << endl;
    delete []r;
}

void ex_12_26(){
    cout << "Enter the size of the string: ";
    int size;
    cin >> size;
    allocator<string> alloc;
    auto p = alloc.allocate(size);
    auto q = p;
    string s;
    cout << "Enter the string: ";
    while(cin >> s && q != p + size){
        alloc.construct(q++, s);
    }
    cout << "The string you entered is: " << endl;
    while (q != p){
        --q;
        cout << *q << endl;
        alloc.destroy(q);
    }
    alloc.deallocate(p, size); 
}

int main() {
    // ex_12_23();
    // ex_12_24();
    ex_12_26();


}
