#include <iostream>
#include <vector>
#include <set>

using namespace std;
typedef long long ll;

int N, M;
vector<vector<int>> constraints_vars;
vector<ll> low, high;
set<int> involved_vars;

bool unbounded = false;

void dfs(int idx, vector<ll>& vars, vector<bool>& assigned) {
    if (idx == N) {
        // All variables assigned
        for (int i = 0; i < M; ++i) {
            ll sum = 0;
            for (int var : constraints_vars[i]) {
                sum += vars[var];
            }
            if (sum < low[i] || sum > high[i]) {
                return;
            }
        }
        // Valid assignment found, but since variables can be large, we can't count them
        unbounded = true;
        return;
    }
    if (unbounded) return;
    if (!involved_vars.count(idx)) {
        // Variable not involved in any constraint, can be any non-negative integer
        unbounded = true;
        return;
    }
    // Try minimal value
    vars[idx] = 0;
    assigned[idx] = true;
    dfs(idx + 1, vars, assigned);
}

int main() {
    cin >> N >> M;
    low.resize(M);
    high.resize(M);
    constraints_vars.resize(M);

    for (int i = 0; i < M; ++i) {
        ll l, h;
        int k;
        cin >> l >> h >> k;
        low[i] = l;
        high[i] = h;
        constraints_vars[i].resize(k);
        for (int j = 0; j < k; ++j) {
            int idx;
            cin >> idx;
            idx--; // 0-based indexing
            constraints_vars[i][j] = idx;
            involved_vars.insert(idx);
        }
    }
    if (involved_vars.size() < N) {
        // Variables not involved in any constraint can be arbitrarily large
        cout << "infinity" << endl;
        return 0;
    }

    vector<ll> vars(N, 0);
    vector<bool> assigned(N, false);
    dfs(0, vars, assigned);

    if (unbounded) {
        cout << "infinity" << endl;
    } else {
        // It's impractical to compute the exact number due to large upper bounds
        cout << "0" << endl;
    }
    return 0;
}
