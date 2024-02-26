#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int getsum(int n){
        int sum;
        while(n){
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    //哈希表方法
    bool isHappy(int n) {
        unordered_set<int> hash;
        int sum = n;
        while(1){
            sum = getsum(sum);
            if(sum == 1){
                return true;
            }

            if(hash.find(sum) == hash.end()){
                hash.insert(sum);
            }else{
                return false;
            }
        }
    }
    //快慢指针方法
        bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do{
            slow = getsum(slow);
            fast = getsum(fast);
            fast = getsum(fast);
        }while(slow != fast);

        return slow == 1;
    }
};

int main(){
    Solution s;
    int n = 19;
    cout << s.isHappy(n) << endl;
    return 0;
}