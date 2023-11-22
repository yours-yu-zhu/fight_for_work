#include <iostream>
#include <fstream>
#include <sstream>
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
   istringstream iss("dasdacsaadsada sds sdsas sax");
   istream& a = func(iss);
   cout<<a.rdstate()<<endl;
}