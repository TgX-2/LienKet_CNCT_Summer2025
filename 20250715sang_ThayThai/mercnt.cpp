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
// #define int                long long
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

const int mod = 1e9 + 7;
const int maxn = 7007;
long long n, a[maxn], b[maxn];

// int bs(int v, int tar) {
// 	int l = v, r = n;
// 	int ans = -1;
// 	while(l <= r) {
// 		int mid = (l + r) >> 1;
// 		if (b[mid] - b[v - 1] >= tar) {
// 			ans = mid;
// 			r = mid - 1;
// 		} else l = mid + 1;
// 	}
// 	return ans;
// }

int dp[maxn][maxn];
// int loc(int id, int pre) {
// 	if (id > n) return 1;

// 	if (dp[id][pre] != -1) return dp[id][pre];

// 	long long ans = 0;
// 	int pos = bs(id, b[id - 1] - b[pre - 1]);
// 	if (pos != -1) {
// 		FOR(i, pos, n) {
// 			ans += loc(i + 1, id);
// 			ans %= mod;
// 		}
// 	}
// 	dp[id][pre] = ans;
// 	return ans;
// }



void process() {
    cin >> n;
    FOR(i, 1, n) {
    	cin >> a[i];
    	b[i] = b[i - 1] + a[i];
    }

    FOR(i, 1, n) dp[1][i] = 1;
    FOR(i, 1, n - 1) {
    	long long val = 0, id = i;
    	FOR(j, i + 1, n) {
    		while(id >= 1 and b[j] - b[i] >= b[i] - b[id - 1]) {
    			val += dp[id][i];
    			val %= mod;
    			id--;
    		}
    		dp[i + 1][j] = val;
    	}
    }

	long long ans = 0;
    FOR(i, 1, n) {
    	ans += dp[i][n];
    	ans %= mod;
    }
    cout << ans;

    // if (n <= 1000) {
	//     memo(dp, -1);
	//     cout << loc(1, 1);
    // }
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