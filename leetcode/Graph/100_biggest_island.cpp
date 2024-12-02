#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int count = 0;
int direction[4][2] = {0, 1, 1, 0, -1, 0, 0, -1}; // 四个方向

void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y){
    queue<pair<int ,int>> que;
    que.push({x, y});
    visited[x][y] = true;
    ++count;
    while(!que.empty()){
        pair<int ,int> cur = que.front();
        que.pop();
        for(int i = 0; i < 4; ++i){
            int next_x = cur.first + direction[i][0];
            int next_y = cur.second + direction[i][1];
            if(next_x < 0 || next_y < 0 || next_x >= grid.size() || next_y >= grid[0].size()) continue;
            if(!visited[next_x][next_y] && grid[next_x][next_y] == 1){
                visited[next_x][next_y] = true;
                ++count;
                que.push({next_x, next_y});
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
            if (!visited[i][j] && grid[i][j] == 1){
                count = 0;
                bfs(grid, visited, i, j);
                result = result > count ? result : count;                
            }

        }
    } 
    cout << result;
}