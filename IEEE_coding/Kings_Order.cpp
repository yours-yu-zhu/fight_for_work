#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Project {
    int id;
    int group;

    Project(int id, int group) : id(id), group(group) {}
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> group(N + 1);
    vector<vector<int>> adj(N + 1);
    vector<int> indegree(N + 1, 0);

    // Read group ID for each project
    for (int i = 1; i <= N; ++i) {
        cin >> group[i];
    }

    // Read dependencies
    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        indegree[B]++;
    }

    // Custom comparator for priority queue based on group ID and project ID
    auto cmp = [&](int a, int b) {
        if (group[a] == group[b]) {
            return a > b;
        }
        return group[a] > group[b];
    };

    // Min-heap priority queue
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

    // Add all projects with zero indegree to the queue
    for (int i = 1; i <= N; ++i) {
        if (indegree[i] == 0) {
            pq.push(i);
        }
    }

    vector<int> result;

    while (!pq.empty()) {
        int curr = pq.top();
        pq.pop();
        result.push_back(curr);

        for (int neighbor : adj[curr]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                pq.push(neighbor);
            }
        }
    }

    // Check if we have processed all projects
    if (result.size() != N) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << (i == result.size() - 1 ? "\n" : " ");
        }
    }

    return 0;
}
