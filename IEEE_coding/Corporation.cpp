#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Maximum size for the segment tree
const int MAX = 800000;

// Segment tree arrays
ll sum_salary_tree[MAX];
ll sum_happiness_tree[MAX];
ll min_salary_tree[MAX];
ll max_salary_tree[MAX];
bool has_set_lazy[MAX];
ll set_val_lazy[MAX];
ll add_val_lazy_tree[MAX];

// Initial salary array
ll initial_salary_arr[200005];

// Function to compute GCD
ll compute_gcd(ll a, ll b){
    return b == 0 ? a : compute_gcd(b, a % b);
}

// Function to reduce fraction to its simplest form
pair<ll, ll> reduce_fraction(ll p, ll q){
    if(q < 0){
        p = -p;
        q = -q;
    }
    if(p == 0){
        return {0, 1};
    }
    ll g = compute_gcd(abs(p), abs(q));
    return {p / g, q / g};
}

// Function to push up the values from children to parent
void push_up(int node){
    sum_salary_tree[node] = sum_salary_tree[node*2] + sum_salary_tree[node*2+1];
    sum_happiness_tree[node] = sum_happiness_tree[node*2] + sum_happiness_tree[node*2+1];
    min_salary_tree[node] = min(min_salary_tree[node*2], min_salary_tree[node*2+1]);
    max_salary_tree[node] = max(max_salary_tree[node*2], max_salary_tree[node*2+1]);
}

// Function to apply set operation to a node
void apply_set(int node, int l, int r, ll c){
    if(l == r){
        // Leaf node: Update happiness based on salary change
        if(c > sum_salary_tree[node]){
            sum_happiness_tree[node] += 1;
        }
        else if(c < sum_salary_tree[node]){
            sum_happiness_tree[node] -= 1;
        }
        // If c == current salary, no change to happiness
    }
    // Apply the set operation
    sum_salary_tree[node] = (r - l + 1) * c;
    min_salary_tree[node] = c;
    max_salary_tree[node] = c;
    has_set_lazy[node] = true;
    set_val_lazy[node] = c;
    add_val_lazy_tree[node] = 0;
}

// Function to apply add operation to a node
void apply_add(int node, int l, int r, ll c){
    if(l == r){
        // Leaf node: Update happiness based on salary change
        if(c > 0){
            sum_happiness_tree[node] += 1;
        }
        else if(c < 0){
            sum_happiness_tree[node] -= 1;
        }
        // If c == 0, no change to happiness
    }
    else{
        // Internal node: All employees in range have their salary increased or decreased
        if(c > 0){
            sum_happiness_tree[node] += (r - l + 1);
        }
        else if(c < 0){
            sum_happiness_tree[node] -= (r - l + 1);
        }
    }
    // Apply the add operation
    sum_salary_tree[node] += (r - l + 1) * c;
    min_salary_tree[node] += c;
    max_salary_tree[node] += c;

    if(has_set_lazy[node]){
        set_val_lazy[node] += c;
    }
    else{
        add_val_lazy_tree[node] += c;
    }
}

// Function to push down the lazy updates to children
void push_down(int node, int l, int r){
    if(has_set_lazy[node]){
        int mid = (l + r) / 2;
        // Apply set to left child
        apply_set(node*2, l, mid, set_val_lazy[node]);
        // Apply set to right child
        apply_set(node*2+1, mid+1, r, set_val_lazy[node]);
        has_set_lazy[node] = false;
    }
    if(add_val_lazy_tree[node] != 0){
        int mid = (l + r) / 2;
        // Apply add to left child
        apply_add(node*2, l, mid, add_val_lazy_tree[node]);
        // Apply add to right child
        apply_add(node*2+1, mid+1, r, add_val_lazy_tree[node]);
        add_val_lazy_tree[node] = 0;
    }
}

// Function to build the segment tree
void build(int node, int l, int r){
    if(l == r){
        sum_salary_tree[node] = initial_salary_arr[l];
        sum_happiness_tree[node] = 0;
        min_salary_tree[node] = initial_salary_arr[l];
        max_salary_tree[node] = initial_salary_arr[l];
        has_set_lazy[node] = false;
        set_val_lazy[node] = 0;
        add_val_lazy_tree[node] = 0;
        return;
    }
    int mid = (l + r) / 2;
    build(node*2, l, mid);
    build(node*2+1, mid+1, r);
    push_up(node);
}

