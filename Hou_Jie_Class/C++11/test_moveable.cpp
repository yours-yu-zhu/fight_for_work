#include <iostream>
#include <cstring>
#include <vector>
#include <ctime>
using namespace std;

class Mystring{
public:
    static size_t DCtor;
    static size_t Ctor;
    static size_t CCtor;
    static size_t CAsign;
    static size_t MCtor;
    static size_t MAsign;
    static size_t Dtor;
private:
    char* _data;
    size_t _len;
    void _init_data(const char* s){
        _data = new char[_len + 1];
        memcpy(_data, s, _len);
        _data[_len]= '\0';
    }
public:
    // default constructor
    Mystring(): _data(nullptr), _len(0){
        ++DCtor;
    }

    //constructor
    Mystring(const char* p): _len(strlen(p)){
        ++Ctor;
        _init_data(p);
    }
    // copy constructor
    Mystring(const Mystring& str): _len(str._len){
        ++CCtor;
        _init_data(str._data);
    }
    // move constructor
    Mystring(Mystring&& str) noexcept : _data(str._data), _len(str._len){
        ++MCtor;
        str._len = 0;
        str._data = nullptr;
    }
    // copy assignment
    Mystring& operator=(const Mystring& rhs){
        ++CAsign;
        if(this != &rhs){
            if(_data) delete _data;
            _len = rhs._len;
            _init_data(rhs._data);
        }
        return *this;
    }
    // move assignment
    Mystring& operator=(Mystring&& rhs) noexcept{
        ++MAsign;
        if(this != &rhs){
            if(_data) delete _data;
            _len = rhs._len;
            _data = rhs._data;
            rhs._len = 0;
            rhs._data = nullptr;
        }
        return *this;
    }
    // destructor
    ~Mystring(){
        ++Dtor;
        if(_data) delete _data;
    }
};

class My_no_string{
public:
    static size_t DCtor;
    static size_t Ctor;
    static size_t CCtor;
    static size_t CAsign;
    static size_t Dtor;
private:
    char* _data;
    size_t _len;
    void _init_data(const char* s){
        _data = new char[_len + 1];
        memcpy(_data, s, _len);
        _data[_len]= '\0';
    }
public:
    // default constructor
    My_no_string(): _data(nullptr), _len(0){
        ++DCtor;
    }

    //constructor
    My_no_string(const char* p): _len(strlen(p)){
        ++Ctor;
        _init_data(p);
    }
    // copy constructor
    My_no_string(const My_no_string& str): _len(str._len){
        ++CCtor;
        _init_data(str._data);
    }
    // copy assignment
    My_no_string& operator=(const My_no_string& rhs){
        ++CAsign;
        if(this != &rhs){
            if(_data) delete _data;
            _len = rhs._len;
            _init_data(rhs._data);
        }
        return *this;
    }
    // destructor
    ~My_no_string(){
        ++Dtor;
        if(_data) delete _data;
    }
};


size_t Mystring::DCtor = 0;
size_t Mystring::Ctor = 0;
size_t Mystring::CCtor = 0;
size_t Mystring::CAsign = 0;
size_t Mystring::MCtor = 0;
size_t Mystring::MAsign = 0;
size_t Mystring::Dtor = 0;
size_t My_no_string::DCtor = 0;
size_t My_no_string::Ctor = 0;
size_t My_no_string::CCtor = 0;
size_t My_no_string::CAsign = 0;
size_t My_no_string::Dtor = 0;


template<typename Container>
void test_moveable(Container c, long& value){
    using Valtype = typename Container::value_type;
    clock_t timeStart = clock();
    char buf[10];
    for(long i = 0; i < value; ++i){
        snprintf(buf, 10, "%d", rand());
        auto ite = c.end();
        c.insert(ite, Mystring(buf));
    }
    cout << "milli-seconds: " << (clock() - timeStart) << endl;
    cout << "Container size = " << c.size() << endl;
    cout << typeid(*(c.begin())).name() << endl;
    cout << "CCtor = " << Mystring::CCtor << endl;
    cout << "MCtor = " << Mystring::MCtor << endl;
    cout << "CAsign = " << Mystring::CAsign << endl;
    cout << "MAsign = " << Mystring::MAsign << endl;
    cout << "Dtor = " << Mystring::Dtor << endl;
    cout << "Ctor = " << Mystring::Ctor << endl;
    cout << "DCtor = " << Mystring::DCtor << endl;
    cout << "---------------------------------" << endl;
}

template<typename Container>
void test_no_moveable(Container c, long& value){
    using Valtype = typename Container::value_type;
    clock_t timeStart = clock();
    char buf[10];
    for(long i = 0; i < value; ++i){
        snprintf(buf, 10, "%d", rand());
        auto ite = c.end();
        c.insert(ite, Valtype(buf));
    }
    cout << "milli-seconds: " << (clock() - timeStart) << endl;
    cout << "Container size = " << c.size() << endl;
    cout << typeid(*(c.begin())).name() << endl;
    cout << "CCtor = " << My_no_string::CCtor << endl;
    cout << "CAsign = " << My_no_string::CAsign << endl;
    cout << "Dtor = " << My_no_string::Dtor << endl;
    cout << "Ctor = " << My_no_string::Ctor << endl;
    cout << "DCtor = " << My_no_string::DCtor << endl;
    cout << "---------------------------------" << endl;
}

int main(){
    long value = 3000000;
    test_moveable(vector<Mystring>(), value);
    test_no_moveable(vector<My_no_string>(), value);

    return 0;
}