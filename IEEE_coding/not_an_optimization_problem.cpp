#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int MAX = 200005;

// 快速幂计算 a^b % mod
ll power_pow(ll a, ll b, ll mod_val) {
    ll res = 1;
    a %= mod_val;
    while(b > 0){
        if(b & 1LL) res = res * a % mod_val;
        a = a * a % mod_val;
        b >>=1LL;
    }
    return res;
}

ll fact[MAX], inv_fact_arr[MAX];

// 预计算阶乘和逆阶乘
void precompute_fact(){
    fact[0] = 1;
    for(int i=1;i<MAX;i++) fact[i] = fact[i-1] * i % MOD;
    inv_fact_arr[MAX-1] = power_pow(fact[MAX-1], MOD-2, MOD);
    for(int i=MAX-2;i>=0;i--) inv_fact_arr[i] = inv_fact_arr[i+1] * (i+1) % MOD;
}

// 计算组合数 C(n, k) % MOD
ll comb(int n, int k){
    if(n < k) return 0;
    return fact[n] * inv_fact_arr[k] % MOD * inv_fact_arr[n - k] % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    precompute_fact();
    
    int N;
    cin >> N;
    vector<ll> W(N+1, 0);
    for(int i=1;i<=N;i++) cin >> W[i];
    
    // 建立树的邻接表
    vector<vector<int>> adj(N+1, vector<int>());
    vector<pair<int, int>> edges;
    for(int i=1;i<N;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.emplace_back(u, v);
    }
    
    // 将树根设为节点1，并计算每个子树的大小
    vector<int> size_subtree(N+1, 1);
    vector<int> parent(N+1, 0);
    stack<int> s;
    s.push(1);
    parent[1] = -1;
    // 使用DFS遍历树
    while(!s.empty()){
        int u = s.top();
        s.pop();
        for(auto &v: adj[u]){
            if(parent[v] == 0){
                parent[v] = u;
                s.push(v);
            }
        }
    }
    
    // 从后向前计算子树大小
    for(int u=N; u>=1; u--){
        if(parent[u] != -1){
            size_subtree[parent[u]] += size_subtree[u];
        }
    }
    
    // 对每条边，确定其贡献
    vector<pair<ll, int>> edge_info; // {W_u, size_v}
    for(auto &[u, v]: edges){
        if(parent[u] == v){
            // u是子节点
            edge_info.emplace_back(W[v], size_subtree[u]);
        }
        else{
            // v是子节点
            edge_info.emplace_back(W[u], size_subtree[v]);
        }
    }
    
    // 频率数组 freq[n] = sum of W_u for edges with size_v = n
    vector<ll> freq(N+1, 0);
    for(auto &[w, sz]: edge_info){
        if(sz <= N){
            freq[sz] = (freq[sz] + w) % MOD;
        }
    }
    
    // 计算所有节点权重之和
    ll sum_W =0;
    for(int i=1;i<=N;i++) sum_W = (sum_W + W[i]) % MOD;
    
    // 计算 P(k) = sum(freq[n] * C(n, k)) for all n
    vector<ll> P(N+1, 0);
    
    for(int n=0;n<=N;n++){
        if(freq[n]==0) continue;
        // 计算 C(n, k) 并累加到 P[k]
        ll Cnk =1;
        for(int k=0;k<=n;k++){
            P[k] = (P[k] + freq[n] * Cnk) % MOD;
            if(k <n){
                Cnk = Cnk * (n -k) % MOD;
                Cnk = Cnk * power_pow(k+1, MOD-2, MOD) % MOD;
            }
        }
    }
    
    // 预计算 C(N, k) for all k
    vector<ll> Cnk_all(N+1, 0);
    for(int k=0;k<=N;k++) Cnk_all[k] = comb(N, k);
    
    // 计算并输出每个 k 的答案
    for(int k=1;k<=N;k++){
        ll ans = (Cnk_all[k] * sum_W % MOD - P[k] + MOD) % MOD;
        cout << ans << "\n";
    }
    
    return 0;
}
