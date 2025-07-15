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

int n, lim;

bool check(int n){
    while(n > 1 && n % 2 == 0) n /= 2;
    return (n == 1);
}

void move(){
    if(n == 0) return;
    if(n <= lim){
        cout << n << endl;
        return;
    }

    int cnt = 1, m = n;
    while(m % 2 == 0){
        m >>= 1;
        cnt *= 2;
    }
    cout << cnt << endl;
    n -= cnt;
}

void process() {
    cin >> n; lim = n - 1;
    if((__builtin_popcount(n)) == 1) {
        cout << 0 << endl;
        while(n){
            cin >> lim;
            n -= lim;
            move();
        }
        return;
    }
    while(n){
        move();
        if(n > 0){
            cin >> lim;
            n -= lim;
        }
    }
}

// void process() {
//     cin >> n;
//     if (n % 2 == 1) {
//         move();
//     } else {

//     }

    // int n; cin >> n;
    // if (n % 2 == 1) {
    //     int x;
    //     n -= 1;
    //     cout << 1 << endl;
    //     while(cin >> x) {
    //         n -= x;
    //         cout << 1 << endl;
    //         n--;
    //         if (n == 0) break;
    //     }
    // } else {
    //     if ((n / 2) % 2 == 0) {
    //         n -= 4;
    //         cout << 4 << endl;
    //         int x;
    //         while(cin >> x) {
    //             n -= x;
    //             if (x % 2 == 1) {
    //                 cout << 1 << endl;
    //                 n -= 1;
    //             } else {
    //                 cout << 2 << endl;
    //                 n -= 2;
    //             }

    //             if (n == 0) break;
    //         }
    //     } else {
    //         n -= 2;
    //         cout << 2 << endl;
    //         int x;
    //         while(cin >> x) {
    //             n -= x;
    //             if (x % 2 == 1) {
    //                 cout << 1 << endl;
    //                 n -= 1;
    //             } else {
    //                 cout << 2 << endl;
    //                 n -= 2;
    //             }

    //             if (n == 0) break;
    //         }
    //     }
    // }
// }



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



/*
* neu den luot minh ma la so le thi lay 1
* neu cur < pre lay het
* luy thua 2 thi de no di truoc
    * neu no lay so le thi minh bu''
    * neu no lay so chan thi minh lay giong no

* neu so ban dau la so chan
    * neu (n / 2) la chan thi lay 4 dau tien
    * neu (n / 2) la le thi lay so 2 dau tien
*/

/*==============================+
|INPUT                          |
--------------------------------|

================================+
|OUTPUT                         |
--------------------------------|

===============================*/