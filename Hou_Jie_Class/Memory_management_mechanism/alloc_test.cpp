#include <cstdlib>	//malloc, free
#include <iostream>
#include <vector>
#include <list>
#include <ext/pool_allocator.h> 

//C++/11 alias template
template <typename T>
using listPool = std::__cxx11::list<T, __gnu_cxx::__pool_alloc<T>>; 

void* myAlloc(size_t size)
{  return malloc(size); }

void myFree(void* ptr)
{  return free(ptr); }

//我要設計一個可以累計總分配量和總釋放量的 operator new() / operator delete().
//除非 user 直接使用 malloc/free, 否則都避不開它們, 這樣就可以累積總量. 
static long long countNew = 0;
static long long countDel = 0;	    
static long long countArrayNew = 0;
static long long countArrayDel = 0;
static long long timesNew = 0;

inline void* operator new(size_t size) 	 
{
    //std::cout << "jjhou global new(), \t" << size << "\t"; 
    countNew += size; 
    ++timesNew;  
    
    //void* p = myAlloc( size ); 
    //std::cout << p << std::endl; 
    //return p;
    
    return myAlloc( size ); 	    
}

inline void  operator delete(void* ptr, size_t size)  
{  	
    std::cout << "jjhou global delete(ptr,size), \t" << ptr << "\t" << size << std::endl;	
    countDel += size;  	
    myFree( ptr ); 			
}
//(2)
inline void  operator delete(void* ptr)  
{  	
    //std::cout << "jjhou global delete(ptr), \t" << ptr << std::endl;	 	
    myFree( ptr ); 			
}	

int main(){
      	//reset countNew
	countNew = 0;
	timesNew = 0;	
	
  	//list<double, __gnu_cxx::__pool_alloc<double>> lst;	
	//上一行改用 C++/11 alias template 來寫 : 
	listPool<double> lst; 
    //std::__cxx11::list <double> lst

  	for (int i=0; i< 1000000; ++i)
  	    lst.push_back(i);
    std::cout << "::countNew= " << ::countNew << std::endl;  	//16752832 (注意, node 都不帶 cookie)
    std::cout << "::timesNew= " << ::timesNew << std::endl;   //122	
}