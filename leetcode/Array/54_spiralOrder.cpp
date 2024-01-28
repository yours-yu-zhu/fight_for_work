#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0){
            return {};
        }
        int row = matrix.size();
        int col = matrix[0].size();
        int startX = 0;
        int startY = 0;
        int offset = 1;
        vector<int> result;
        for(int count = 0; count < row * col;){
            //上边
            for(;startY < col - offset; ++startY){
                if(count >= row * col)
                    break;
                result.push_back(matrix[startX][startY]);
                ++count;
            }
            //右边
            for(;startX < row - offset; ++startX){
                if(count >= row * col)
                    break;
                result.push_back(matrix[startX][startY]);
                ++count;
            }
            //下边
            for(;startY >= offset; --startY){
                if(count >= row * col)
                    break;
                result.push_back(matrix[startX][startY]);
                ++count;
            }
            //左边
            for(;startX >= offset; --startX){
                if(count >= row * col)
                    break;
                result.push_back(matrix[startX][startY]);
                ++count;
            }
            if(col == row && col % 2 == 1 && count == row * col - 1){
                result.push_back(matrix[col / 2][row / 2]);
                ++count;
            }
            ++startX;
            ++startY;
            ++offset;

        }

        return result;
    }
};


int main(){
    Solution s;
    vector<vector<int>> matrix = {};
    vector<int> result = s.spiralOrder(matrix);
    for(int i = 0; i < result.size(); ++i){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}