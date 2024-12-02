#include <iostream>

using namespace std;
long long l, n, m;
long long f[2002][2002];
int bola[4005], bolb[4005], a, b;

long long p = 998244353;

int main()
{
    cin >> n;
    cin >> a;
    bolb[2 * n] = 1;
    bola[1] = 1;
    for (int i = 1; i <= a; i++)
    {
        int x;
        cin >> x;
        bola[x] = 1;
    }
    cin >> b;
    for (int i = 1; i <= b; i++)
    {
        int x;
        cin >> x;
        bolb[x] = 1;
    }
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        f[0][i] = !bola[i] && f[0][i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        f[i][0] = !bolb[i] && f[i - 1][0];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (!bolb[i + j] && !(i - 1 < j))
                f[i][j] = f[i - 1][j];
            if (!bola[i + j])
                f[i][j] = (f[i][j - 1] + f[i][j]) % p;
        }
    }
    cout << f[n][n] << endl;
}