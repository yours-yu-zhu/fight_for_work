#include <bits/stdc++.h>
using namespace std;
long long l, n, m;
long long cnt = 0, cnt1 = 0, cnt2 = 0;
long long cnta[100001];
int main()
{
    cin >> l >> n >> m;
    cnt = 1;
    for (long long i = 1; i <= n; i++)
    {
        char a;
        long long b;
        cin >> a >> b;
        if (a == 'R')
            cnt1++;
        else
            cnta[++cnt2] = b;
        cnt++;
    }
    // cout<<cnt<<"x"<<endl;
    sort(cnta + 1, cnta + cnt2 + 1);
    for (long long i = 1; i <= m; i++)
    {
        char a;
        long long b;
        cin >> a >> b;
        if (a == 'L')
            cnt += n;
        else
        {
            cnt += (upper_bound(cnta + 1, cnta + cnt2 + 1, b) - cnta);
        }
        cnt++;
    }
    cout << cnt;
}