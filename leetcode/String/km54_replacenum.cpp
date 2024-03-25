#include <iostream>
#include <string>

using namespace std;

#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;
    int count = 0;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] >= '0' && s[i] <= '9'){
            ++count;
        }
    }
    int r_len = s.size();
    s.resize(s.size() + 5 * count);
    for(int slow = r_len - 1, fast = s.size() - 1; slow >= 0; --slow, --fast){
        if(s[slow] >= '0' && s[slow] <= '9' ){
            s[fast] = 'r';
            s[fast - 1] = 'e';
            s[fast - 2] = 'b';
            s[fast - 3] = 'm';
            s[fast - 4] = 'u';
            s[fast - 5] = 'n';
            fast -= 5;
        }else{
            s[fast] = s[slow];
        }
    }
    cout << s << endl;
    
}