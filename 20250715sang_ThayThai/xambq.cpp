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

const int maxn = 1507;
int n, a[maxn][maxn];

namespace sub1 {
	int b[maxn][maxn];

	int ans = 0;
	int dp(int x, int y) {
		FOR(i, x, n) FOR(j, y, n) {
			ans -= b[i][j];
			b[i][j] = a[i][j];
			if (i != 1) maxi(b[i][j], b[i - 1][j] + a[i][j]);
			if (j != 1) maxi(b[i][j], b[i][j - 1] + a[i][j]);
			ans += b[i][j];
		}
		return ans;
	}

	pair<int, int> toiuusieucap(int x, int y) {
		int xx = n, yy = n;
		FOR(i, x, n) {
			if (i == 1) continue;
			if (i != 1) {
				if (b[i][y - 1] + a[i][y] > b[i - 1][y] + a[i][y]) {
					xx = i;
					break;
				}
			}
		}
		FOR(j, y, n) {
			if (j == 1)  continue;
			if (j != 1) {
				if (b[x - 1][j] + a[x][j] > b[x][j - 1] + a[x][j]) {
					yy = j;
					break;
				}
			}
		}
		return {xx, yy};
	}

	void app(int x1, int y1, int x2, int y2, int val) {
		FOR(x, x1 + 1, x2) FOR(y, y1 + 1, y2) b[x][y] += val;
	}

	int cal() {
		int ans = 0;
		FOR(i, 1, n) FOR(j, 1, n) ans += b[i][j];
		return ans;
	}

	void getout() {
		FOR(i, 1, n) FOR(j, 1, n) cout << b[i][j] << " \n"[j == n];
		cout __ ;
	}

	void sol() {
		cout << dp(1, 1) __ ;
		// cout << cal() __ ;
		getout();
		char typ;
		int x, y;
		while(cin >> typ >> x >> y) {
			if (typ == 'U') {
				a[x][y]++;
			} else {
				a[x][y]--;
			}
			cout << toiuusieucap(x, y) __ ;
			cout << dp(x, y) _ typ _ x _ y __  ;
			getout();
			// cout << cal() __ ;
		}
	}
};

void process() {
    cin >> n;
    FOR(i, 1, n) FOR(j, 1, n) cin >> a[i][j];
	
	sub1::sol();	
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