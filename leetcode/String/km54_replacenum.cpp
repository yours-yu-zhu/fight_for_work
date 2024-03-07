#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    int count = 0;
    cin >> s;
    int oldsize = s.size();
    //获取数字的数量
    for(int i = 0; i < oldsize; ++i){
        if(s[i] >= '0' && s[i] <= '9'){
            ++count;
        }
    }
    s.resize(oldsize + 5 * count);
    for(int slow = oldsize - 1, fast = s.size() - 1;slow > 0 ; --slow, --fast){
        if(s[slow] >= 'a' && s[slow] <= 'z'){
            s[fast] = s[slow];
        }else{
            s[fast] = 'r';
            s[fast - 1] = 'e';
            s[fast - 2] = 'b';
            s[fast - 3] = 'm';
            s[fast - 4] = 'u';
            s[fast - 5] = 'n';
            fast -= 5;            
        }
    }
    cout << s << endl;
    
}