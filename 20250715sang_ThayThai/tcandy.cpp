#include <bits/stdc++.h>
using namespace std;
using ll = long long;


ll modPow(ll a, ll b, ll m) {
    ll res = 1 % m;
    a %= m;
    while (b > 0) {
        if (b & 1) res = (int)res * a % m;
        a = (int)a * a % m;
        b >>= 1;
    }
    return res;
}


ll extGcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) { x = 1; y = 0; return a; }
    ll x1, y1;
    ll g = extGcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}


ll modInv(ll a, ll m) {
    ll x, y;
    ll g = extGcd(a, m, x, y);
    if (g != 1) return -1; 
    x %= m;
    if (x < 0) x += m;
    return x;
}


pair<ll,ll> factorialDecomp(ll n, ll p, ll exp_pe, ll mod, 
                            const vector<ll>& F, const vector<pair<ll,ll>>& Ff, ll mx) {
    ll k = 0;
    ll a = 1;
    
    while (n >= mx) {
        ll t = n / p;
        ll b = n / mod;
        k += t;
        
        ll pw = 1;
        if ((b & 1) && (p != 2 || exp_pe == 2)) {
            
            pw = mod - 1; 
        }
        
        ll idx = n - b * mod;
        a = ( (int)a * F[idx] ) % mod;
        if (pw == mod - 1) a = ( (int)a * pw ) % mod;
        n = t;
    }
    
    k += Ff[n].first;
    a = ( (int)a * Ff[n].second ) % mod;
    return {k, a};
}

int main() {
        freopen("temp.inp", "r", stdin);
        freopen("temp.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m;
    int T;
    cin >> n >> m >> T;
    
    long long N = n + m - 1;
    long long K = n; 
    
    int tempT = T;
    vector<pair<int,int>> factors;
    for (int p = 2; p * p <= tempT; ++p) {
        if (tempT % p == 0) {
            int e = 0;
            while (tempT % p == 0) {
                tempT /= p;
                e++;
            }
            factors.emplace_back(p, e);
        }
    }
    if (tempT > 1) factors.emplace_back(tempT, 1);

    
    long long result = 0;
    long long curMod = 1;

    for (auto &f : factors) {
        ll p = f.first;
        int e = f.second;
        ll mod = 1;
        for (int i = 0; i < e; i++) mod *= p;
        
        ll mx = mod;
        vector<ll> F(mx);
        vector<pair<ll,ll>> Ff(mx);
        F[0] = 1;
        Ff[0] = {0, 1};
        for (ll i = 1; i < mx; i++) {
            
            if (i % p != 0) {
                F[i] = ( (int)F[i-1] * i ) % mod;
            } else {
                F[i] = F[i-1];
            }
            
            ll ti = i;
            ll tk = 0;
            while (ti % p == 0) {
                ti /= p;
                tk++;
            }
            Ff[i].first = Ff[i-1].first + tk;
            Ff[i].second = ( (int)Ff[i-1].second * ti ) % mod;
        }
        
        auto tN = factorialDecomp(N, p, e, mod, F, Ff, mx);
        auto tK = factorialDecomp(K, p, e, mod, F, Ff, mx);
        auto tNK = factorialDecomp(N-K, p, e, mod, F, Ff, mx);
        ll expN = tN.first, valN = tN.second;
        ll expK = tK.first, valK = tK.second;
        ll expNK = tNK.first, valNK = tNK.second;
        ll expRes = expN - expK - expNK;
        ll rmod = 0;
        if (expRes >= e) {
            
            rmod = 0;
        } else {
            
            ll denom = ( (int)valK * valNK ) % mod;
            ll invDen = modInv(denom, mod);
            ll res = ( (int)valN * invDen ) % mod;
            
            res = ( (int)res * modPow(p, expRes, mod) ) % mod;
            rmod = res;
        }
        
        if (curMod == 1) {
            result = rmod;
            curMod = mod;
        } else {
            
            ll diff = (rmod - result % mod + mod) % mod;
            ll invCur = modInv(curMod % mod, mod);
            ll tval = ( (int)diff * invCur ) % mod;
            result = result + curMod * tval;
            curMod *= mod;
            result %= curMod;
        }
    }

    
    if (T == 1) cout << 0;
    else cout << (result % T + T) % T;

    return 0;
}
