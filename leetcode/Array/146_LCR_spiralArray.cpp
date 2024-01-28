#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> spiralArray(vector<vector<int>>& array) {
        if (array.size() == 0 || array[0].size() == 0) {
            return {};
        }
        int row = array.size(), col = array[0].size();
        int startX = 0, startY = 0;
        int offset = 1;
        vector<int> result;
        for(int count = 0; count < col * row;){
            //向右
            for(;startY < col - offset; ++startY){
                if(count >= col * row) break;
                result.push_back(array[startX][startY]);
                ++count;
            }
            //向下
            for(;startX < row - offset; ++startX){
                if(count >= col * row) break;
                result.push_back(array[startX][startY]);
                ++count;
            }
            //向左
            for(;startY >= offset; ++startY){
                if(count >= col * row) break;
                result.push_back(array[startX][startY]);
                ++count;
            }
            //向上
            for(;startX >= offset; ++startX){
                if(count >= col * row) break;
                result.push_back(array[startX][startY]);
                ++count;
            }
            if(row == col && count == row * col - 1 && row % 2 == 1){
                result.push_back(array[row / 2][col / 2]);
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
    vector<vector<int>> array = {{1,2,3},{4,5,6},{7,8,9}};
    Solution s;
    vector<int> result = s.spiralArray(array);
    for(auto i : result){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}