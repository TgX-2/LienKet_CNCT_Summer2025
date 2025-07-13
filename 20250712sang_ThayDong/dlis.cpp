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
const int N = 1e3+4;
const int LOG = 31 - __builtin_clz(N);

int n, m;
string s;
int len[N][N], dp[N][50];

void inp(){
    cin >> n;
  	cin >> s;
  	s = ' ' + s;
  	m = sqrt(n) + 1;
}

bool check(int l, int r, int k){
	if(len[l][r] >= k) return false;
	return s[l + len[l][r]] < s[r + len[l][r]];
}

void proc(){
    for(int i = n; i >= 1; i--){
        for(int j = n; j > i; j--) len[i][j] = (s[i] == s[j] ? len[i + 1][j + 1] + 1 : 0);
    }
	for(int i = 1; i <= n; i++){
		for(int k = 1; k <= i; k++) dp[i][k] = 1;
		for(int k = 1; k <= min(i / 2, m); k++){
			for(int j = k; j <= i - k; j++) if(check(j - k + 1, i - k + 1, k)) maxi(dp[i][k], dp[j][k] + 1);
			if(k > 1 && s[i - k + 1] != '0'){
				for(int j = k - 1; j <= i - k; j++) maxi(dp[i][k], dp[j][k - 1] + 1);
			}
		}	
	}
	int res = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++) maxi(res, dp[i][j]);
	}
	cout << res;
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
