#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to perform big integer division by 3
pair<string, int> divideBy3(const string& num) {
    string quotient;
    int remainder = 0;
    bool firstNonZero = false;

    for (char c : num) {
        int digit = c - '0';
        int temp = remainder * 10 + digit;
        int q_digit = temp / 3;
        remainder = temp % 3;

        if (q_digit != 0 || firstNonZero) {
            quotient += (q_digit + '0');
            firstNonZero = true;
        }
    }

    if (!firstNonZero) {
        quotient = "0";
    }

    return {quotient, remainder};
}

int main() {
    string N;
    cin >> N;

    if (N == "0") {
        cout << -1 << endl;
        return 0;
    }

    string base3_representation;
    while (N != "0") {
        auto result = divideBy3(N);
        N = result.first;
        int remainder = result.second;
        base3_representation += (remainder + '0');
    }

    reverse(base3_representation.begin(), base3_representation.end());

    // Check if the base-3 representation is '1' followed by zeros
    if (base3_representation[0] != '1') {
        cout << -1 << endl;
        return 0;
    }

    for (size_t i = 1; i < base3_representation.size(); ++i) {
        if (base3_representation[i] != '0') {
            cout << -1 << endl;
            return 0;
        }
    }

    // The exponent x is the number of zeros in the base-3 representation
    int x = base3_representation.size() - 1;
    cout << x << endl;

    return 0;
}
