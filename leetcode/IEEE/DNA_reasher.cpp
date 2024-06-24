#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 计算部分匹配表（LPS数组）
vector<int> computeLPSArray(const string& pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);
    int length = 0;
    int i = 1;
    
    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    
    return lps;
}

// KMP字符串匹配
vector<int> KMPSearch(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();
    
    vector<int> lps = computeLPSArray(pattern);
    vector<int> result;
    
    int i = 0;
    int j = 0;
    
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        
        if (j == m) {
            result.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    
    return result;
}

int main() {
    string T, P;
    cin >> T >> P;
    
    vector<int> result = KMPSearch(T, P);
    
    if (result.empty()) {
        cout << "Not Found" << endl;
    } else {
        for (int index : result) {
            cout << index << " ";
        }
        cout << endl;
    }
    
    return 0;
}
