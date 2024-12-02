#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    long x;
    cin >> N >> x;
    vector<long> A(N);
    for(auto &a:A) cin >> a;
    
    // 将砖块按升序排序
    sort(A.begin(), A.end());
    
    // 存储每个堆栈的砖块
    vector<vector<long>> stacks;
    
    // 使用 multiset 来维护堆栈的顶部砖块，存储 pair<stack_top, stack_id>
    // multiset 按 stack_top 升序排列
    multiset<pair<long, int>> stack_tops;
    
    for(int i = 0; i < N; ++i){
        long brick = A[i];
        long required = brick - x;
        
        // 查找第一个 stack_top > required
        auto it = stack_tops.upper_bound({required, INT32_MAX});
        
        if(it == stack_tops.begin()){
            // 没有合适的堆栈，创建新的堆栈
            stacks.emplace_back();
            stacks.back().push_back(brick);
            // 插入新的堆栈顶部
            stack_tops.emplace(brick, stacks.size()-1);
        }
        else{
            // 找到最大的 stack_top <= required
            --it;
            long stack_top = it->first;
            int stack_id = it->second;
            // 移除旧的 stack_top
            stack_tops.erase(it);
            // 将砖块放入该堆栈
            stacks[stack_id].push_back(brick);
            // 插入新的 stack_top
            stack_tops.emplace(brick, stack_id);
        }
    }
    
    // 输出堆栈的数量
    cout << stacks.size() << "\n";
    
    // 输出每个堆栈的信息
    for(auto &stack : stacks){
        // 从大到小排列
        // 由于砖块是按升序放入堆栈的，所以逆序输出
        cout << stack.size() << "\n";
        for(int i = stack.size()-1; i >=0; --i){
            cout << stack[i] << (i ? ' ' : '\n');
        }
    }
    
    return 0;
}
