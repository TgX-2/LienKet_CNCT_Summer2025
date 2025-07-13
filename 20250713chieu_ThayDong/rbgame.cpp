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

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int n, m;

bool canbe(const vector<vector<int>> &a) {
	vector<vector<int>> dis(n + 7, vector<int>(m + 7, intmax));
	dis[1][1] = 0;
	priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> q;
	q.push({0, 1, 1});

	while(!q.empty()) {
		array<int, 3> top = q.top(); q.pop();
		int cost = top[0], x = top[1], y = top[2];
		if (cost != dis[x][y]) continue;

		for(int i = 0; i <= 3; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 1 or xx > n or yy < 1 or yy > m) continue;
			if (a[xx][yy] != -1) continue;
			if (dis[xx][yy] > dis[x][y] + 1) {
				dis[xx][yy] = dis[x][y] + 1;
				q.push({dis[xx][yy], xx, yy});
			}
		}
	}
	// for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) cout << dis[i][j] << " \n"[j == m];

	if (dis[n][m] == intmax) return 0;
	return 1;
}

const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};

int dijk(const vector<vector<int>> &a, const vector<pair<int, int>> &sta) {
	vector<vector<int>> dis(n + 7, vector<int>(m + 7, intmax));
	priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> q;
	for(const pair<int, int> &val : sta) {
		int x = val.first, y = val.second;
		dis[x][y] = a[x][y];
		q.push({a[x][y], x, y});
	}

	while(!q.empty()) {
		array<int, 3> top = q.top(); q.pop();
		int cost = top[0], x = top[1], y = top[2];
		if (cost != dis[x][y]) continue;

		for(int i = 0; i <= 7; i++) {
			int xx = x + ddx[i];
			int yy = y + ddy[i];

			if (xx < 1 or xx > n or yy < 1 or yy > m) continue;
			if (a[xx][yy] == -1) continue;

			if (dis[xx][yy] > dis[x][y] + a[xx][yy]) {
				dis[xx][yy] = dis[x][y] + a[xx][yy];
				q.push({dis[xx][yy], xx, yy});
			}
		}
	}

	int ans = intmax;
	for(int j = 2; j <= m; j++) 
		mini(ans, dis[1][j]);
	for(int i = 2; i <= n; i++)
		mini(ans, dis[i][m]);

	// for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++)
	// 	cout << a[i][j] << " \n"[j == m];
	// cout __ ;
	// for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++)
	// 	cout << dis[i][j] << " \n"[j == m];

	return ans;
}

void process() {	
	cin >> n >> m;
    vector<vector<int>> a(n + 7, vector<int>(m + 7));
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) {
    	char x; cin >> x;
    	if (x == '.') a[i][j] = -1;
    	else if (x == '#') a[i][j] = 0;
    	else a[i][j] = (x - '0');
    }

	if (canbe(a)) return cout << -1, void();

	vector<pair<int, int>> pos;

	// pos.pb({10, 7});


	for(int i = 1; i <= n; i++) 
		if (a[i][1] != -1) pos.push_back({i, 1});
	for(int j = 2; j <= m; j++)
		if (a[n][j] != -1) pos.push_back({n, j});

	cout << dijk(a, pos);

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
00100
00000
10001
00000
00100

===============================*/