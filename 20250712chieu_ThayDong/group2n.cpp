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

const int maxn = 1e6 + 7;
int n, a[maxn];

vector<int> snt;
vector<int> odd, even;
vector<bool> check(2000006, 1);
void sieve() {
	check[0] = check[1] = 0;
	for(int i = 2; i <= 2000000; i++) {
		if (check[i] == 1) {
			snt.pb(i);
			for(int j = i * i; j <= 2000000; j += i) 
				check[j] = 0;
		}
	}
}

bool vis[maxn];
int mat[maxn];
vector<int> g[maxn];

bool match(int i) {
	if (vis[i]) return 0;
	vis[i] = 1;
	for(const int &j : g[i]) {
		if (mat[j] == 0 or (match(mat[j]) == 1)) {
			mat[j] = i;
			return 1;
		}
	}
	return 0;
}

set<int> cc;

bool cmp(const int &i, const int &j) {
	return (a[i] > a[j]);
}

void maxpair() {
	int cnt = 0;

	for(const int &i : odd) if (mat[i] == 0) {
		memo(vis, 0);
		if (match(i)) cnt++;
	}

	// cout << cc __ ;

	for(const int &i : even) if (mat[i]){
		if (a[i] == 1) cc.erase(i);
		if (a[mat[i]] == 1) cc.erase(mat[i]);
	}

	// cout << cc __ ;


	cout << cnt + (len(cc) / 2) __ ;

	for(const int &i : even) if (mat[i])
		cout << i _ mat[i] __ ;

	int pre = 0;
	for(const int &val : cc) {
		if (pre == 0) {
			pre = val;
		} else {
			cout << pre _ val __ ;
			pre = 0;
		}
	}
}

int b[maxn];

void sub4() {
    cout << n / 2 __ ;
    int i = n - (n & 1);
    while(i > 1) {
        int k = i * 2;
        int x = lower_bound(all(snt), k) - snt.begin();
        x--;
        int l = snt[x] - i, r = i;
        i = l - 1;
        while(l < r) {
        	cout << b[l] _ b[r] __ ;
            l++, r--;
        }
    }
}

void process() {
	sieve();

    cin >> n;
    FOR(i, 1, n) {
    	cin >> a[i];
    	b[a[i]] = i;
    	if (a[i] == 1) cc.insert(i);

    	if (a[i] % 2 == 0) even.pb(i);
    	else odd.pb(i);
    }

    if (n > 1000)  {
    	sub4();
    	return;
    }

    sort(all(odd), cmp);

    for(const int &i : odd) for(const int &j : even) {
    	if (check[a[i] + a[j]] == 1) {
    		g[i].pb(j);
    		g[j].pb(i);
    	}
    }


    maxpair();
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