#include <bits/stdc++.h>
using namespace std;
 
#define fo(i, a, b) for (int i = (a); i < (b); ++i)
#define ll long long
 
const int MX = 81;
ll f[MX], fb[MX], v[MX];
 
void pc() {
    f[0] = 1;
    if (1 < MX) f[1] = 1;
    fo(i, 2, MX) f[i] = f[i-1] + f[i-2];
 
    fo(i, 1, MX) fb[i] = f[i];
 
    if (1 < MX) v[1] = 1;
    if (2 < MX) v[2] = 2;
    fo(k, 3, MX) v[k] = v[k-1] + v[k-2] + f[k-1];
}
 
ll ddg(ll h, int m) {
    if (h < fb[m]) return 0;
    if (m+1 < MX) h = min(h, fb[m+1]-1);
 
    string s;
    ll t = h;
    for (int i = m; i >= 1; --i) {
        if (t >= fb[i]) {
            s += '1';
            t -= fb[i];
        } else {
            s += '0';
        }
    }
    if (s.length() != m) s = string(m - s.length(), '0') + s;
 
    ll dp[MX][2][2][2] = {};
    fo(ti, 0, 2) fo(la, 0, 2) dp[m][ti][la][0] = 1;
 
    for (int i = m-1; i >= 0; --i) {
        fo(ti, 0, 2) {
            fo(la, 0, 2) {
                int ch[2] = {0};
                int nc = 0;
                if (i == 0) {
                    ch[nc++] = 1;
                } else {
                    if (la == 1) {
                        ch[nc++] = 0;
                    } else {
                        ch[nc++] = 0;
                        ch[nc++] = 1;
                    }
                }
                ll ct = 0, sm = 0;
                fo(idx, 0, nc) {
                    int d = ch[idx];
                    if (ti && d > s[i] - '0') continue;
                    bool nt = ti && (d == s[i] - '0');
                    int nl = d;
                    ct += dp[i+1][nt][nl][0];
                    sm += dp[i+1][nt][nl][1] + d * dp[i+1][nt][nl][0];
                }
                dp[i][ti][la][0] = ct;
                dp[i][ti][la][1] = sm;
            }
        }
    }
    return dp[0][1][0][1];
}
 
void cr(ll x, string &s, int &m) {
    m = 1;
    fo(i, 1, MX) {
        if (fb[i] <= x) m = i;
        else break;
    }
    s.clear();
    ll t = x;
    for (int j = m; j >= 1; --j) {
        if (t >= fb[j]) {
            s += '1';
            t -= fb[j];
        } else {
            s += '0';
        }
    }
}
 
main() {
    pc();
    ll n;
    cin >> n;
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
 
    ll F = 0, G = 0;
    int m = 1;
    bool fd = false;
    while (m < MX && F < n) {
        ll cg = f[m-1];
        ll lg = cg * m;
        if (F + lg <= n) {
            ll og = f[m-1];
            if (m - 2 >= 0) og += v[m-2];
            F += lg;
            G += og;
            m++;
        } else {
            ll nf = (n - F) / m;
            if (nf > cg) nf = cg;
            ll lu = nf * m;
            ll lw = fb[m];
            ll hg = lw + nf - 1;
            ll os = 0;
            if (nf > 0) os = ddg(hg, m);
            G += os;
            F += lu;
            if (F < n) {
                ll nn = hg + 1;
                string rs;
                int lr;
                cr(nn, rs, lr);
                ll tc = n - F;
                string pr = rs.substr(0, tc);
                ll op = count(pr.begin(), pr.end(), '1');
                G += op;
                F = n;
            }
            fd = true;
            break;
        }
    }
    cout << G << endl;
    return 0;
}