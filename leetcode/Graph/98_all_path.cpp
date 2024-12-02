#include <iostream>
#include <vector>

using namespace std;
vector<int> path;
vector<vector<int>> result;

void dfs(vector<vector<int>> &graph, int x, int n){
    if(x == n){
        result.push_back(path);
        return;
    }
    for(int i = 1; i <= n; ++i){
        if(graph[x][i] == 1){
            path.push_back(i);
            dfs(graph, i, n);
            path.pop_back();
        }
    }
}

int main(){
    int m, n;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
    while(m--){
        int s, t;
        cin >> s >> t;
        graph[s][t] = 1;
    }
    //cout graph
    path.push_back(1);
    dfs(graph, 1, n);
    
    for(auto a : result){
        for(auto b : a){
            cout << b << ' ';
        }
        cout << endl;
    }
    
    
}