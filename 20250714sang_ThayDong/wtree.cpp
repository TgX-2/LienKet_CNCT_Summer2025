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

const int maxn = 1007;
int n, s, a[maxn];
vector<int> g[maxn];

int val[maxn];
int sta[maxn], fin[maxn], cnt = 0;
void dfs(int u, int pre) {
	val[u] += a[u];
	sta[u] = ++cnt;

	for(const int &v : g[u]) if (v != pre) {
		dfs(v, u);
		val[u] += val[v];
	}

	fin[u] = cnt;
}

array<int, 4> b[maxn];
bool cmp(const array<int, 4> &x, const array<int, 4> &y) {
	return (x[1] < y[1]);
}

bool vis[maxn][maxn];
bool mem[maxn][maxn];
vector<int> res;
bool loc(int id, int sum, vector<bool> &used) {
	if (sum > s) return 0;
	if (sum == s) return 1;
	if (id > n) return 0;

	// if (vis[id][sum]) return mem[id][sum];
	// vis[id][sum] = 1;

	if (loc(id + 1, sum, used)) {
		mem[id][sum] = 1;
		return 1;
	}


	bool cc = 1;
	FOR(i, b[id][1], b[id][2]) {
		if (i >= 1 and i <= n and used[i] == 1) {
			cc = 0;
			break;
		}
	}

	if (cc) {
        FOR(i, b[id][1], b[id][2]) used[i] = 1;
		if (loc(id + 1, sum + b[id][0], used)) {
			res.pb(id);
			mem[id][sum] = 1;
			return 1;
		}
		FOR(i, b[id][1], b[id][2]) used[i] = 0;
	}

	mem[id][sum] = 0;
	return 0;
}


void process() {
	cin >> n >> s;
	FOR(i, 1, n) cin >> a[i];
	FOR(i, 2, n) {
		int u, v; cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	dfs(1, 0);    

	FOR(i, 1, n) b[i] = {val[i], sta[i], fin[i], i};
	sort(b + 1, b + 1 + n, cmp);

	// FOR(i, 1, n) cout << b[i] __ ;

	vector<bool> used(n + 7, 0);
	if (loc(1, 0, used)) {
		cout << len(res) __ ;
		for(const int &val : res) 
			cout << b[val][3] ___ ;
	} else cout << -1;
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