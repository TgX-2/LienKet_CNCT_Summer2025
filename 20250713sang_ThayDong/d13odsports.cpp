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
int n, v[maxn], s[maxn];


// int l[maxn], r[maxn];
// bool check(int taim) {
// 	FOR(i, 0, n + 1) l[i] = r[i] = 0;

// 	FOR(i, 1, n) {
// 		l[i] = max(1LL, v[i] - s[i] / taim);
// 		r[i] = min(n, v[i] + s[i] / taim);
// 	}

// 	sort(l + 1, l + 1 + n);
// 	sort(r + 1, r + 1 + n);
	
// 	FOR(i, 1, n)
// 		if (l[i] > i or r[i] < i) return 0;
	
// 	return 1;
// }

vector<int> vv[maxn];
bool check(int m){
    for(int i = 1; i <= n; i++) vv[i].clear();
    for(int i = 1; i <= n; i++){
        int dist = s[i] / m;
        int l = max(1LL, v[i] - dist);
        int r = min(n, v[i] + dist);
        vv[l].pb(r);
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 1; i <= n; i++){
        for(auto it : vv[i]) pq.push(it);

        if(!pq.empty() && pq.top() < i) return false;
        if(pq.empty()) return false;
        pq.pop();
    }
    return true;
}

void process() {
    cin >> n;
    FOR(i, 1, n) cin >> v[i];
    FOR(i, 1, n) cin >> s[i];

    int l = 1, r = 10000000;
    int ans = 0;

    while(l <= r) {
    	int mid = (l + r) >> 1;

    	if (check(mid)) {
    		ans = mid;
    		l = mid + 1;
    	} else r = mid - 1;
    }

    int q; cin >> q;
    while(q--) {
    	int x; cin >> x;
    	if (x <= ans) cout << 1 ___ ;
    	else cout << 0 ___ ;
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