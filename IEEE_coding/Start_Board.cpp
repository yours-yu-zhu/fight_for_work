#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Edge
{
    int to, next;
};

vector<Edge> edges;
vector<int> head;
vector<int> ns;
int ans = 0;

void addEdge(int u, int v)
{
    edges.push_back({v, head[u]});
    head[u] = edges.size() - 1;
}

void addBiEdge(int u, int v)
{
    addEdge(u, v);
    addEdge(v, u);
}

void updatePaths(vector<int> &primary, const vector<int> &secondary)
{
    if (primary.size() < secondary.size())
        primary.resize(secondary.size(), INT_MAX);
    for (size_t i = 0; i < secondary.size(); ++i)
        primary[i] = min(primary[i], secondary[i]);
}

void calculateMaxPath(const vector<int> &up, const vector<int> &down, int value)
{
    for (size_t i = 0; i < up.size(); ++i)
    {
        auto pos = lower_bound(down.begin(), down.end(), -up[i]);
        ans = max(ans, static_cast<int>(i + 1 + distance(down.begin(), pos)));
    }
    for (size_t i = 0; i < down.size(); ++i)
    {
        auto pos = lower_bound(up.begin(), up.end(), -down[i]);
        ans = max(ans, static_cast<int>(i + 1 + distance(up.begin(), pos)));
    }
    auto posUp = lower_bound(up.begin(), up.end(), value);
    auto posDown = lower_bound(down.begin(), down.end(), -value);
    ans = max(ans, static_cast<int>(distance(up.begin(), posUp) + distance(down.begin(), posDown) + 1));
}

void dfs(int v, int parent, vector<int> &up, vector<int> &down)
{
    for (int i = head[v]; i != -1; i = edges[i].next)
    {
        int u = edges[i].to;
        if (u != parent)
        {
            vector<int> upSub, downSub;
            dfs(u, v, upSub, downSub);

            calculateMaxPath(upSub, down, ns[v]);
            calculateMaxPath(up, downSub, ns[v]);

            updatePaths(up, upSub);
            updatePaths(down, downSub);
        }
    }

    if (up.empty() || up.back() < ns[v])
        up.push_back(ns[v]);
    else
        *lower_bound(up.begin(), up.end(), ns[v]) = ns[v];

    if (down.empty() || down.back() < -ns[v])
        down.push_back(-ns[v]);
    else
        *lower_bound(down.begin(), down.end(), -ns[v]) = -ns[v];
}

int main()
{
    int n;
    cin >> n;
    ns.resize(n + 1);
    head.assign(n + 1, -1);
    edges.reserve(2 * n);

    for (int i = 1; i <= n; ++i)
        cin >> ns[i];

    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        addBiEdge(u, v);
    }

    vector<int> up, down;
    dfs(1, 0, up, down);

    cout << ans << endl;
    return 0;
}
