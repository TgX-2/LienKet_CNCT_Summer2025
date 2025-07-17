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
	int n, a[maxn];

	void process() {
	    cin >> n; 
	    int m = n;
	    n = n * 2;

	    FOR(i, 1, n) cin >> a[i];
	    sort(a + 1, a + 1 + n);

	   	if (m % 2 == 1) {
	   		cout << a[m + (m + 1) / 2] __ ;
	   	} else {
	   		cout << (a[m + m / 2] + a[m + (m + 1) / 2]) / 2 __ ;
	   	}

	    FOR(i, 1, n / 2) 
	    	cout << a[i] _ a[n - i + 1] ___ ;
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
	1 1 2
	2 3 4

	===============================*/