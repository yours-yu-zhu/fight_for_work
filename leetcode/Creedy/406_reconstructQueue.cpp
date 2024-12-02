#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class cmp{
public:
    bool operator()(vector<int>& a, vector<int>& b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
        
    }
};

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {

    }
};
int main(){
    Solution s;
    vector<vector<int>> people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    sort(people.begin(), people.end(), cmp());
    //cout pepole
    for(auto p : people){
        cout << p[0] << " " << p[1] << endl;
    }
    return 0;
}