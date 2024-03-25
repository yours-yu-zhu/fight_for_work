#include <iostream>
#include <string>

class allocator 
{
private:
  	struct obj {
    	struct obj* next;  //embedded pointer
  	};	
public:
    void* allocate(size_t);
    void  deallocate(void*, size_t);
    void  check();
    
private: 
    obj* freeStore = nullptr;
    const int CHUNK = 5; //小一點方便觀察 
};

void* allocator::allocate(size_t size)
{
    obj* p;
    if(!freeStore){
        size_t chunk = CHUNK * size;
        freeStore = p = (obj*)malloc(chunk);
        for(int i = 0; i < CHUNK - 1; ++i){
            p->next = (obj*)((char*)p +size);
            p = p->next;
        }
        p->next = nullptr;
    }
    p = freeStore;
    freeStore = freeStore->next;
    return p;
}

void allocator::deallocate(void* p, size_t)
{
    ((obj*)p)->next = freeStore;
    freeStore = (obj*)p;
}

void allocator::check(){
    obj* p = freeStore;
    int count = 0;
    while(p){
        //std::cout << p << std::endl;
        p = p->next;
        count++;
    }
    std::cout << "There are " << count << " free nodes." << std::endl;
}

class Foo{
public:
    long L;
    std::string str;
    static allocator myAlloc;
public:
    Foo(long l):L(l){}
    static void* operator new(size_t size){
        return myAlloc.allocate(size);
    }
    static void operator delete(void* p, size_t size){
        myAlloc.deallocate(p, size);
    }
};
allocator Foo::myAlloc;

int main(){
    Foo* p[100];
    std::cout << "sizeof(Foo) = " << sizeof(Foo) << std::endl;
    for(int i = 0; i < 100; ++i){
        p[i] = new Foo(i);
        std::cout << p[i] << ' ' << p[i]->L << std::endl;
    }
    p[0]->myAlloc.check();
    for(int i = 0; i < 100; ++i){
        delete p[i];
    }
    p[0]->myAlloc.check();
    return 0;
}
