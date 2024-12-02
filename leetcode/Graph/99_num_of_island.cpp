#include <iostream>
#include <vector>
#include <queue>
// #include <utility>
using namespace std;
int direction[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y){
    queue<pair<int, int>> que;
    que.push({x, y});
    while(!que.empty()){
        pair<int, int> cur = que.front();
        que.pop();
        visited[cur.first][cur.second] = true;
        for(int i = 0; i < 4; ++i){
            int next_x = cur.first + direction[i][0];
            int next_y = cur.second + direction[i][1];
                        
            if(next_x < 0 || next_x >= grid.size() || next_y >= grid[0].size() || next_y < 0) continue;
            if(!visited[next_x][next_y] && grid[next_x][next_y] == 1){
                que.push({next_x, next_y});
                visited[next_x][next_y] = true;
            }
        }
    }
}

int main(){
    int m, n;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> grid[i][j];
        }
    }
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int result = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(!visited[i][j] && grid[i][j] == 1){
                ++result;
                bfs(grid, visited, i, j);
            }
        }
    }  
    cout << result;
}