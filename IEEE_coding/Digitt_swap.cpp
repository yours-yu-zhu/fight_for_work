#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string max_num = "";

unordered_set<string> visited;

void backtrack(string &num, int K, int idx) {
    if(num > max_num){
        max_num = num;
    }
    
    if(K == 0){
        return;
    }
    
    int n = num.size();
    
    char current_max = '0';
    for(int i = idx; i < n; i++) {
        if(num[i] > current_max){
            current_max = num[i];
        }
    }
    
    if(num[idx] == current_max){
        backtrack(num, K, idx + 1);
        return;
    }
    
    for(int i = n - 1; i >= idx; i--){
        if(num[i] == current_max){
            swap(num[idx], num[i]);
            
            string state = num + to_string(K - 1) + to_string(idx + 1);
            
            if(visited.find(state) == visited.end()){
                visited.insert(state);
                backtrack(num, K - 1, idx + 1);
            }
            
            swap(num[idx], num[i]);
        }
    }
}

int main(){
    string N;
    int K;
    cin >> N >> K;
    
    max_num = N; 
    
    backtrack(N, K, 0);
    
    if(max_num[0] == '0'){
        cout << -1;
    }
    else{
        cout << max_num;
    }
}
