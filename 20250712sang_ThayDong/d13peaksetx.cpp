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

const int maxn = 1e5 + 7;
int n, m;
string a[maxn];

int getint(int l, int r) {
    int res = 0;
    for(int i = 0; i < 4; i++) {
        res = (res << 15) ^ (rand() & ((1 << 15) - 1));
    }
    return l + rand() % (r - l + 1);
}

// int mmax = intmin, mmin = intmax;
// vector<int> chosemmax, chosemmin;

// vector<int> chose;
// unordered_set<int> ss;
// int cal() {
// 	int ans = chose[0];
// 	FOR(i, 1, len(chose) - 1)
// 		ans = ans ^ chose[i];
// 	return ans;
// }

// void dq(int i, int j, int cur) {
// 	if (i > n) {
// 		int x = len(ss);
// 		if (x > mmax) {
// 			mmax = x;
// 			chosemmax = c    hose;
// 		}

// 		if (x < mmin) {
// 			mmin = x;
// 			chosemmin = chose;
// 		}

// 		// cout << x _ chose __ ;

// 		return;
// 	}

// 	if (j == m) {
// 		chose.push_back(cur);
// 		ss.insert(cur);
// 		dq(i + 1, 0, 0);
// 		ss.erase(cur);
// 		chose.pop_back();
// 		return;
// 	} else {
// 		if (a[i][j] == '0') dq(i, j + 1, cur);
// 		else if (a[i][j] == '1') dq(i, j + 1, cur + (1 << (m - j - 1)));
// 		else {
// 			dq(i, j + 1, cur);
// 			dq(i, j + 1, cur + (1 << (m - j - 1)));
// 		}
// 	}
// }

int mmax = intmin, mmin = intmax;
int ans[maxn][107];
int ansmmax[maxn][107], ansmmin[maxn][107];

void process() {
	cin >> n >> m;
	vector<pair<int, int>> pos;

	FOR(i, 1, n) {
		cin >> a[i]; a[i] = " " + a[i];
		FOR(j, 1, m) {
			if (a[i][j] == '*') pos.pb({i, j});
			else ans[i][j] = (a[i][j] - '0');
		}
	}

	while(clock() * 1.0 / CLOCKS_PER_SEC <= 2.95) {
		for(const pair<int, int> &val : pos) {
			int i = val.fi, j = val.se;
			int x = getint(0, 1);
			ans[i][j] = (x % 2);
		}

		unordered_set<string> ss;
		FOR(i, 1, n) {
			string cur = "";
			FOR(j, 1, m) cur += (char)(ans[i][j] + '0');
			ss.insert(cur);
		}

		if (len(ss) > mmax) {
			mmax = len(ss);
			FOR(i, 1, n) FOR(j, 1, m) ansmmax[i][j] = ans[i][j]; 
		}
		if (len(ss) < mmin) {
			mmin = len(ss);
			FOR(i, 1, n) FOR(j, 1, m) ansmmin[i][j] = ans[i][j];
		}
	}

	cout << mmin ___ ;
	FOR(i, 1, n) {
		FOR(j, 1, m) cout << ansmmin[i][j];
		cout ___ ;
	}
	cout __ ;

	cout << mmax ___ ;
	FOR(i, 1, n) {
		FOR(j, 1, m) cout << ansmmax[i][j];
		cout ___ ;
	}


	// cout << len(ss) ___ ;
	// FOR(i, 1, n) {
	// 	FOR(j, 1, m) cout << ans[i][j];
	// 	cout ___ ;
	// }
	// cout __ ;

	// mmax
	// int case1 = 0, case2 = 0, case3 = 0;

	// // 0 truoc 1 sau
	// FOR(j, 1, m) {
	// 	int cntt = 0;
	// 	FOR(i, 1, n) {
	// 		if (a[i][j] == '1') ans1[i][j] = 1;
	// 		else if (a[i][j] == '0') ans1[i][j] = 0;
	// 		else {
	// 			if (cntt % 2 == 0) ans1[i][j] = 0;
	// 			else ans1[i][j] = 1;
	// 			cntt++;
	// 		}
	// 	}
	// }

	// ss.clear();
	// FOR(i, 1, n) {
	// 	int cur = 0;
	// 	FOR(j, 1, m) cur = cur * 10 + ans1[i][j];
	// 	ss.insert(cur);
	// }

	// case1 = len(ss);

	// FOR(j, 1, m) {
	// 	int cntt = 1;
	// 	FOR(i, 1, n) {
	// 		if (a[i][j] == '1') ans2[i][j] = 1;
	// 		else if (a[i][j] == '0') ans2[i][j] = 0;
	// 		else {
	// 			if (cntt % 2 == 0) ans2[i][j] = 0;
	// 			else ans2[i][j] = 1;
	// 			cntt++;
	// 		}
	// 	}
	// }

	// ss.clear();
	// FOR(i, 1, n) {
	// 	int cur = 0;
	// 	FOR(j, 1, m) cur = cur * 10 + ans1[i][j];
	// 	ss.insert(cur);
	// }

	// case2 = len(ss);

	// FOR(j, 1, m) {
	// 	FOR(i, 1, n) {
	// 		if (a[i][j] == '1') ans3[i][j] = 1;
	// 		else if (a[i][j] == '0') ans3[i][j] = 0;
	// 		else {
	// 			int cntt = getint(1, 100);
	// 			ans3[i][j] = (cntt % 2);
	// 		}
	// 	}
	// }

	// ss.clear();
	// FOR(i, 1, n) {
	// 	int cur = 0;
	// 	FOR(j, 1, m) cur = cur * 10 + ans3[i][j];
	// 	ss.insert(cur);
	// }

	// case3 = len(ss);

	// if (case1 == max({case1, case2, case3})) {
	// 	cout << case1 ___ ;
	// 	FOR(i, 1, n) {
	// 		FOR(j, 1, m) cout << ans1[i][j];
	// 		cout ___ ;
	// 	}
	// } else if (case2 == max({case1, case2, case3})){
	// 	cout << case2 ___ ;
	// 	FOR(i, 1, n) {
	// 		FOR(j, 1, m) cout << ans2[i][j];
	// 		cout ___ ;
	// 	}
	// } else {
	// 	cout << case3 ___ ;
	// 	FOR(i, 1, n) {
	// 		FOR(j, 1, m) cout << ans3[i][j];
	// 		cout ___ ;
	// 	}
	// }


	// dq(1, 0, 0);
	// cout << mmin ___ ;
	// for(const int &val : chosemmin) {
	// 	FORD(i, m - 1, 0) cout << ((val >> i) & 1);
	// 	cout ___ ;
	// }
	// cout __ ;

	// cout << mmax ___ ;
	// for(const int &val : chosemmax) {
	// 	FORD(i, m - 1, 0) cout << ((val >> i) & 1);
	// 	cout ___ ;
	// }

    // 0 2 1 7
    // cout << (((1 ^ 2) ^ 1) ^ 2) __ ;
    // cout << (((0 ^ 2) ^ 1) ^ 7) __ ;
}



/*-----------------------------*/
______________TgX______________ {
	srand(time(NULL));
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