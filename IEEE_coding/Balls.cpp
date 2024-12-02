#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

long long lcm(long long a, long long b) {
    return (a / __gcd(a, b)) * b;
}

long long countTilesHit(long long N, const vector<int>& elasticities) {
    int K = elasticities.size();
    long long result = 0;
    
    // Use inclusion-exclusion principle to count the number of tiles hit
    for (int mask = 1; mask < (1 << K); ++mask) {
        long long lcm_val = 1;
        int bits = 0;
        for (int i = 0; i < K; ++i) {
            if (mask & (1 << i)) {
                lcm_val = lcm(lcm_val, elasticities[i]);
                if (lcm_val > N) break; // If lcm exceeds N, no need to continue
                ++bits;
            }
        }
        if (lcm_val > N) continue;
        
        long long count = N / lcm_val;
        if (bits % 2 == 1) {
            result += count;
        } else {
            result -= count;
        }
    }
    
    return result;
}

int main() {
    long long N;
    int K;
    cin >> N >> K;
    vector<int> elasticities(K);
    for (int i = 0; i < K; ++i) {
        cin >> elasticities[i];
    }
    
    cout << countTilesHit(N, elasticities) << endl;
    return 0;
}
