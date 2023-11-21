#include <iostream>
#include <string>
#include <vector>

using namespace std;

istream& func(istream& in);

istream& func(istream& in){
    string buf;
    while(in >> buf){
        cout << buf << endl;
    }
    in.clear();
    return in;
}

int main(int argc, char **argv)
{
   istream& a = func(cin);
   cout<<a.rdstate()<<endl;
}