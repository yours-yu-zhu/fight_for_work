#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <limits.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n,vector<int>(n));
        vector<vector<int>> derection = {{0,1},{1,0},{0,-1},{-1,0}};

        int i = 0,j = 0,k = 1,d = 0;
        while(k <= n*n){
            result[i][j] = k;
            k++;
            int next_i = i + derection[d][0], next_j = j + derection[d][1];
            if(next_i < 0 || next_i >= n || next_j < 0 || next_j >= n || result[next_i][next_j] != 0){
                d = (d + 1 ) % 4;
            }
            i = i + derection[d][0], j = j + derection[d][1];
        }
        return result;
    }
};

int main() {
    int target = 7;
    Solution a ;
    vector<vector<int>> result =  a.generateMatrix(3);
    for(int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[0].size();j++)
        {
            cout<<result[i][j];
        }
    }
    return 0;
}
