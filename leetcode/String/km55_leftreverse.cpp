#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int n = 0;
    string s;
    cin >> n;
    cin >> s;
    //整体反转字符串
    reverse(s.begin(), s.end());
    //局部反转0~n - 1
    reverse(s.begin(), s.begin() + n);
    //局部反转n~s.size() - 1
    reverse(s.begin() + n, s.end());
    cout << s << endl;
}