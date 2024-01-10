#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <tuple>
#include <bitset>
#include <regex>
using namespace std;

void ex17_14(){
    try{
        regex r("[[:alnum:]]+\\.(cpp|cxx|cc)$", regex::icase);
    }catch(regex_error e){
        cout << e.what() << "\ncode: " << e.code() << endl;
    }
}

void ex17_15(){
    try{
        regex r("[[:alpha:]]*[^c]ei[[:alpha:]]*", regex::icase);
    }catch(regex_error e){
        cout << e.what() << "\ncode: " << e.code() << endl;
    }
    regex r("[[:alpha:]]*[^c]ei[[:alpha:]]*", regex::icase);
    string s;
    cout << "Enter a word, I will tell you if it follows the rule: ";
    while(cin >> s && s != "q"){
        if(regex_search(s,r)){
            cout << "The word " << s << " follows the rule." << endl;
        }else{
            cout << "The word " << s << " does not follow the rule." << endl;
        }
    }
}

void ex17_16(){
    try{
        regex r("[^c]ei", regex::icase);
    }catch(regex_error e){
        cout << e.what() << "\ncode: " << e.code() << endl;
    }
    regex r("[^c]ei", regex::icase);
    string s;
    cout << "Enter a word, I will tell you if it follows the rule: ";
    while(cin >> s && s != "q"){
        if(regex_search(s,r)){
            cout << "The word " << s << " follows the rule." << endl;
        }else{
            cout << "The word " << s << " does not follow the rule." << endl;
        }
    }
}

void ex17_17(){
	string s;
	cout << "Please input a sequence of words:" << endl;
	getline(cin, s);
	cout << endl;
	cout << "Word(s) that violiate the \"ei\" grammar rule:" << endl;
    string pattern("[[:alpha:]]*[^c]ei[[:alpha:]]*");
    regex r(pattern, regex::icase);
    for(sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it){
        cout << it->str() << endl;
    }
    
}

bool valid(const smatch& m)
{
	// if there is an open parenthesis before the area code
	if (m[1].matched)
		// the area code must be followed by a close parenthesis
		// and followed immediately by the rest of the number or a space
		return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
	else
		// then there can't be a close after the area code
		// the delimiters between the other two components must match
		return !m[3].matched && m[4].str() == m[6].str();
}
void ex17_20(){
	string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
	regex r(phone);
	smatch m;
	string s;
	bool valid_record;
	// read each record from the input file
	while (getline(cin, s))
	{
		valid_record = false;
		// for each matching phone number
		for (sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it)
		{
			valid_record = true;
			// check whether the number's formatting is valid
			if (valid(*it))
				cout << "valid phone number: " << it->str() << endl;
			else
				cout << "invalid phone number: " << it->str() << endl;
		}

		if (!valid_record)
			cout << "invalid record!" << endl;
	}
}

void ex17_24(){
    string pattern = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
    string fmt = "$2.$5.$7";
    regex r(pattern);
    string s;
    while(getline(cin, s)){
        cout << regex_replace(s, r, fmt) << endl;
    }
}

int main(){
    // ex17_14();
    // ex17_15();
    // ex17_16();
    // ex17_17();
    // ex17_20();
    ex17_24();
}  