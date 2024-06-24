#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k0, k1;
    cin >> n >> m >> k0 >> k1;

    vector<vector<int>> reverseFromEntertainments(m);
    vector<vector<int>> reverseFromRestaurants(n);

    // 读取并构建逆向图
    for (int i = 0; i < k0; ++i) {
        int xi, yi;
        cin >> xi >> yi;
        reverseFromEntertainments[yi].push_back(xi);
    }

    for (int i = 0; i < k1; ++i) {
        int xi, yi;
        cin >> xi >> yi;
        reverseFromRestaurants[yi].push_back(xi);
    }

    int ns, ms;
    cin >> ns >> ms;
    vector<bool> safeRestaurants(n, false), safeEntertainments(m, false);
    vector<bool> reachableRestaurants(n, false), reachableEntertainments(m, false);

    // 标记安全的餐厅和娱乐设施
    for (int i = 0; i < ns; ++i) {
        int idx;
        cin >> idx;
        safeRestaurants[idx] = true;
        reachableRestaurants[idx] = true;  // 从安全餐厅开始可以访问
    }
    for (int i = 0; i < ms; ++i) {
        int idx;
        cin >> idx;
        safeEntertainments[idx] = true;
        reachableEntertainments[idx] = true;  // 从安全娱乐设施开始可以访问
    }

    queue<int> q;
    // BFS从安全的餐厅开始
    for (int i = 0; i < n; ++i) {
        if (safeRestaurants[i]) {
            q.push(i);
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                for (int next : reverseFromRestaurants[curr]) {
                    if (!reachableEntertainments[next] && safeEntertainments[next]) {
                        reachableEntertainments[next] = true;
                        q.push(next);
                    }
                }
            }
        }
    }

    // BFS从安全的娱乐设施开始
    for (int i = 0; i < m; ++i) {
        if (safeEntertainments[i]) {
            q.push(i);
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                for (int next : reverseFromEntertainments[curr]) {
                    if (!reachableRestaurants[next] && safeRestaurants[next]) {
                        reachableRestaurants[next] = true;
                        q.push(next);
                    }
                }
            }
        }
    }

    // 输出结果
    vector<int> ansRestaurants, ansEntertainments;
    for (int i = 0; i < n; ++i) {
        if (reachableRestaurants[i]) ansRestaurants.push_back(i);
    }
    for (int i = 0; i < m; ++i) {
        if (reachableEntertainments[i]) ansEntertainments.push_back(i);
    }

    cout << ansRestaurants.size() << " " << ansEntertainments.size() << endl;
    for (int r : ansRestaurants) cout << r << " ";
    cout << endl;
    for (int e : ansEntertainments) cout << e << " ";
    cout << endl;

    return 0;
}