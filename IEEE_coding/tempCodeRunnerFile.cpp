#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<string> generateSwaps(string num) {
    vector<string> neighbors;
    int n = num.size();
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(i == 0 && num[j] == '0') continue;
            string swapped = num;
            swap(swapped[i], swapped[j]);
            neighbors.push_back(swapped);
        }
    }
    return neighbors;
}

int main(){
    string N;
    int K;
    cin >> N >> K;

    unordered_set<string> current;
    current.insert(N);
    for(int step=0; step<K; step++) {
        unordered_set<string> next;
        for(auto &num : current) {
            vector<string> neighbors = generateSwaps(num);
            for(auto &s : neighbors) {
                next.insert(s);
            }
        }
        if(next.empty()) break;
        current = move(next);
    }

    string max_num = "-1";
    for(auto &num : current) {
        if(num > max_num) {
            max_num = num;
        }
    }

    cout << max_num;
}
