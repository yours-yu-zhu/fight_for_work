#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

struct SegmentTree {
    struct Node {
        int l, r;
        long long sum;
        long long lazy;
    } tree[MAXN * 4];

    void push_up(int idx) {
        tree[idx].sum = tree[idx * 2].sum + tree[idx * 2 + 1].sum;
    }

    void push_down(int idx) {
        if (tree[idx].lazy) {
            long long lazyVal = tree[idx].lazy;
            tree[idx * 2].lazy += lazyVal;
            tree[idx * 2 + 1].lazy += lazyVal;
            tree[idx * 2].sum += (tree[idx * 2].r - tree[idx * 2].l + 1) * lazyVal;
            tree[idx * 2 + 1].sum += (tree[idx * 2 + 1].r - tree[idx * 2 + 1].l + 1) * lazyVal;
            tree[idx].lazy = 0;
        }
    }

    void build(int idx, int l, int r) {
        tree[idx].l = l;
        tree[idx].r = r;
        tree[idx].sum = 0;
        tree[idx].lazy = 0;
        if (l == r) {
            return;
        }
        int mid = (l + r) / 2;
        build(idx * 2, l, mid);
        build(idx * 2 + 1, mid + 1, r);
    }

    void update(int idx, int l, int r, long long val) {
        if (tree[idx].l > r || tree[idx].r < l) {
            return;
        }
        if (tree[idx].l >= l && tree[idx].r <= r) {
            tree[idx].sum += (tree[idx].r - tree[idx].l + 1) * val;
            tree[idx].lazy += val;
            return;
        }
        push_down(idx);
        update(idx * 2, l, r, val);
        update(idx * 2 + 1, l, r, val);
        push_up(idx);
    }

    long long query(int idx, int l, int r) {
        if (tree[idx].l > r || tree[idx].r < l) {
            return 0;
        }
        if (tree[idx].l >= l && tree[idx].r <= r) {
            return tree[idx].sum;
        }
        push_down(idx);
        long long res = query(idx * 2, l, r) + query(idx * 2 + 1, l, r);
        push_up(idx);
        return res;
    }
};

int N, Q;
int P[MAXN];
SegmentTree segTree;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;
    for (int i = 1; i <= N; ++i) {
        cin >> P[i];
    }

    segTree.build(1, 1, N);

    for (int q = 0; q < Q; ++q) {
        int type;
        cin >> type;
        if (type == 0) {
            int l, r, c;
            cin >> l >> r >> c;
            segTree.update(1, l, r, c);
        } else if (type == 1) {
            int l, r, c;
            cin >> l >> r >> c;
            vector<int> positions;
            for (int i = l; i <= r; ++i) {
                positions.push_back(P[i]);
            }
            sort(positions.begin(), positions.end());
            for (size_t i = 0; i < positions.size();) {
                int start = positions[i];
                int end = start;
                while (i + 1 < positions.size() && positions[i + 1] == positions[i] + 1) {
                    ++i;
                    end = positions[i];
                }
                segTree.update(1, start, end, c);
                ++i;
            }
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;
            cout << segTree.query(1, l, r) << '\n';
        } else if (type == 3) {
            int l, r;
            cin >> l >> r;
            vector<int> positions;
            for (int i = l; i <= r; ++i) {
                positions.push_back(P[i]);
            }
            sort(positions.begin(), positions.end());
            long long total = 0;
            for (size_t i = 0; i < positions.size();) {
                int start = positions[i];
                int end = start;
                while (i + 1 < positions.size() && positions[i + 1] == positions[i] + 1) {
                    ++i;
                    end = positions[i];
                }
                total += segTree.query(1, start, end);
                ++i;
            }
            cout << total << '\n';
        }
    }

    return 0;
}
