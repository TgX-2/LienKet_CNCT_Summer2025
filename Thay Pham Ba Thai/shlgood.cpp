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

const int maxn = 5e5 + 7;
int n, a[maxn];

namespace sub1 {

	int mmax[maxn][30], mmin[maxn][30];
	void build() {
		FOR(i, 1, n) {
			mmax[i][0] = a[i];
			mmin[i][0] = a[i];
		}

		for(int j = 1; (1 << j) <= n; j++) {
			for(int i = 1; i + (1 << j) - 1 <= n; i++) {
				mmax[i][j] = max(mmax[i][j - 1], mmax[i + (1 << (j - 1))][j - 1]);
				mmin[i][j] = min(mmin[i][j - 1], mmin[i + (1 << (j - 1))][j - 1]);
			}
		}
	}

	int getmax(int l, int r) {
		if (l > r) return intmin;
		int k = __lg(r - l + 1);
		return max(mmax[l][k], mmax[r - (1 << k) + 1][k]);
	}

	int getmin(int l, int r) {
		if (l > r) return intmax;
		int k = __lg(r - l + 1);
		return min(mmin[l][k], mmin[r - (1 << k) + 1][k]);
	}

	bool check(int l, int r) {
		int m = (r - l + 1);
		int pivot1 = r - m / 2, pivot2 = r;
		while(1) {			
			if (pivot1 < l) break;
			int seq1 = llongmax;
			if (pivot1 - 1 >= l) mini(seq1, getmin(l, pivot1 - 1));
			if (pivot2 + 1 <= r) mini(seq1, getmin(pivot2 + 1, r));
			int seq2 = getmax(pivot1, pivot2);
			// debug(l, r);
			// debug(pivot1, pivot2);
			// FOR(x, l, r) cout << a[x] ___ ; cout __ ;
			// cout << mmax _ mmin __ ;

			// mmax = llongmax;
			// mmin = llongmin;

			// FOR(x, l, r) {
			// 	if (l <= x and x <= pivot1 - 1) mini(mmax, a[x]);
			// 	if (pivot2 + 1 <= x and x <= r) mini(mmax, a[x]);
			// 	if (pivot1 <= x and x <= pivot2) maxi(mmin, a[x]);
			// }

			// cout << mmax _ mmin __ ;
			// cout __ ;
			if (seq1 > seq2) {
				FOR(x, l, r) cout << a[x] << " \n"[x == r];
				return 1;
			}
			pivot1--;
			pivot2--;
		}
		return 0;	
	}

	void sol() {
		build();
		int ans = 0;
		FOR(i, 1, n) 
			for(int j = i + 1; j <= n; j += 2) 
				ans += check(i, j);
		cout << ans;
	}
};

void process() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];

	if (n <= 5000) sub1::sol();
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