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
int n;
array<int, 3> a[maxn];
int b[maxn], trace[maxn], cur[maxn];

void process() {
    cin >> n;
    vector<int> val;
    FOR(i, 1, n) {
    	int x, y; cin >> x >> y;
    	if (x > y) swap(x, y);
    	val.push_back(x);
    	val.push_back(y);
    	a[i] = {x, y, i};
    }

    sort(all(val));
    val.erase(unique(all(val)), val.end());
    FOR(i, 1, n) {
    	a[i][0] = lower_bound(all(val), a[i][0]) - val.begin() + 1;
    	a[i][1] = lower_bound(all(val), a[i][1]) - val.begin() + 1;
    }

    sort(a + 1, a + 1 + n);
    int ans = 1;

    FOR(i, 0, n + 1) b[i] = intmax;
    FOR(i, 1, n) {
    	int val = a[i][1], pos = a[i][2];
    	int l = 1, r = n, anss = 1;
    	while(l <= r) {
    		int mid = (l + r) >> 1;
    		if (val < b[mid]) {
    			anss = mid;
    			r = mid - 1;
    		} else l = mid + 1;
    	}
    	b[anss] = val;
    	cur[anss] = pos;
    	trace[pos] = cur[anss - 1];
    	maxi(ans, anss);
    }
    cout << ans __ ;

    int curr = cur[ans];
    vector<int> path;
    FOR(i, 1, ans) {
    	path.push_back(curr);
    	curr = trace[curr];
    }

    reverse(all(path));
    for(const int &v : path) cout << v ___ ;

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
0 2 1 7
1 2 1 2
===============================*/