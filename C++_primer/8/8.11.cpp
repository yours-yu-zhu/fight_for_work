#include <iostream>
#include <fstream>  
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct PersonInfo {
    string name;
    vector<string> phones;
};

bool valid(const string& str){
    for(char c : str){
        if(!isdigit(c)){
            return false;
        }
    }
    return true;
}

string format(const string& str)
{
    return str.substr(0,3) + "-" + str.substr(3,3) + "-" + str.substr(6);
}


int main(int argc, char **argv){
    ifstream ifs("./PhoneNumber.txt");
    if(!ifs){
        cout << "no such file!"<<endl;
        return -1;
    }
    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    //把一行变为 一个类
    while (getline(ifs,line))
    {
        PersonInfo info;
        record.clear();
        record.str(line);
        record >> info.name;
        while(record >> word){
            info.phones.push_back(word);
        }
        people.push_back(info);
    }
    
    for(const auto& entry : people){
        ostringstream formatted, badNums;
        for(const auto& nums : entry.phones){
            if(!valid(nums)){
                badNums << " "<< nums;
            }
            else{
                formatted << " "<< format(nums);
            }
        }
        if(badNums.str().empty()){
            cout << entry.name <<" "<<formatted.str()<<endl;
        }
        else{
            cerr << "input error:"<<entry.name<<"invalid numbers:"<< badNums.str()<<endl; 
        }
    }

}