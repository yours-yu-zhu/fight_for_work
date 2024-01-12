#include <iostream>
#include <string>
#include <memory>
using namespace std;

class ZooAnimal {
public:
 void print(){
    cout << "ZooAnimal::print()" << endl;
}  //1
virtual ~ZooAnimal() = default;
};


class Endangered {
public:
 void print(){
    cout << "Endangered::print()" << endl;
}    
virtual void highlight(){
    cout << "Endangered::highlight()" << endl;
} //2
virtual ~Endangered() = default;
};


class Bear :public ZooAnimal {
public:
 void print(){
    cout << "Bear::print()" << endl;
}  //1
virtual void toes(){
    cout << "Bear::toes()" << endl;
}   //3
};


class Panda :public Bear, public Endangered {
public:
 void print(){
    cout << "Panda::print()" << endl;
}     //1
virtual void highlight(){
    cout << "Panda::highlight()" << endl;
} //2
virtual void toes(){
    cout << "Panda::toes()" << endl;
}      //3
virtual void cuddle(){
    cout << "Panda::cuddle()" << endl;
}    //4
};

int main()
{
Bear *pb = new Panda();


pb->print();     //正确，调用Panda::print()
// pb->cuddle();    //错误，不属于Bear接口
// pb->highlight(); //错误，不属于Bear接口


// delete pb;       //正确，调用Panda::~Panda()


return 0;
}