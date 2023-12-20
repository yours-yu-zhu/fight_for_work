#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <unordered_map>

using namespace std;

unordered_map<string,string> map_build(ifstream &map_file){
    unordered_map<string,string> trans_map;
    string key;
    string value;
    while(map_file >> key && getline(map_file, value)){
        if(value.size() > 1){
            trans_map[key] = value.substr(1);
        }else{
            throw runtime_error("no rule for " + key);
        }
    }
    return trans_map;
}

const string &trans(const string &word, unordered_map<string,string> &trans_map){
    auto map_it = trans_map.find(word);
    if (map_it != trans_map.end()){
        return map_it->second;
    }else{
        return word;
    }
}

void w_transform(ifstream &map_file, ifstream &input){
    auto trans_map = map_build(map_file);
    string text;
    while(getline(input, text)){
        istringstream s(text);
        string word;
        bool firstword = true;
        while(s >> word){
            if (firstword)
                firstword = false;
            else
                cout << " ";
            cout << trans(word, trans_map);

        }
        cout << endl;
    }
}

void ex_11_37(){
    ifstream map_file("map_file.txt");
    ifstream input("input.txt");
    w_transform(map_file, input);
}


int main() {
	ex_11_37();
	
}
