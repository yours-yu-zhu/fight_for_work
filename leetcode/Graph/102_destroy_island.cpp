#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int direction[4][2] = {1,0,-1,0,0,1,0,-1};
int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y){
    int flag = 1;
    if(visited[x][y] || grid[x][y] == 0) return -1;
    if(x == 0 || x == grid.size() - 1 || y == 0 || y == grid[0].size() - 1) flag = 0;
    visited[x][y] = true;
    for(int i = 0; i < 4; ++i){
        int next_x = x + direction[i][0];
        int next_y = y + direction[i][1];
        if(next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size()) continue;
        if(dfs(grid, visited, next_x, next_y) == 0) flag = 0;
    }
    return flag;
    
}

bool bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y){
    bool flag = false;
    if(visited[x][y] || grid[x][y] == 0) return false;
    if(x == 0 || x == grid.size() - 1 || y == 0 || y == grid[0].size() - 1) flag = true;
    queue<pair<int, int>> que;
    que.push({x, y});
    visited[x][y] = true;
    while(!que.empty()){
        pair<int, int> cur = que.front();
        que.pop();
        for(int i = 0; i < 4; ++i){
            int next_x = cur.first + direction[i][0];
            int next_y = cur.second + direction[i][1];
            if(next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size()) continue;
            if(!visited[next_x][next_y] && grid[next_x][next_y] == 1){
                if(x == 0 || x == grid.size() - 1 || y == 0 || y == grid[0].size() - 1) flag = true;
                que.push({next_x, next_y});
                visited[next_x][next_y] = 1;
            }

        }
    }
    return flag;
}

void clear(vector<vector<int>>& grid, int x, int y){
    if(grid[x][y] == 0) return;
    grid[x][y] = 0;
    for(int i = 0; i < 4; ++i){
        int next_x = x + direction[i][0];
        int next_y = y + direction[i][1];
        if(next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size()) continue;
        clear(grid, next_x, next_y);
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
    
    // for(int i = 0; i < n; ++i){
    //     for(int j = 0; j < m; ++j){
    //       if(!visited[i][j] && grid[i][j] == 1){
    //           if(dfs(grid, visited, i, j) == 1) {
    //                 clear(grid, i, j);
    //           }
    //       }
    //     }
    // }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
          if(!visited[i][j] && grid[i][j] == 1){
              if(bfs(grid, visited, i, j) == false) {
                    clear(grid, i, j);
              }
          }
        }
    }
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cout << grid[i][j] << " ";        
        }
        cout << endl;
    }
    
}