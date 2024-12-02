#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
#include <queue>

using namespace std;

struct Point {
    int x, y;
};

double distance(const Point& a, const Point& b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
    int N;
    cin >> N;
    vector<Point> points(N);
    for (int i = 0; i < N; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    vector<bool> used(N, false);
    vector<vector<int>> bestGrouping;

    for (int i = 0; i < N / 3; ++i) {
        double bestStability = numeric_limits<double>::max();
        vector<int> bestGroup;

        for (int a = 0; a < N; ++a) {
            if (used[a]) continue;
            for (int b = a + 1; b < N; ++b) {
                if (used[b]) continue;
                for (int c = b + 1; c < N; ++c) {
                    if (used[c]) continue;

                    double d1 = distance(points[a], points[b]);
                    double d2 = distance(points[a], points[c]);
                    double d3 = distance(points[b], points[c]);
                    double stability = max({d1, d2, d3}) - min({d1, d2, d3});

                    if (stability < bestStability) {
                        bestStability = stability;
                        bestGroup = {a, b, c};
                    }
                }
            }
        }

        for (int idx : bestGroup) {
            used[idx] = true;
        }
        bestGrouping.push_back(bestGroup);
    }

    for (const auto& group : bestGrouping) {
        cout << group[0] << " " << group[1] << " " << group[2] << "\n";
    }

    return 0;
}