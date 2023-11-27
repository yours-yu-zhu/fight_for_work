#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <deque>
#include <vector>

using namespace std;


//9.4函数
void find(list<int>::iterator begin,list<int>::iterator end,int a){
    while (begin != end)
    {
        cout << *begin<< endl;
        ++begin;
    }

}
    
int main(int argc, char **argv)
{
    list<int> myVector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    find(myVector.begin(),myVector.end(),8);
}