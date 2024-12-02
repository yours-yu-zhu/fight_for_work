#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int count = 0;
int direction[4][2] = {1,0,-1,0,0,1,0,-1};
int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y){
    int flag = 1;
    if(visited[x][y] || grid[x][y] == 0) return -1;
    if(x == 0 || x == grid.size() - 1 || y == 0 || y == grid[0].size() - 1) flag = 0;
    visited[x][y] = true;
    ++count;
    for(int i = 0; i < 4; ++i){
        int next_x = x + direction[i][0];
        int next_y = y + direction[i][1];
        if(next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size()) continue;
        if(dfs(grid, visited, next_x, next_y) == 0) flag = 0;
    }
    return flag;
}

bool bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y){
    bool flag = true;
    if(visited[x][y] || grid[x][y] == 0) return false;
    if(x == 0 || x == grid.size() - 1 || y == 0 || y == grid[0].size() - 1) flag = false;
    queue<pair<int, int>> que;
    que.push({x, y});
    visited[x][y] = true;
    ++count;
    while(!que.empty()){
        pair<int, int> cur = que.front();
        que.pop();
        for(int i = 0; i < 4; ++i){
            int next_x = cur.first + direction[i][0];
            int next_y = cur.second + direction[i][1];
            if(next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size()) continue;
            if(!visited[next_x][next_y] && grid[next_x][next_y] == 1){
                if(next_x == 0 || next_x == grid.size() - 1 || next_y == 0 || next_y == grid[0].size() - 1) flag = false;
                que.push({next_x, next_y});
                ++count;
                visited[next_x][next_y] = 1;
            }
        }
    }
    return flag;

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
    // *****bfs****
    // for(int i = 0; i < n; ++i){
    //     for(int j = 0; j < m; ++j){
    //        if(!visited[i][j] && grid[i][j] == 1){
    //            count = 0;
    //            if(dfs(grid, visited, i, j) == 1) {
    //                 result += count;
    //            }
    //        }
    //     }
    // }

    // *****dfs****
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(!visited[i][j] && grid[i][j] == 1){
                count = 0;
                if(bfs(grid, visited, i, j)) result += count;
            }
        }
    }
    cout << result;
}