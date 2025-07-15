/*-----------------------------
        Author : TgX.2
       11Ti - K28 - CHV
-----------------------------*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC optimize("O1")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,mmx,abm")
 
#include<bits/stdc++.h>
using namespace std;
 
static struct FastInput {
    static constexpr int BUF_SIZE = 1 << 20;
    char buf[BUF_SIZE];
    size_t chars_read = 0;
    size_t buf_pos = 0;
    FILE *in = stdin;
    char cur = 0;
    
        inline char get_char() {
        if (buf_pos >= chars_read) {
        chars_read = fread(buf, 1, BUF_SIZE, in);
        buf_pos = 0;
        buf[0] = (chars_read == 0 ? -1 : buf[0]);
        }
        return cur = buf[buf_pos++];
    }
    
    inline void tie(int) {}
    
    inline explicit operator bool() {
        return cur != -1;
    }
    
    inline static bool is_blank(char c) {
        return c <= ' ';
    }
    
    inline bool skip_blanks() {
        while (is_blank(cur) && cur != -1) {
        get_char();
        }
        return cur != -1;
    }
    
    inline FastInput& operator>>(char& c) {
        skip_blanks();
        c = cur;
        return *this;
    }
    
    inline FastInput& operator>>(string& s) {
        if (skip_blanks()) {
        s.clear();
        do {
            s += cur;
        } while (!is_blank(get_char()));
        }
        return *this;
    }
    
    template <typename T>
    inline FastInput& read_integer(T& n) {
        // unsafe, doesn't check that characters are actually digits
        n = 0;
        if (skip_blanks()) {
        int sign = +1;
        if (cur == '-') {
            sign = -1;
            get_char();
        }
        do {
            n += n + (n << 3) + cur - '0';
        } while (!is_blank(get_char()));
        n *= sign;
        }
        return *this;
    }
    
    template <typename T>
    inline typename enable_if<is_integral<T>::value, FastInput&>::type operator>>(T& n) {
        return read_integer(n);
    }
    
    #if !defined(_WIN32) | defined(_WIN64)
    inline FastInput& operator>>(__int128& n) {
        return read_integer(n);
    }
    #endif
    
    template <typename T>
    inline typename enable_if<is_floating_point<T>::value, FastInput&>::type operator>>(T& n) {
        // not sure if really fast, for compatibility only
        n = 0;
        if (skip_blanks()) {
        string s;
        (*this) >> s;
        sscanf(s.c_str(), "%lf", &n);
        }
        return *this;
    }
    } fast_input;
    
    #define cin fast_input
    
    static struct FastOutput {
    static constexpr int BUF_SIZE = 1 << 20;
    char buf[BUF_SIZE];
    size_t buf_pos = 0;
    static constexpr int TMP_SIZE = 1 << 20;
    char tmp[TMP_SIZE];
    FILE *out = stdout;
    
    inline void put_char(char c) {
        buf[buf_pos++] = c;
        if (buf_pos == BUF_SIZE) {
        fwrite(buf, 1, buf_pos, out);
        buf_pos = 0;
        }
    }
    
    ~FastOutput() {
        fwrite(buf, 1, buf_pos, out);
    }
    
    inline FastOutput& operator<<(char c) {
        put_char(c);
        return *this;
    }
    
    inline FastOutput& operator<<(const char* s) {
        while (*s) {
        put_char(*s++);
        }
        return *this;
    }
    
    inline FastOutput& operator<<(const string& s) {
        for (int i = 0; i < (int) s.size(); i++) {
        put_char(s[i]);
        }
        return *this;
    }
    
    template <typename T>
    inline char* integer_to_string(T n) {
        char* p = tmp + TMP_SIZE - 1;
        if (n == 0) {
        *--p = '0';
        } else {
        bool is_negative = false;
        if (n < 0) {
            is_negative = true;
            n = -n;
        }
        while (n > 0) {
            *--p = (char) ('0' + n % 10);
            n /= 10;
        }
        if (is_negative) {
            *--p = '-';
        }
        }
        return p;
    }
    
    template <typename T>
    inline typename enable_if<is_integral<T>::value, char*>::type stringify(T n) {
        return integer_to_string(n);
    }
    
    #if !defined(_WIN32) || defined(_WIN64)
    inline char* stringify(__int128 n) {
        return integer_to_string(n);
    }
    #endif
    
    template <typename T>
    inline typename enable_if<is_floating_point<T>::value, char*>::type stringify(T n) {
        sprintf(tmp, "%.17f", n);
        return tmp;
    }
    
    template <typename T>
    inline FastOutput& operator<<(const T& n) {
        auto p = stringify(n);
        for (; *p != 0; p++) {
        put_char(*p);
        }
        return *this;
    }
} fast_output;
 
#define cout fast_output
#define endl '\n'

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
int n, m;
vector<int> a[4];
int rep[maxn];
vector<pair<int, int>> g[maxn];

int dis[maxn], trace[maxn];
vector<int> dijk(int x, int y) {
	FOR(i, 0, n + 1) {
		dis[i] = intmax;
		trace[i] = 0;
	}

	queue<int> q;

	for(const int &i : a[x]) {
		dis[i] = 0;
		q.push(i);
		trace[i] = -1;
	}

	while(!q.empty()) {
		int u = q.front(); q.pop();

		for(const pair<int, int> &val : g[u]) {
			int v = val.fi, w = val.se;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				trace[v] = u;
				q.push(v);
			}
		}
	}

	vector<int> path;
	int cur = a[y][0];
	while(1) {
		if (cur == -1) break;
		if (rep[cur] == 0) path.pb(cur);
		cur = trace[cur];
	}
	return path;
}

set<int> cal(int x, int y, int z) {
	set<int> ans;
	vector<int> d1 = dijk(x, y);
	vector<int> d2 = dijk(x, z);
	for(const int &val : d1) ans.insert(val);
	for(const int &val : d2) ans.insert(val);
	return ans;
}

void process() {
    cin >> n >> m;

    FOR(i, 1, 3) {
    	int xx; cin >> xx;
    	FOR(j, 1, xx) {
    		int x; cin >> x;
    		a[i].pb(x);
    		rep[x] = i;
    	}
    }

    FOR(i, 1, m) {
    	int u, v; cin >> u >> v;
    	int w = 1;
    	if (rep[u] == rep[v] and rep[u] != 0) w = 0;
    	g[u].pb({v, w});
    	g[v].pb({u, w});
    }


    set<int> case1 = cal(1, 2, 3);
    set<int> case2 = cal(2, 1, 3);
    set<int> case3 = cal(3, 1, 2);

    if (len(case1) <= len(case2) and len(case1) <= len(case3)) {
    	cout << len(case1) __ ;
    	for(const int &val : case1) cout << val ___ ;
    } else if (len(case2) <= len(case1) and len(case2) <= len(case3)) {
    	cout << len(case2) __ ;
    	for(const int &val : case2) cout << val ___ ;
    } else if (len(case3) <= len(case2) and len(case3) <= len(case1)) {
    	cout << len(case3) __ ;
    	for(const int &val : case3) cout << val ___ ;
    }
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
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
void dijkstra()
{
    queue<int> q;
    q.push(1);
    memset(f, 0x3f, sizeof f);
    f[1] = 0;
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (auto v:a[u])
            if (f[v.fi] > f[u] + v.se)
            {
                f[v.fi] = f[u] + v.se;
                q.push(v.fi);
            }
    }

===============================*/
