#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0, right = num;
        while(left <= right){
            int middle = left + (right - left) / 2;
            if(static_cast<double>(middle) * static_cast<double>(middle) > num){
                right = middle - 1;
            }else if(static_cast<double>(middle) * static_cast<double>(middle) < num){
                left = middle + 1;
            }else{
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution sol;
    cout << sol.isPerfectSquare(16) << endl;
    cout << sol.isPerfectSquare(14) << endl;
    cout << sol.isPerfectSquare(1) << endl;
    cout << sol.isPerfectSquare(0) << endl;
    cout << sol.isPerfectSquare(2147483647) << endl;
    return 0;
}