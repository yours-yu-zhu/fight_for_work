#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <unordered_map>

using namespace std;

struct DSU {
    vector<int> parent, rank;
    DSU(int n) : parent(n), rank(n, 1) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y) {
        int xr = find(x), yr = find(y);
        if (xr == yr) return;
        if (rank[xr] < rank[yr])
            parent[xr] = yr;
        else if (rank[xr] > rank[yr])
            parent[yr] = xr;
        else {
            parent[yr] = xr;
            rank[xr]++;
        }
    }
};

int main() {
    string S;
    cin >> S;
    int N = S.size();
    vector<int> result(N, 0);

    // Loop through each possible number of connected components
    for (int k = 1; k <= N; ++k) {
        int minLength = numeric_limits<int>::max();
        bool found = false;

        // Iterate through all possible substring lengths
        for (int len = 1; len <= N; ++len) {
            DSU dsu(N);
            for (int start = 0; start + len <= N; ++start) {
                string T = S.substr(start, len);
                for (int l = 0; l + len <= N; ++l) {
                    if (S.substr(l, len) == T) {
                        for (int i = l; i < l + len - 1; ++i) {
                            dsu.unite(i, i + 1);
                        }
                    }
                }
            }

            int components = 0;
            for (int i = 0; i < N; ++i) {
                if (dsu.find(i) == i) components++;
            }

            if (components == k) {
                found = true;
                minLength = min(minLength, len);
                break; // No need to check longer lengths if we already found a valid substring
            }
        }

        result[k - 1] = found ? minLength : 0;
    }

    for (int i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}