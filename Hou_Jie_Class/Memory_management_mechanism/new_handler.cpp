#include <new>
#include <iostream>
#include <cassert>
using namespace std;
void noMoreMemory()
{
    cerr << "out of memory!!";
    abort();  
}
	
int main()
{	
	cout << "\n\n\ntest_set_new_handler().......... \n";

    set_new_handler(noMoreMemory);


    int* p = new int[1000000000000];   //well, so BIG!
    assert(p);

    // p = new int[100000000000000000000];  //[Warning] integer constant is too large for its type
    // assert(p);


}
