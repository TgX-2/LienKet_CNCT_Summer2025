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
int a[5];
int getint(int l, int r) {
    int res = 0;
    for(int i = 0; i <= 3; i++) 
        res = (res << 15) ^ (rand() & ((1 << 15) - 1));
    return l + rand() % (r - l + 1);
}

bool ask(int l, int r){
    cout << "? " << l << ' ' << r << endl;
    int tmp; cin >> tmp;
    return tmp;
}

void bs(int l, int r){
    if(l > r) return;
    if(l == r){
        if(ask(l, r)){
            a[0] = l - 1, a[1] = l + 1;
            return;
        }
    }
    int mid = (l + r) >> 1;
    if(ask(l, mid)){
        a[0] = l - 1, a[1] = mid + 1;
        bs(l, mid);
    }
    else bs(mid + 1, r);
}

void process(){
    bs(intmin, intmax);
    while(1){
        int i = getint(0, 1);
        if(ask(a[i], a[i]) == 0){
            cout << "! " << a[1 - i] << endl;
            return;
        }
        else{
            int id = a[i];
            a[0] = id - 1;
            a[1] = id + 1;
        }
    }
}

// void process() {
//  	int l = -1e9, r = 1e9;
//  	int ans = 0;
//  	while(l <= r) {
//  		if ((r - l + 1) <= 3) {
//  			while(1) {
//  				int r = getint(l, r);

//  			}
//  		}
//  		int mid = (l + r) >> 1;
//  		cout << "? " << l << " " << mid << endl;
//  		int ret; cin >> ret;
//  		if (ret == 1) {
//  			l--;
//  			r = mid + 1;
//  		} else {
//  			r++;
//  			l = mid - 1;
//  		}
//  	}   
// }



/*-----------------------------*/
______________TgX______________ {
	srand(time(NULL));
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