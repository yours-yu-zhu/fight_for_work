#include <iostream>
#include <vector>
using namespace std;

// Function to determine the color of a point at coordinates (x, y)
int getColor(long long x, long long y) {
    while (x > 1) {
        long long mid = (x + 1) / 2;
        if (y == mid) {
            return 0; // Blue point
        } else if (y > mid) {
            y = x + 1 - y;
        }
        x = mid;
    }
    return 1; // Red point
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int Q;
    cin >> Q;
    while (Q--) {
        long long x, y;
        cin >> x >> y;
        cout << getColor(x, y) << "\n";
    }
    
    return 0;
}