#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int mySqrt_1(int x) {
        double left = 0, right = static_cast<double>(x) + 1;       
        int result = 0;
        if(x == 0){
            return 0;
        }

        while(left < right){
            int middle = left + (right - left) / 2;
            if(middle > x / middle){
                right = middle;
            }else if(middle < x / middle){
                left = middle + 1;
                result = middle;
            }else{
                return middle;
            }
        }
        return result;
    }
    int mySqrt_2(int x) {
        double left = 0, right = static_cast<double>(x) + 1;       
        int result = 0;
        while(left < right){
            int middle = left + (right - left) / 2;
            if(static_cast<double>(middle) * static_cast<double>(middle) > x){
                right = middle;
            }else if(static_cast<double>(middle) * static_cast<double>(middle) < x){
                left = middle + 1;
                result = middle;
            }else if(static_cast<double>(middle) * static_cast<double>(middle) == x){
                return middle;
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    cout << sizeof(long long) << endl;
    return 0;
}