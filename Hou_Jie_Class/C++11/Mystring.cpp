#include <iostream>
#include <cstring>
#include <vector>
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
size_t Mystring::DCtor = 0;
size_t Mystring::Ctor = 0;
size_t Mystring::CCtor = 0;
size_t Mystring::CAsign = 0;
size_t Mystring::MCtor = 0;
size_t Mystring::MAsign = 0;
size_t Mystring::Dtor = 0;


void test301_move_semantics_with_noexcept()
{
  	cout << "\ntest301_move_semantics_with_noexcept_and_swap().......\n";    
       
  	vector<Mystring> vec;	
  	//without reserve(N);
    
  	vec.push_back(Mystring("jjhou"));		//Move Constructor is called! source: jjhou
  											//Destructor is called! [0]
  	vec.push_back(Mystring("sabrina"));  	//Move Constructor is called! source: sabrina
  											//Move Constructor is called! source: jjhou 	
											//Destructor is called! [0]
											//Destructor is called!	[0]								
  	vec.push_back(Mystring("stacy"));  		//Move Constructor is called! source: stacy	
											//Move Constructor is called! source: jjhou
											//Move Constructor is called! source: sabrina 	
											//Destructor is called! [0]
											//Destructor is called! [0]
											//Destructor is called! [0]
	//以上十分好：
	//  1, 以 temp obj.放入容器，編譯器知道那是個 Rvalue, 於是呼叫 move ctor 而非 copy ctor. 
	//  2, 當 push_back() 引發 vector 擴展，擴展過程中使用 move 而非 copy. 
	cout << "vec.clear() ------- \n";
	vec.clear();			
								
  	//exit 前會 delete all existing objects.  																					
}

int main()
{
    test301_move_semantics_with_noexcept();
    return 0;
}