// Function to perform range set operation
void range_set_op(int node, int l, int r, int a, int b, ll c){
    if(b < l || a > r){
        return;
    }
    if(a <= l && r <= b){
        if(c > max_salary_tree[node]){
            // All salaries will increase
            if(l != r){
                // Internal node: Update happiness without affecting sum_happiness_tree[node] directly
                apply_add(node, l, r, 0); // Dummy operation to handle internal nodes
                // Instead, handle happiness updates in apply_set
            }
            // Apply set operation
            apply_set(node, l, r, c);
        }
        else if(c < min_salary_tree[node]){
            // All salaries will decrease
            if(l != r){
                // Internal node: Update happiness without affecting sum_happiness_tree[node] directly
                apply_add(node, l, r, 0); // Dummy operation to handle internal nodes
            }
            // Apply set operation
            apply_set(node, l, r, c);
        }
        else{
            // Mixed: Need to split further
            if(l != r){
                push_down(node, l, r);
                int mid = (l + r) / 2;
                range_set_op(node*2, l, mid, a, b, c);
                range_set_op(node*2+1, mid+1, r, a, b, c);
                push_up(node);
            }
            else{
                // Leaf node: No change in happiness if c == current salary
                // Otherwise, already handled in apply_set
                apply_set(node, l, r, c);
            }
        }
        return;
    }
    push_down(node, l, r);
    int mid = (l + r) / 2;
    range_set_op(node*2, l, mid, a, b, c);
    range_set_op(node*2+1, mid+1, r, a, b, c);
    push_up(node);
}

// Function to perform range add operation
void range_add_op(int node, int l, int r, int a, int b, ll c){
    if(b < l || a > r){
        return;
    }
    if(a <= l && r <= b){
        // Apply happiness updates based on c
        apply_add(node, l, r, c);
        return;
    }
    push_down(node, l, r);
    int mid = (l + r) / 2;
    range_add_op(node*2, l, mid, a, b, c);
    range_add_op(node*2+1, mid+1, r, a, b, c);
    push_up(node);
}

// Function to query sum of salaries in range
ll query_sum_salary(int node, int l, int r, int a, int b){
    if(b < l || a > r){
        return 0;
    }
    if(a <= l && r <= b){
        return sum_salary_tree[node];
    }
    push_down(node, l, r);
    int mid = (l + r) / 2;
    return query_sum_salary(node*2, l, mid, a, b) + query_sum_salary(node*2+1, mid+1, r, a, b);
}

// Function to query sum of happiness in range
ll query_sum_happiness(int node, int l, int r, int a, int b){
    if(b < l || a > r){
       	return 0;
    }
    if(a <= l && r <= b){
        return sum_happiness_tree[node];
    }
    push_down(node, l, r);
    int mid = (l + r) / 2;
    return query_sum_happiness(node*2, l, mid, a, b) + query_sum_happiness(node*2+1, mid+1, r, a, b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    for(int i=1;i<=N;i++) cin >> initial_salary_arr[i];
    build(1, 1, N);
    while(Q--){
        int type;
        cin >> type;
        if(type == 0){
            int l, r;
            ll c;
            cin >> l >> r >> c;
            range_set_op(1, 1, N, l, r, c);
        }
        else if(type ==1){
            int l, r;
            ll c;
            cin >> l >> r >> c;
            range_add_op(1, 1, N, l, r, c);
        }
        else if(type ==2){
            int l, r;
            cin >> l >> r;
            ll total_salary = query_sum_salary(1, 1, N, l, r);
            int count = r - l +1;
            pair<ll, ll> frac = reduce_fraction(total_salary, (ll)count);
            cout << frac.first << "/" << frac.second << "\n";
        }
        else if(type ==3){
            int l, r;
            cin >> l >> r;
            ll total_happiness = query_sum_happiness(1, 1, N, l, r);
            int count = r - l +1;
            pair<ll, ll> frac = reduce_fraction(total_happiness, (ll)count);
            cout << frac.first << "/" << frac.second << "\n";
        }
    }
}
