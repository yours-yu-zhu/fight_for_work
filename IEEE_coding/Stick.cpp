#include <iostream>
#include <algorithm>
using namespace std;

long long n, k, l;
__int128 n1, k1, l1;

string int128ToString(__int128 value)
{
    if (value == 0)
        return "0";
    string result;
    bool isNegative = value < 0;
    if (isNegative)
        value = -value;
    while (value > 0)
    {
        result += '0' + value % 10;
        value /= 10;
    }
    if (isNegative)
        result += '-';
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    cin >> n >> k >> l;
    l = l * 2ll;
    n1 = n;
    k1 = k;
    l1 = l;
    if (k >= l)
        cout << int128ToString(l1 * l1 * n1);
    if (k < l)
        cout << int128ToString(l1 * l1 + (k1 * l1 * 2 - k1 * k1) * (n1 - 1));
}