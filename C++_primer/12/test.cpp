#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <exception>
#include <iostream>

using  namespace std;


int main()
{
    shared_ptr<vector <string>> file(new vector<string>);
    file->push_back("hello");
    file->push_back("world");
    cout << file->size();
}