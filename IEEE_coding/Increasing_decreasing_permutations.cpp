#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll factorial_mod(int n, ll M){
    ll fact = 1;
    for(int i=2;i<=n;i++) {
        fact = (fact * i) % M;
    }
    return fact;
}

int main(){
    int N;
    ll M;
    cin >> N >> M;
    
    int K = (N +1)/2;
    
    ll sum_distance =0;
    for(int i=1;i<=N;i++) {
        sum_distance += abs(i - K);
    }
    
    ll fact = 1;
    for(int i=2;i<=N-1;i++) {
        fact = (fact * i) % M;
    }
    
    ll total_swaps = (fact * sum_distance) % M;
    
    cout << total_swaps;
}
