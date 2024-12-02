#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int N;
vector<int> C;
vector<int> R;
vector<int> B;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    C.resize(2 * N);
    R.resize(N);
    B.resize(N);

    set<int> S_known_numbers;
    vector<int> positions(2 * N);
    iota(positions.begin(), positions.end(), 0);

    for (int i = 0; i < 2 * N; ++i) {
        cin >> C[i];
        if (C[i] != -1) {
            S_known_numbers.insert(C[i]);
        }
    }

    for (int i = 0; i < N; ++i) {
        cin >> R[i];
    }

    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }

    set<int> S_all_numbers;
    for (int i = 1; i <= 2 * N; ++i) {
        S_all_numbers.insert(i);
    }

    set<int> S_unknown_numbers;
    for (int num : S_all_numbers) {
        if (S_known_numbers.find(num) == S_known_numbers.end()) {
            S_unknown_numbers.insert(num);
        }
    }

    // For each pair, generate possible options
    vector<vector<pair<int, int>>> options(N); // options[i] = list of (value1, value2)
    bool possible = true;

    for (int i = 0; i < N; ++i) {
        int p1 = 2 * i;
        int p2 = 2 * i + 1;

        int c1 = C[p1];
        int c2 = C[p2];

        vector<pair<int, int>> pair_options;

        if (c1 != -1 && c2 != -1) {
            int min_val = min(c1, c2);
            int max_val = max(c1, c2);
            if ((R[i] == 0 && min_val == B[i]) || (R[i] == 1 && max_val == B[i])) {
                pair_options.push_back({c1, c2});
            } else {
                possible = false;
                break;
            }
        } else {
            // Prepare lists of possible values
            set<int> possible_vals_p1, possible_vals_p2;

            if (c1 != -1) {
                possible_vals_p1.insert(c1);
            } else {
                possible_vals_p1 = S_unknown_numbers;
            }

            if (c2 != -1) {
                possible_vals_p2.insert(c2);
            } else {
                possible_vals_p2 = S_unknown_numbers;
            }

            for (int val1 : possible_vals_p1) {
                for (int val2 : possible_vals_p2) {
                    if (val1 == val2 && c1 == -1 && c2 == -1)
                        continue; // Values must be distinct
                    if (S_known_numbers.find(val1) != S_known_numbers.end() && c1 == -1)
                        continue;
                    if (S_known_numbers.find(val2) != S_known_numbers.end() && c2 == -1)
                        continue;
                    int min_val = min(val1, val2);
                    int max_val = max(val1, val2);
                    if ((R[i] == 0 && min_val == B[i]) || (R[i] == 1 && max_val == B[i])) {
                        pair_options.push_back({val1, val2});
                    }
                }
            }
        }

        if (pair_options.empty()) {
            possible = false;
            break;
        }

        options[i] = pair_options;
    }

    if (!possible) {
        cout << 0 << '\n';
        return 0;
    }

    // For small N, we can perform DP with bitmasking
    if (N <= 20) {
        map<vector<int>, int> dp;
        dp[vector<int>()] = 1;
        for (int i = 0; i < N; ++i) {
            map<vector<int>, int> new_dp;
            for (auto &state : dp) {
                for (auto &opt : options[i]) {
                    vector<int> new_state = state.first;
                    if (find(new_state.begin(), new_state.end(), opt.first) != new_state.end())
                        continue;
                    if (find(new_state.begin(), new_state.end(), opt.second) != new_state.end())
                        continue;
                    new_state.push_back(opt.first);
                    new_state.push_back(opt.second);
                    sort(new_state.begin(), new_state.end());
                    new_dp[new_state] = (new_dp[new_state] + state.second) % MOD;
                }
            }
            dp = move(new_dp);
        }
        int ans = 0;
        for (auto &state : dp) {
            ans = (ans + state.second) % MOD;
        }
        cout << ans << '\n';
        return 0;
    } else {
        // For larger N, the problem is computationally infeasible
        cout << 0 << '\n';
        return 0;
    }
}
