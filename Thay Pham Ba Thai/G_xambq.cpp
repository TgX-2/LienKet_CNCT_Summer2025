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

// namespace sub1 {
// 	int b[maxn][maxn];

// 	int ans = 0;
// 	int dp(int x, int y) {
// 		FOR(i, x, n) FOR(j, y, n) {
// 			ans -= b[i][j];
// 			b[i][j] = a[i][j];
// 			if (i != 1) maxi(b[i][j], b[i - 1][j] + a[i][j]);
// 			if (j != 1) maxi(b[i][j], b[i][j - 1] + a[i][j]);
// 			ans += b[i][j];
// 		}
// 		return ans;
// 	}

// 	pair<int, int> toiuusieucap(int x, int y) {
// 		int xx = n, yy = n;
// 		FOR(i, x, n) {
// 			if (i == 1) continue;
// 			if (i != 1) {
// 				if (b[i][y - 1] + a[i][y] > b[i - 1][y] + a[i][y]) {
// 					xx = i;
// 					break;
// 				}
// 			}
// 		}
// 		FOR(j, y, n) {
// 			if (j == 1)  continue;
// 			if (j != 1) {
// 				if (b[x - 1][j] + a[x][j] > b[x][j - 1] + a[x][j]) {
// 					yy = j;
// 					break;
// 				}
// 			}
// 		}
// 		return {xx, yy};
// 	}

// 	void app(int x1, int y1, int x2, int y2, int val) {
// 		FOR(x, x1 + 1, x2) FOR(y, y1 + 1, y2) b[x][y] += val;
// 	}

// 	int cal() {
// 		int ans = 0;
// 		FOR(i, 1, n) FOR(j, 1, n) ans += b[i][j];
// 		return ans;
// 	}

// 	void getout() {
// 		FOR(i, 1, n) FOR(j, 1, n) cout << b[i][j] << " \n"[j == n];
// 		cout __ ;
// 	}

// 	void sol() {
// 		cout << dp(1, 1) __ ;
// 		// cout << cal() __ ;
// 		getout();
// 		char typ;
// 		int x, y;
// 		while(cin >> typ >> x >> y) {
// 			if (typ == 'U') {
// 				a[x][y]++;
// 			} else {
// 				a[x][y]--;
// 			}
// 			cout << toiuusieucap(x, y) __ ;
// 			cout << dp(x, y) _ typ _ x _ y __  ;
// 			getout();
// 			// cout << cal() __ ;
// 		}
// 	}
// };

struct {
	int sex[maxn << 2];
	void update(int id, int l, int r, int pos, int val) {
		if (pos < l or r < pos) return;
		if (l == r) return sex[id] += val, void();
		int mid = (l + r) >> 1;
		update(id << 1, l, mid, pos, val);
		update(id << 1 | 1, mid + 1, r, pos, val);
		sex[id] = sex[id << 1] + sex[id << 1 | 1];
	}

	int get(int id, int l, int r, int u, int v) {
		if (v < l or r < u) return 0;
		if (u <= l and r <= v) return sex[id];
		int mid = (l + r) >> 1;
		return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
	}
} seg[maxn];

int ans = 0;
int dp[maxn][maxn];

void process() {
    cin >> n;
    FOR(i, 1, n) FOR(j, 1, n) {
        cin >> a[i][j];
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
        ans += dp[i][j];
        seg[i].update(1, 1, n, j, dp[i][j] - dp[i][j - 1]);
    }

    cout << ans __ ;

    FOR(t, 1, n) {
        char typ; int x, y;
        cin >> typ >> x >> y;

        int f1 = y, f2 = y, nf2 = 1e18;
        int last_j = x - 1; 

        if (typ == 'U') {
            for (int j = x; j <= n; j++) {
                while (f2 + 1 <= n &&
                    1 + seg[j].get(1, 1, n, 1, f2) > seg[j - 1].get(1, 1, n, 1, f2 + 1))
                    f2++;

                if (j != x) {
                    while (f1 <= nf2 && f1 > 1 &&
                        seg[j].get(1, 1, n, 1, f1 - 1) >= seg[j - 1].get(1, 1, n, 1, f1))
                        f1++;
                }

                if (f1 > nf2) break;

                seg[j].update(1, 1, n, f1, 1);
                if (f2 != n) seg[j].update(1, 1, n, f2 + 1, -1);

                ans += (f2 - f1 + 1);
                nf2 = f2;
                last_j = j;
            }
            a[last_j][y]++;
        } else {
            for (int j = x; j <= n; j++) {
                while (f2 + 1 <= n &&
                    seg[j].get(1, 1, n, 1, f2) - 1 >= seg[j - 1].get(1, 1, n, 1, f2 + 1))
                    f2++;

                if (j != x) {
                    while (f1 <= nf2 && f1 > 1 &&
                        seg[j].get(1, 1, n, 1, f1 - 1) > seg[j - 1].get(1, 1, n, 1, f1))
                        f1++;
                }

                if (f1 > nf2) break;

                seg[j].update(1, 1, n, f1, -1);
                if (f2 != n) seg[j].update(1, 1, n, f2 + 1, 1);

                ans -= (f2 - f1 + 1);
                nf2 = f2;
                last_j = j;
            }
            a[last_j][y]--;
        }

        cout << ans __ ;
    }
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