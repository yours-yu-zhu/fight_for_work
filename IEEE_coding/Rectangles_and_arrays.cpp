#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int maxHistogramArea(const vector<int>& heights) {
    int n = heights.size();
    stack<int> s;
    int max_area = 0;
    int i = 0;
    while (i < n) {
        if (s.empty() || heights[s.top()] <= heights[i]) {
            s.push(i++);
        } else {
            int top = s.top();
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            max_area = max(max_area, heights[top] * width);
        }
    }
    while (!s.empty()) {
        int top = s.top();
        s.pop();
        int width = s.empty() ? i : i - s.top() - 1;
        max_area = max(max_area, heights[top] * width);
    }
    return max_area;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    int original_max_area = maxHistogramArea(A);

    int modified_max_area = original_max_area;

    for (int i = 0; i < n; ++i) {
        int original_value = A[i];
        A[i] = x;
        modified_max_area = max(modified_max_area, maxHistogramArea(A));
        A[i] = original_value; 
    }

    cout << modified_max_area << endl;

    return 0;
}
