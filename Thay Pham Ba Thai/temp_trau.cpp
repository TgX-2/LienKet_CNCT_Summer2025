#include <bits/stdc++.h>
using namespace std;

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());

#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define rf if(fopen(name".inp", "r")) {freopen(name".inp", "r", stdin); freopen(name".ans", "w", stdout);}


#define ll long long
#define fi first
#define se second
#define pii pair<int, int>
#define plx pair<ll, int>
#define vi vector<int>
#define vvi vector<vi>
#define all(a) (a).begin(), (a).end()
#define len(x) ((int)(x).size())
#define pb push_back
#define endl '\n'

#define name "temp"

template<typename T1, typename T2> bool maxi(T1 &a, T2 b)
    {if(a < b) a = b; else return 0; return 1;}

const int mod = 1e9+7;
const int inf = 1e9+9;
const ll oo = 1e18l+7;
const int M = 5e5+6;
const int N = 1505;
const int LOG = 31 - __builtin_clz(N);

int n, a[N][N];

void inp(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) cin >> a[i][j];
    }
}

namespace sub1{
    ll sum = 0;
    int dp[N][N];

    void calc(int u, int v){
        for(int i = u; i <= n; i++){
            for(int j = v; j <= n; j++){
                sum -= dp[i][j];
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
                if(i == 1 && j == 1) dp[i][j] = a[i][j];
                sum += dp[i][j];
            }
        }
        cout << sum << endl;
    }

    void solve(){
        for(int i = 0; i <= n; i++) dp[i][0] = dp[0][i] = -inf;
        calc(1, 1);
        for(int i = 1; i <= n; i++){
            char c; cin >> c;
            int u, v; cin >> u >> v;
            a[u][v] += (c == 'U' ? 1 : -1);
            calc(u, v);
        }
    }
}

void proc(){
    sub1::solve();
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    rf

    int test = 1;
    //cin >> test;

    while(test--){
        inp();
        proc();
    }
    
    cerr << "Time elapsed: " << TIME << "s" << endl;
    return 0;
}