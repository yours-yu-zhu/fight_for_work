#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;

// 将字符转换为对应的数值
int charToValue(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    return -1;
}

// 将字符串转换为指定进制下的数值
long long toBaseValue(const string& s, int base) {
    long long value = 0;
    for (char c : s) {
        int digit = charToValue(c);
        if (digit >= base) return -1; // Invalid digit for the base
        value = value * base + digit;
    }
    return value;
}

// 分析表达式并验证在指定进制下是否成立
bool isValidEquation(const string& equation, int base) {
    size_t opPos = equation.find_first_of("+-*/");
    size_t eqPos = equation.find('=');
    
    string left = equation.substr(0, opPos);
    string right = equation.substr(opPos + 1, eqPos - opPos - 1);
    string result = equation.substr(eqPos + 1);

    long long leftValue = toBaseValue(left, base);
    long long rightValue = toBaseValue(right, base);
    long long resultValue = toBaseValue(result, base);

    if (leftValue == -1 || rightValue == -1 || resultValue == -1) return false;

    switch (equation[opPos]) {
        case '+': return leftValue + rightValue == resultValue;
        case '-': return leftValue - rightValue == resultValue;
        case '*': return leftValue * rightValue == resultValue;
        case '/': return rightValue != 0 && leftValue == rightValue * resultValue;
    }

    return false;
}

int main() {
    string equation;
    cin >> equation;

    vector<int> validBases;

    for (int base = 2; base <= 16; ++base) {
        if (isValidEquation(equation, base)) {
            validBases.push_back(base);
        }
    }

    if (validBases.empty()) {
        cout << -1 << endl;
    } else {
        for (size_t i = 0; i < validBases.size(); ++i) {
            if (i > 0) cout << " ";
            cout << validBases[i];
        }
        cout << endl;
    }

    return 0;
}
