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
int n, m;
vector<int> a[4];
int rep[maxn];
vector<pair<int, int>> g[maxn];

int dis[maxn], trace[maxn];
vector<int> dijk(int x, int y) {
	FOR(i, 0, n + 1) {
		dis[i] = intmax;
		trace[i] = 0;
	}

	queue<pair<int, int>> q;

	dis[a[x][0]] = 0;
	q.push({dis[a[x][0]], a[x][0]});
	trace[a[x][0]] = -1;

	// for(const int &i : a[x]) {
	// 	dis[i] = 0;
	// 	q.push({dis[i], i});
	// 	trace[i] = -1;
	// }

	while(!q.empty()) {
		pair<int, int> top = q.front(); q.pop();
		int cost = top.fi, u = top.se;
		if (cost != dis[u]) continue;

		for(const pair<int, int> &val : g[u]) {
			int v = val.fi, w = val.se;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				trace[v] = u;
				q.push({dis[v], v});
			}
		}
	}

	vector<int> path;
	int cur = a[y][0];
	while(1) {
		if (cur == -1) break;
		if (rep[cur] == 0) path.pb(cur);
		cur = trace[cur];
	}

	reverse(all(path));
	return path;
}

unordered_set<int> cal(int x, int y, int z) {
	unordered_set<int> ans;
	vector<int> d1 = dijk(x, y);
	vector<int> d2 = dijk(x, z);
	for(const int &val : d1) ans.insert(val);
	for(const int &val : d2) ans.insert(val);
	return ans;
}

void process() {
    cin >> n >> m;

    FOR(i, 1, 3) {
    	int xx; cin >> xx;
    	FOR(j, 1, xx) {
    		int x; cin >> x;
    		a[i].emplace_back(x);
    		rep[x] = i;
    	}
    }

    FOR(i, 1, m) {
    	int u, v; cin >> u >> v;
    	int w = 1;
    	if (rep[u] == rep[v] and rep[u] != 0) w = 0;
    	g[u].emplace_back(v, w);
    	g[v].emplace_back(u, w);
    }


    unordered_set<int> case1 = cal(1, 2, 3);
    unordered_set<int> case2 = cal(2, 1, 3);
    unordered_set<int> case3 = cal(3, 1, 2);

    if (len(case1) <= len(case2) and len(case1) <= len(case3)) {
    	cout << len(case1) __ ;
    	for(const int &val : case1) cout << val ___ ;
    } else if (len(case2) <= len(case1) and len(case2) <= len(case3)) {
    	cout << len(case2) __ ;
    	for(const int &val : case2) cout << val ___ ;
    } else if (len(case3) <= len(case2) and len(case3) <= len(case1)) {
    	cout << len(case3) __ ;
    	for(const int &val : case3) cout << val ___ ;
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
