#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

typedef long long ll;

ll ns[100005];

struct Query
{
    ll id;
    ll x;
    ll ans;
};

vector<Query> qs;

ll calc(ll cur, ll start)
{
    if ((cur - start) % 2 == 0)
    {
        ll cost = calc(cur - 1, start);
        return max(cost, ns[cur]);
    }
    ll mx = 0;
    for (ll i = start; i < (cur - start + 1) / 2 + start; i++)
        mx = max(mx, ns[i] + ns[cur - i + start]);
    return mx;
}

ll binarySearch(ll l, ll r, ll start, ll x)
{
    ll ans = -1;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (calc(mid, start) <= x)
        {
            l = mid + 1;
            ans = mid;
        }
        else
            r = mid - 1;
    }
    return ans;
}

ll binarySearchEven(ll l, ll r, ll end, ll x)
{
    ll ans = 0;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (calc(end, 2 * mid - (end % 2 == 0)) <= x)
        {
            l = mid + 1;
            ans = 2 * mid - (end % 2 == 0);
        }
        else
            r = mid - 1;
    }
    return ans;
}

ll binarySearchOdd(ll l, ll r, ll end, ll x)
{
    ll ans = 0;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (calc(end, 2 * mid - (end % 2)) <= x)
        {
            l = mid + 1;
            ans = 2 * mid - (end % 2);
        }
        else
            r = mid - 1;
    }
    return ans;
}

ll raw[100005];

ll presum[100005];

ll eoro[100005];

int main()
{
    ll n, q;
    cin >> n >> q;
    for (ll i = 1; i <= n; i++)
    {
        cin >> ns[i];
        presum[i] = presum[i - 1] + ns[i];
        if (i >= 2)
            eoro[i] = eoro[i - 2] + ns[i];
        else
            eoro[i] = ns[i];
    }
    for (ll i = 0; i < q; i++)
    {
        ll x;
        cin >> x;
        qs.push_back({i, x, 0});
    }
    sort(qs.begin(), qs.end(), [](Query a, Query b)
         { return a.x < b.x; });
    ll lastAnswer = 1;
    for (ll i = 0; i < q; i++)
    {
        ll x = qs[i].x;
        raw[qs[i].id] = i;
        ll currentAnswer = binarySearch(lastAnswer, n, 1, x);
        ll ans = 0;
        for (ll j = 2; j <= currentAnswer; j++)
        {                                                              // j == 1 is not needed
            ll even = binarySearchEven(1, j / 2, j, x);                // even case
            ll odd = binarySearchOdd(even / 2 + 1, (j + 1) / 2, j, x); // odd case

            // cout << currentAnswer << " " << j << " " << even << " " << odd << endl;
            // for (ll k = 1; k <= even; k++) {
            //     ans += ns[j] - ns[k];
            // }
            ans += ns[j] * even - presum[even];
            assert((odd - even - 1) % 2 == 0);
            // for (ll k = even + 1; k <= odd; k+=2) {
            //     ans += ns[j] - ns[k];
            // }
            ans += ns[j] * (1 + (odd - even - 1) / 2) - (eoro[odd] - eoro[even - 1]);
        }
        lastAnswer = currentAnswer;
        qs[i].ans = ans;
    }

    for (ll i = 0; i < q; i++)
        cout << qs[raw[i]].ans << endl;
}
