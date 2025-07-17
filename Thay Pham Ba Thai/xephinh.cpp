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
const int maxn = 3;
const string goal = "012345678";

// struct Node {
// 	string state;
// 	int g, h;

// 	int dist(const string &s) {
// 		int ans = 0;
// 		FOR(i, 0, 8) {
// 			if (s[i] == '0') continue;
// 			int val = s[i] - '1';
// 			ans += abs(i / 3 - val / 3) + abs(i % 3 - val % 3);
// 		}
// 		return ans;
// 	}

// 	Node(string s, int g) : state(s), g(g)  {
// 		h = dist(s);
// 	}

// 	int f() const { return g + h; }
// 	bool operator <(const Node& other) const {
// 		return f() > other.f();
// 	}
// };

// int dist(const string &s) {
// 	int ans = 0;
// 	FOR(i, 0, 8) {
// 		if (s[i] == '0') continue;
// 		int val = s[i] - '1';
// 		ans += abs(i / 3 - val / 3) + abs(i % 3 - val % 3);
// 	}
// 	return ans;
// }

// int invcnt(const string& s) {
//     string t;
//     for (char c : s) if (c != '0') t += c;

//     int inv = 0;
//     for (int i = 0; i < t.size(); ++i) {
//         for (int j = i + 1; j < t.size(); ++j) {
//             if (t[i] > t[j]) ++inv;
//         }
//     }
//     return inv;
// }

// int base;

// bool check(const string& start) {
//     return (base % 2 == invcnt(start) % 2);
// }


// int sol(const string &start) {
// 	priority_queue<Node> q;
// 	unordered_set<string> vis;
// 	q.push(Node(start, 0));

// 	while(!q.empty()) {
// 		Node top = q.top(); q.pop();
// 		string s = top.state;
// 		int val = top.g;

// 		if (s == goal) return val;
// 		if (vis.count(s)) continue;
// 		vis.insert(s);

// 		int z = s.find('0');
// 		int x = z / 3, y = z % 3;

//         FOR(i, 0, 3) {
//         	int xx = x + dx[i];
//         	int yy = y + dy[i];

//         	if (xx < 0 or yy < 0 or xx > 2 or yy > 2) continue;

//        		int zz = xx * 3 + yy;

//             string ns = s;
//             swap(ns[z], ns[zz]);
//             if (!vis.count(ns)) {
//                 q.push(Node(ns, val + 1));
//             }
//         }
// 	}
// 	return -1;
// }	

unordered_map<string, int> dis;

void bfs() {
	priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> q;
	q.push({0, goal});
	dis[goal] = 0;

	while(!q.empty()) {
		pair<int, string> top = q.top(); q.pop();

		int cost = top.fi;
		string cur = top.se;
		if (cost > dis[cur]) continue;

		int pos = 0;
		FOR(i, 0, 8) if (cur[i] == '0') {
			pos = i;
			break;
		}

		int x = pos / 3;
		int y = pos % 3;

		FOR(i, 0, 3) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 0 or yy < 0 or xx > 2 or yy > 2) continue;

			int npos = xx * 3 + yy;
			string ncur = cur;
			swap(ncur[npos], ncur[pos]);

			// if (dis.count(ncur) and dis[ncur] > dis[cur] + 1) {
			// 	dis[ncur] = dis[cur] + 1;
			// 	q.push({dis[ncur], ncur});
			// } else {
			if (!dis.count(ncur)) {
				dis[ncur] = dis[cur] + 1;
				q.push({dis[ncur], ncur});
			}
		}
	}
}

void process() {
    int t; cin >> t;
    bfs();
    while(t--) {
    	string s = "";
    	FOR(i, 1, 9) {
    		int x; cin >> x;
    		s = s + (char)(x + '0');
    	}

    	if (dis.count(s)) {
    		cout << dis[s] __ ;
    	} else cout << -1 __ ;
    		
    }

}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
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