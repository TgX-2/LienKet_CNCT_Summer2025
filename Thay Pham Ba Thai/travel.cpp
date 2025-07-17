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
int n, m, k;
vector<pair<int, int>> g[maxn];

int dis[maxn][15];

void dijk() {
	FOR(i, 0, n + 1) FOR(kk, 0, k + 1) dis[i][kk] = llongmax;
	dis[1][0] = 0;
	priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> q;
	q.push({dis[1][0], 1, 0});

	while(!q.empty()) {
		array<int, 3> top = q.top(); q.pop();
		int cost = top[0], u = top[1], kk = top[2];
		if (cost != dis[u][kk]) continue;

		for(const pair<int, int> &val : g[u]) {
			int v = val.fi, w = val.se;

			if (kk + 1 <= k and dis[v][kk + 1] > dis[u][kk]) {
				dis[v][kk + 1] = dis[u][kk];
				q.push({dis[v][kk + 1], v, kk + 1});
			}

			if (dis[v][kk] > dis[u][kk] + w) {
				dis[v][kk] = dis[u][kk] + w;
				q.push({dis[v][kk], v, kk});
			}
		}
	}

	// FOR(i, 1, n) FOR(j, 0, k) cout << dis[i][j] << " \n"[j == k];

	int ans = llongmax;
	FOR(kk, 0, k) 
		mini(ans, dis[n][kk]);
	if (ans == llongmax) cout << -1;
	else cout << ans;
}

void process() {
    cin >> n >> m >> k;
    FOR(i, 1, m) {
    	int u, v, w; cin >> u >> v >> w;
    	g[u].pb({v, w});
    	g[v].pb({u, w});
    }

    dijk();
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