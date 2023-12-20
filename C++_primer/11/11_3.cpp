#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void ex_11_16(){
    map<string, int> word_count = {{"hello", 1}, {"world", 2}};
    auto it = word_count.begin();
    while(it != word_count.end()){
        ++(it->second);
        ++it;
    }
    for(const auto &w : word_count){
        cout << w.first << " " << w.second << endl;
    }
}

void ex_11_18(){
    map<string, int> word_count = {{"hello", 1}, {"world", 2}};
    map<string, int>::iterator mapp_it = word_count.begin();
    while(mapp_it != word_count.end()){
        ++(mapp_it->second);
        ++mapp_it;
    }
    for(const auto &w : word_count){
        cout << w.first << " " << w.second << endl;
    }
}


void ex_11_20(){
    map<string, size_t> word_count;
    string word;
    while(cin >> word){
        auto ret = word_count.insert({word,1});
        if(!ret.second){
            ++(ret.first->second);
        }
    }

    for(auto &w : word_count){
        cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;
    }
}

void ex_11_29(){
    map<string,vector<int>> a;
    map<string,vector<int>>::iterator it = a.find("hello");
}

void ex_11_31(){
    multimap<string, string> authors{
		{ "alan", "DMA" },
		{ "pezy", "LeetCode" },
		{ "alan", "CLRS" },
		{ "wang", "FTP" },
		{ "pezy", "CP5" },
		{ "wang", "CPP-Concurrency" } };
    	
    string author = "pezy";
	string work = "1";

    auto found = authors.find(author);
    auto count = authors.count(author);

    while(count){
        if(found->second == work){
            authors.erase(found);
            break;
        }
        ++found;
        --count;
    }

    for(const auto &w : authors){
        cout << w.first << " " << w.second << endl;
    }
}

map<string,string> map_build(ifstream &map_file){
    map<string,string> trans_map;
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

const string &trans(const string &word, map<string,string> &trans_map){
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
    //ex_16();
    //ex_18();
    //ex_11_20();
    //ex_11_31();
    ex_11_37();
}
