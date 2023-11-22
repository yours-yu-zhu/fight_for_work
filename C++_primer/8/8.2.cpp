#include <iostream>
#include<fstream>  
#include <string>
#include <vector>

using namespace std;
//一个元素为一行
void ReadFileToVec_1( string file_name, vector<string>& v){
    string buf;
    ifstream in(file_name);
    if(in){
        while(getline(in,buf)){
            v.push_back(buf);
        }
    }
}

//一个元素为一个单词
void ReadFileToVec_2( string file_name, vector<string>& v){
    string buf;
    ifstream in(file_name);
    if(in){
        while(in >> buf){
            v.push_back(buf);
        }
    }
}

int main(int argc, char **argv){
    vector<string> v;
    string fin = "in.txt";
    string fout = "out.txt";
    ReadFileToVec_2(fin,v);
    ofstream write(fout);
    for(auto x :v){
        write<< x<<endl;
    }
}