#include <iostream>
#include <string>
using namespace std;

class Foo{
public:
    int _id;
    long _data;
    string _str;

public:
    Foo(): _id(0){
        cout << "default ctor.this=" << this << "\tid="<< _id<< endl;
    }
    Foo(int id): _id(id){
        cout << "ctor.this=" << this << "\tid="<< _id<< endl;
    }
    ~Foo(){
        cout << "dtor.this=" << this  << "\tid="<< _id<< endl;
    }
    // virtual void func(){
    //     cout << "Foo::func()" << endl;
    // }
    static void* operator new(size_t size);
    static void operator delete(void* pdead, size_t  size);
    static void* operator new[](size_t size);
    static void operator delete[](void* pdead, size_t  size);
};

void* Foo::operator new(size_t size){
    Foo* p = (Foo*)malloc(size);
    cout << "operator new size:" << size << "\tp=" << p << endl;
    return p;
}
void Foo::operator delete(void* pdead, size_t size){
    cout << "operator delete size:" << size << "\tp=" << pdead << endl;
    free(pdead);
}

void* Foo::operator new[](size_t size){
    Foo* p = (Foo*)malloc(size);
    cout << "operator new[] size:" << size << "\tp=" << p << endl;
    return p;
}

void Foo::operator delete[](void* pdead, size_t size){
    cout << "operator delete[] size:" << size << "\tp=" << pdead << endl;
    free(pdead);
}

int main(){
    cout << sizeof(int) << endl;
    cout << sizeof(long) << endl;
    cout << sizeof(string) << endl;
    cout << sizeof(Foo) << endl;
    Foo *pf = new Foo(7);
    delete pf;
    // Foo* parrat = new Foo[3];
    // delete[] parrat;
}