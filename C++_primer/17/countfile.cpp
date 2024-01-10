#include <iostream>
#include <fstream>
using namespace std;

int main(){
    fstream io("/home/ubuntu/fight_for_work/C++_primer/17/data.txt",fstream::in|fstream::out|fstream::ate);
    if(!io){
        cerr << "can't open file" << endl;
        return -1;
    }
    auto end_mark = io.tellg();
    io.seekg(0,fstream::beg);
    size_t cnt = 0;
    string line;
    while(io && io.tellg() != end_mark && getline(io, line)){
        cnt += line.size() + 1;
        auto mark = io.tellg();
        io.seekp(0,fstream::end);
        io << cnt;
        if(mark != end_mark){
             io << " ";
        }
        io.seekg(mark);
    }
    io.seekp(0,fstream::end);
    io << "\n";
}