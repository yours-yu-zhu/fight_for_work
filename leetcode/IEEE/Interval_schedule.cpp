#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 区间结构体
struct Interval {
    int start;
    int end;
};

// 比较函数，按结束时间排序
bool compare(Interval a, Interval b) {
    return a.end < b.end;
}

int maxNonOverlappingIntervals(vector<Interval>& intervals) {
    // 按结束时间排序
    sort(intervals.begin(), intervals.end(), compare);
    
    int count = 0;
    int last_end_time = 0;
    
    for (auto& interval : intervals) {
        if (interval.start >= last_end_time) {
            count++;
            last_end_time = interval.end;
        }
    }
    
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<Interval> intervals(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> intervals[i].start >> intervals[i].end;
    }
    
    int result = maxNonOverlappingIntervals(intervals);
    cout << result << endl;
    
    return 0;
}
