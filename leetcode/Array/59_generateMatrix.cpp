#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int count = 1;
        int offset = 1;
        int startX = 0;
        int startY = 0;
        vector<vector<int>> result(n,vector<int>(n, 0));
        for(int cycle = 0; cycle < (n / 2); ++cycle){
            //上面
            for(; startY < n - offset; ++startY){
                result[startX][startY] = count++;
            }

            //右边
            for(; startX < n - offset; ++startX){
                result[startX][startY] = count++;
            }
            //下边
            for(; startY >=offset ; --startY){
                result[startX][startY] = count++;
            }
            //左边
            for(;startX >= offset; --startX){
                result[startX][startY] = count++;
            }
            ++startX;
            ++startY;
            ++offset;
        }
        if(n % 2 == 1){
            result[n / 2][n / 2] = count;
        }
        return result;
    }
};



int main(){
    Solution s,a;
    vector<vector<int>> result = s.generateMatrix(6);
    for(int i = 0; i < result.size(); ++i){
        for(int j = 0; j < result[i].size(); ++j){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}