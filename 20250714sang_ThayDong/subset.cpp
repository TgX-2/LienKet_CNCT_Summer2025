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

const int maxn = 2e5 + 7;
int n, l, r, a[maxn];

namespace sub1 {
	void sol() {
		for(int mask = 0; mask < (1 << n); mask++) {
			int sum = 0;
			vector<int> v;

			FOR(i, 0, n - 1) if (mask & (1 << (i))) {
				v.pb(i + 1);
				sum += a[i + 1];
			}

			if (l <= sum and sum <= r) {
				cout << len(v) __ ;
				for(const int &val : v) cout << val ___ ;
				return;
			}
		}
	}
};

namespace sub2 {
	int m;
	unordered_map<int, vector<int>> m1, m2;

	vector<int> chose;
	void build1(int id, int sum) {
		if (id > m) {
			m1[sum] = chose;
			return;
		}

		build1(id + 1, sum);

		chose.pb(id);
		build1(id + 1, sum + a[id]);
		chose.pop_back();
	}

	void build2(int id, int sum) {

		if (id > n) {
			m2[sum] = chose;
			return;
		}

		build2(id + 1, sum);

		chose.pb(id);
		build2(id + 1, sum + a[id]);
		chose.pop_back();
	}
	
	vector<pair<int, vector<int>>> v1, v2;

	bool bs(int tar) {
		int u = 0, v = len(v2) - 1, ans = -1;
		while(u <= v) {
			int mid = (u + v) >> 1;
			if (v2[mid].fi + tar <= r) {
				v = mid - 1;
				ans = mid;
			} else u = mid + 1;
		}

		if (ans == -1) return 0;
		if (v2[ans].fi + tar >= l) return 1;
		return 0;
	}

	void sol() {
		m = n / 2;
		build1(1, 0);
		build2(m + 1, 0);

		for(const pair<int, vector<int>> &val1 : m1) 
			v1.pb(val1);
		for(const pair<int, vector<int>> &val2 : m2)
			v2.pb(val2);

		sort(all(v1));
		sort(all(v2));


		for(const pair<int, vector<int>> &val1 : v1) if (val1.fi <= r) {
			int pos = bs(val1.fi);

			if (pos != -1) {
				FOR(i, pos, len(v2) - 1) if (v2[i].fi + val1.fi <= r) {
					if (v2[i].fi + val1.fi >= l) {
						cout << len(val1.se) + len(v2[i].se) __ ;
						for(const int &ans : val1.se) cout << ans ___ ;
						for(const int &ans : v2[i].se) cout << ans ___ ;
						return;
					}
				} else break;
			}
		} else return;
	}
};

namespace sub4 {
	bool check() {
		int tar = a[1];
		FOR(i, 2, n) if (a[i] != tar) return 0;
		return 1;
	}

	void sol() {
		int u = 1, v = (r / a[1]) + 10;
		int ans = -1;
		while(u <= v) {
			int mid = (u + v) >> 1;
			if (a[1] * mid >= l) {
				ans = mid;
				v = mid - 1;
			} else u = mid + 1;
		}

		if (ans != -1 and a[1] * ans <= r) {
			cout << ans __ ;
			FOR(i, 1, ans) cout << i ___ ;
		}
	}
};

namespace sub5 {
	int b[maxn];

	vector<int> val;
	bool check() {
		FOR(i, 1, n) val.pb(i);
		sort(all(val));
		FOR(i, 1, n) if (i != val[i - 1]) return 0;
		return 1;
	}

	int bs(int uu, int vv) {
		int u = uu, v = vv, ans = -1;
		while(u <= v) {
			int mid = (u + v) >> 1;
			if (b[vv] - b[mid - 1] >= l) {
				ans = mid;
				u = mid + 1;
			} v = mid - 1;
		}

		// debug(ans);
		// cout << b[vv] - b[ans - 1] __ ;
		if (ans == -1) return ans;

		if (b[vv] - b[ans - 1] <= r) return ans;
		return -1;

		// return (ans == -1 : 0 : (b[vv] - b[ans - 1] >= l ));
	}

	void sol() {
		FOR(i, 1, n) b[i] = b[i - 1] + a[i];

		FOR(i, 1, n) {	
			int j = bs(1, i);
			// cout << j _ i __ ;
			if (j != -1) {
				cout << (i - j + 1) __ ;
				FOR(k, j, i) cout << k ___ ;
				return;
			}
		}
	}
};

void process() {
    cin >> n >> l >> r;
    FOR(i, 1, n) cin >> a[i];

    sub4::sol();
    return;

    if (n <= 20) sub1::sol();
    else if (n <= 40) sub2::sol();
    else if (sub4::check()) sub4::sol();
    else if (sub5::check()) sub5::sol();
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