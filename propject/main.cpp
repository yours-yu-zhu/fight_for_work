#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        std::cout << "Base Constructor\n";
        // 在构造函数中调用虚函数，将使用静态绑定，调用基类版本
        this->virtualFunction();
    }

    virtual ~Base() {
        std::cout << "Base Destructor\n";
        // 在析构函数中调用虚函数，将使用动态绑定，调用相应对象的版本
        this->virtualFunction();
    }

    virtual void virtualFunction() const {
        std::cout << "Base Virtual Function\n";
    }
};

class Derived : public Base {
public:
    Derived() {
        std::cout << "Derived Constructor\n";
        // 在构造函数中调用虚函数，将使用静态绑定，调用基类版本
        this->virtualFunction();
    }

    virtual ~Derived() {
        std::cout << "Derived Destructor\n";
        // 在析构函数中调用虚函数，将使用动态绑定，调用相应对象的版本
        this->virtualFunction();
    }

    virtual void virtualFunction() const override {
        std::cout << "Derived Virtual Function\n";
    }
};

int main() {
    Derived derivedObj;
    return 0;
}