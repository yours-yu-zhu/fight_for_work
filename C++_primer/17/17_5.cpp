#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <tuple>
#include <bitset>
#include <regex>
#include <random>
#include <iomanip>

using namespace std;

int main()
{
	cout <<"default format: " << 100 * sqrt(2.0) << '\n'
		<< "scientific: " << scientific << 100 * sqrt(2.0) << '\n'
		<< "fixed decimal: " << fixed << 100 * sqrt(2.0) << '\n'
		<< "hexidecimal: " << uppercase << hexfloat << 100 * sqrt(2.0) << '\n'
		<< "use defaults: " << defaultfloat << 100 * sqrt(2.0)
		<< "\n\n";
    
    cout << "________________________________________________________________________________________\n\n";
    cout <<left<<setw(15) << "default format:" <<setw(25)<< right<< 100 * sqrt(2.0) << '\n'
	<< left << setw(15) << "scientific:" << scientific << setw(25) << right << 100 * sqrt(2.0) << '\n'
	<< left << setw(15) << "fixed decimal:" << setw(25) << fixed << right << 100 * sqrt(2.0) << '\n'
	<< left << setw(15) << "hexidecimal:" << setw(25) << uppercase << hexfloat << right << 100 * sqrt(2.0) << '\n'
	<< left << setw(15) << "use defaults:" << setw(25) << defaultfloat << right << 100 * sqrt(2.0)
	<< "\n\n";
}