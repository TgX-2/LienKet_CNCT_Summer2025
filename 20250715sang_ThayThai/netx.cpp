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
vector<int> g[maxn];

int scc = 0, cnt = 0, low[maxn], num[maxn];
bool deleted[maxn];
stack<int> s;

int idx[maxn];
set<int> cg[maxn];

void dfs(int u, int pre) {
    low[u] = num[u] = ++cnt;
    s.push(u);
    for(const int &v : g[u]) if (v != pre) {
        if (deleted[v]) continue;
        if (num[v]) mini(low[u], num[v]);
        else {
            dfs(v, u);
            mini(low[u], low[v]);
        }
    }
    if (low[u] == num[u]) {
        scc++;
        int v;
        do {
            v = s.top();
            idx[v] = scc;
            s.pop();
            deleted[v] = 1;
        } while(v != u);
    }
}

int inn[maxn];


void process() {
	cin >> n >> m;
	FOR(i, 1, m) {
		int u, v; cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}    

	dfs(1, 0);

	if (scc == 1) return cout << 0, void();	

	int m = scc;
	FOR(i, 1, n) {
		for(const int &j : g[i]) {
			if (idx[i] != idx[j]) {
				cg[idx[i]].insert(idx[j]);
				inn[idx[i]]++;
			}
		}
	}



	int cnt = 0;
	FOR(i, 1, m) if (inn[i] == 1) {
		cnt++;
	}

	cout << cnt - cnt / 2;
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    if (fopen("temp.inp", "r")) {
        freopen("temp.inp", "r", stdin);
        freopen("temp.ans", "w", stdout);
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