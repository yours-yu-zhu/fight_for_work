#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
using namespace std;

//11.7
void ex11_7(){
    map<string, vector<string>> family;
    string last_name, first_name;
    
    while(cout << "Please input last name: " << endl && cin >> last_name ){
        while(cout << "Please input first name: " << endl && cin >> first_name){
            family[last_name].push_back(first_name);
        }
    }

    for(auto &i : family){
        cout << i.first << ": ";
        for(auto &j : i.second){
            cout << j << " ";
        }
        cout << endl;
    }
}
 
//11.9
map<string, list<int>> word_line;

//11.12 && 11.13
void ex11_12(){
    vector<pair<string, int>> vec;
    string str;
    int i;
    fstream ifs("/home/ubuntu/fight_for_work/C++_primer/11/1.txt");
    while(ifs >> str >> i){
        //make_pair版本
        //vec.push_back(make_pair(str, i));

        //{}构造版本
        // vec.push_back({str, i});
        
        //pair标准构造版本
        vec.push_back(pair<string, int>(str, i));
    }
    for(auto i : vec){
        cout << i.first << " " << i.second << endl;
    }
}

//11.14
class Family{
public:
    using child = pair<string, string>;
    using children = vector<child>;
    using data = map<string, children>;
    
    void add(string const &last_name, string const &first_name, string birthday){
        auto child = make_pair(first_name, birthday);
        _data[last_name].push_back(child);
    }

    void print(){
        for(auto const &pair : _data){
            cout << pair.first << ": ";
            for(auto const &child : pair.second){
                cout <<child.first << " " << child.second << endl;
            }
            cout << endl;
        }
    }

private:
    data _data;
};

void ex11_14(){
    Family family;
    auto msg = "Please enter last name, first name and birthday:\n";
    for(string l, f, b;cout <<msg, cin >> l >> f >> b; family.add(l, f, b));
    family.print();
}

int main() {
    // ex11_7();
    // ex11_12();
    ex11_14();

}
