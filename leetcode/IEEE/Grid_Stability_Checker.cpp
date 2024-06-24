#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 辅助函数：翻转字符
char invert(char c) {
    return c == '0' ? '1' : '0';
}

// 主函数：查找第 k 个字符
char findKthCharacter(const string &S, long long k) {
    long long length = S.size();
    long long currentLength = length;
    bool falg = false;
    while (currentLength <= k) {
        currentLength *= 2;
    }       
    while (k >= length) {
        if(k >= currentLength / 2){
            k = k - currentLength / 2;
            falg = !falg;
        }
        currentLength = currentLength / 2;
    }
    
    if (falg) {
        return invert(S[k]);
    } else {
        return S[k];
    }
}

int main() {
    // 读取输入
    string S;
    int n;
    cin >> S >> n;
    vector<long long> queries(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> queries[i];
        queries[i]--;  // 转换为 0 基索引
    }
    
    // 处理每个查询
    for (int i = 0; i < n; ++i) {
        cout << findKthCharacter(S, queries[i]) << endl;
    }
    
    return 0;
}
