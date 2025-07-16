/*-----------------------------
        Author : TgX.2
       11Ti - K28 - CHV
-----------------------------*/

#include <bits/stdc++.h>
using namespace std;

#ifdef TGX
#include "D:\egoist\debug.h"
#else 
#define debug(...)
#endif

#define FOR(i, a, b)       for (int i = (a), _b = (b); i <= _b; i += 1)
#define FORD(i, a, b)      for (int i = (a), _b = (b); i >= _b; i -= 1)

#define fi                 first
#define se                 second
#define pb                 push_back
#define len(x)             (int)((x).size())
#define all(x)             (x).begin(), (x).end()

#define _                  << " " <<
#define __                 << "\n"
#define ___                << " "

#define ______________TgX______________ main()
#define int                long long
#define intmax             1e9
#define intmin            -1e9
#define llongmax           1e18
#define llongmin          -1e18
#define memo(a, val)       memset((a), (val), sizeof((a)))

template<typename T1, typename T2> bool mini(T1 &a, T2 b)
    {if (a > b) a = b; else return 0; return 1;}

template<typename T1, typename T2> bool maxi(T1 &a, T2 b)
    {if (a < b) a = b; else return 0; return 1;}
/*-----------------------------*/

const int maxn = 107;
const int mod  = 998244353;

int n, s, k, c[maxn], v[maxn];
bool f[maxn][maxn];
int dp[maxn][maxn][maxn], nCk[maxn][maxn], pw[maxn][maxn];

void add(int &x, const int &y){
    x += y;
    if(x >= mod) x -= mod;
}

void process(){
    cin >> n >> s >> k;
    FOR(i, 1, n)  cin >> c[i] >> v[i];

    for(int i = 0; i <= 100; i++) nCk[i][0] = 1;
    for(int i = 1; i <= 100; i++){
        for(int j = 1; j <= i; j++) nCk[i][j] = (nCk[i - 1][j - 1] + nCk[i - 1][j]) % mod;
    }

    FOR(i, 1, n) {
        pw[i][0] = 1;
        for(int j = 1; j <= k; j++) pw[i][j] = 1LL * pw[i][j - 1] * v[i] % mod;
    }

    f[0][0] = 1;
    FOR(i, 1, n) {
        for(int j = 0; j <= s; j++){
            f[i][j] = f[i - 1][j];
            if(j >= c[i] && f[i - 1][j - c[i]]) f[i][j] = f[i - 1][j - c[i]];
        }
    }

    for(int i = 0; i <= n; i++) dp[i][0][0] = 1;
    FOR(i, 1, n) {
        for(int j = 1; j <= s; j++) for(int x = 0; x <= k; x++){
            if(j >= c[i] && f[i - 1][j - c[i]]){
                for(int y = 0; y <= x; y++) add(dp[i][j][x], 1LL * nCk[x][y] * pw[i][x - y] % mod * dp[i - 1][j - c[i]][y] % mod);
            }
            add(dp[i][j][x], dp[i - 1][j][x]);
        }
    }
    int res = 0;
    for(int i = 0; i <= s; i++) add(res, dp[n][i][k]);
    cout << res;
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    if (fopen("temp.inp", "r")) {
        freopen("temp.inp", "r", stdin);
        freopen("temp.out", "w", stdout);
    }
    process();
    cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC __ ;
}


/*==============================+
|INPUT                          |
--------------------------------|

================================+
|OUTPUT                         |
--------------------------------|

===============================*/