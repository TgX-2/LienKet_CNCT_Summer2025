#include <bits/stdc++.h>

using namespace std;

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());

#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define rf if(fopen(name".inp", "r")) {freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout);}
//#define in ({int x = 0; int c = getchar(), n = 0; for(; !isdigit(c); c = getchar()) n = (c == '-'); for(; isdigit(c); c = getchar()) x = x * 10 + c - '0'; n ? -x : x;})

#define bit(i, mask) (((mask) >> (i)) & 1)
#define on(i, mask) ((mask) | (1LL << (i)))
#define off(i, mask) ((mask) & (~(1LL << (i))))

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
#define ub(x, i) upper_bound(all(x), i) - x.begin()
#define lb(x, i) lower_bound(all(x), i) - x.begin()

#define name ""

template<typename T1, typename T2> bool mini(T1 &a, T2 b)
    {if(a > b) a = b; else return 0; return 1;}
template<typename T1, typename T2> bool maxi(T1 &a, T2 b)
    {if(a < b) a = b; else return 0; return 1;}

const int mod = 1e9+7;
const int inf = 1e9+9;
const ll oo = 1e18l+7;
const int M = 5e5+6;
const int N = 1e3+6;
const int LOG = 31 - __builtin_clz(N);

int n, m, a[N][25];
pii b[N];
int f[N];
vi ans[N];

void inp(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++) cin >> a[i][j];
    	sort(a[i] + 1, a[i] + m + 1);
    	for(int j = 1; j <= m; j++) b[i].fi += a[i][j];
    	b[i].se = i;
    }
}

bool check(int u, int v){
	for(int i = 1; i <= m; i++){
		if(a[u][i] > a[v][i]) return false;
	}
	return true;
}

void proc(){
	sort(b + 1, b + n + 1);
	for(int i = 1; i <= n; i++){
		f[i] = 1;
		for(int j = 1; j < i; j++){
			if(check(b[j].se, b[i].se)) maxi(f[i], f[j] + 1);
		}
	}
	int k = 1;
	for(int i = 1; i <= n; i++){
		maxi(k, f[i]);
		ans[f[i]].pb(b[i].se);
	}
	cout << k << endl;
	for(int i = 1; i <= k; i++){
		cout << len(ans[i]) << ' ';
		for(int x : ans[i]) cout << x << ' ';
		cout << endl;
	}
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
