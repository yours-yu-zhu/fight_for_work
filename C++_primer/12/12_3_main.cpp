#include "12_3.h"

using namespace std;

void runQueries(ifstream &infile){
    TextQuery tq(infile);
    while(true){
        cout << "enter word to look for, or q to quit: ";
        string s;
        if(!(cin >> s) || s == "q"){
            break;
        }
        print(cout, tq.query(s)) << endl;
    }
}


int main() {
	ifstream ifs("/home/ubuntu/fight_for_work/C++_primer/15/15_9/data.txt");
	runQueries(ifs);

}
