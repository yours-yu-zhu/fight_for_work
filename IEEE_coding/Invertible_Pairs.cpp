#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int maxSubarraySum(const vector<int>& arr) {
    int max_so_far = INT_MIN, max_ending_here = 0;
    for (int x : arr) {
        max_ending_here = max(x, max_ending_here + x);
        max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;
}

void solveTestCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int& x : A) cin >> x;
    int numPairs = N / 2;
    int maxSum = INT_MIN;
    for (int mask = 0; mask < (1 << numPairs); ++mask) {
        vector<int> B = A;
        for (int i = 0; i < numPairs; ++i) {
            if (mask & (1 << i)) {
                B[2 * i] = -B[2 * i];
                B[2 * i + 1] = -B[2 * i + 1];
            }
        }
        int currentMax = maxSubarraySum(B);
        maxSum = max(maxSum, currentMax);
    }
    cout << maxSum << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solveTestCase();
    }
    return 0;
}