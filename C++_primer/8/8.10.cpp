#include <iostream>
#include <fstream>  
#include <sstream>
#include <string>
#include <vector>

using namespace std;

//编写程序，将来自一个文件中的行保存在一个vector中。然后使用一个istringstream从vector读取数据元素，每次读取一个单词。
int main(int argc, char **argv){
    ifstream ifs("in.txt");
    if(!ifs){
        cout << "no such file!"<<endl;
        return -1;
    }
    vector<string> vec;
    string line;
    while(getline(ifs,line)){
        vec.push_back(line);
    }
    for(auto v : vec){
        cout << "line:"<< v <<endl;
    }
    for(auto v : vec){
        istringstream iss(v);
        string word;
        while(iss >> word){
            cout << "word:"<< word <<endl;
        }
    }
}