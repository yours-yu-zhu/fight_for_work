#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    while (Q--) {
        int L, R, K;
        cin >> L >> R >> K;
        L--;
        R--;
        
        if (K > 0 && K <= R - L + 1) {
            vector<int> subarray(A.begin() + L, A.begin() + R + 1);
            nth_element(subarray.begin(), subarray.begin() + K - 1, subarray.end());
            int kth_smallest = subarray[K - 1];
            
            int count = 0;
            for (int num : subarray) {
                if (num == kth_smallest) {
                    count++;
                }
            }
            
            if (count == 1) {
                cout << kth_smallest << "\n";
            } else {
                cout << "Not Found\n";
            }
        } else {
            cout << "Not Found\n";
        }
    }
    
    return 0;
}
