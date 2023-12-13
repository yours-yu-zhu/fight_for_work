#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void ex_11_3(){
    map<string, size_t> word_count;
    string word;
    while(cin >> word){
        ++word_count[word];
    }
    for(auto &w : word_count){
        cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;
    }
}

void ex_11_4(){
    map<string, size_t> word_count;
    string word;
    while(cin >> word){
        for(auto &c :word){
            c = tolower(c);
        }
        //****重点为如何用remove_if搭配erase去除标点符号****
        word.erase(remove_if(word.begin(), word.end(), [](char c)
                                            {return ispunct(c);}), 
        word.end());
        ++word_count[word];
        
    }
    for(auto &w : word_count){
        cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;
    }
}


int main() {
    // ex_11_3();
    // ex_11_4();
    
}
