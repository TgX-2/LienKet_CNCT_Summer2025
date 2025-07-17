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
const int inf = 1e4+9;
const ll oo = 1e18l+7;
const int M = 5e5+6;
const int N = 2e5+6;
const int LOG = 31 - __builtin_clz(N);
 
struct Edge{
    int v;
    ll flow, cap;
};
 
struct Dinic{
    int n, m, s, t, work[N], d[N];
    vector<Edge> e;
    vi adj[N];
 
    void init(int _n, int _s, int _t){
        n = _n, s = _s, t = _t;
    }
 
    void AddEdge(int u, int v, ll c1){
        e.pb({v, 0, c1});
        adj[u].pb(e.size() - 1);
        e.pb({u, 0, 0});
        adj[v].pb(e.size() - 1);
    }
 
    bool bfs(){
        for(int i = 1; i <= n; i++) d[i] = 0;
        d[s] = 1;
        queue<int> q;
        q.push(s);
        while(!q.empty()){
            int k = q.front(); q.pop();
            for(int u : adj[k]){
                int v = e[u].v;
                if(e[u].cap > e[u].flow && d[v] == 0){
                    d[v] = d[k] + 1;
                    q.push(v);
                }
            }
        }
        return d[t] > 0;
    }
 
    int dfs(int u, ll flow){
        if(u == t) return flow;
        for(int &z = work[u]; z < (int)adj[u].size(); z++){
            int i = adj[u][z];
            int v = e[i].v;
            if(e[i].cap > e[i].flow && d[v] == d[u] + 1){
                ll tmp = dfs(v, min(flow, e[i].cap - e[i].flow));
                if(tmp){
                    e[i].flow += tmp;
                    e[i ^ 1].flow -= tmp;
                    return tmp;
                }
            }
        }
        return 0;
    }
 
    int getFlow(){
        int res = 0;
        while(bfs()){
            for(int i = 1; i <= n; i++) work[i] = 0;
            while(ll delta = dfs(s, inf)) res += delta;
        }
        //for(int i = 0; i < e.size(); i += 2) cout << e[i].flow << endl;
        return res;
    }
};
 
Dinic Flow;
int numNode = 0;
 
struct Trie{
    struct Node{
        int child[2], val, in, out, dir;
    } 
    node[1 << 20];
 
    int cur = 0;
 
    inline int newNode(int dir){
        int i = ++cur;
        memset(node[i].child, 0, sizeof node[i].child);
        node[i].in = ++numNode;
        node[i].out = ++numNode;
        node[i].val = inf;
        node[i].dir = dir;
        return i;
    }
 
    int add(int u, const string &s, int dir){
        int pos = u;
        for(char x : s){
            int c = x - '0';
            if(!node[pos].child[c]){
                node[pos].child[c] = newNode(dir);
                if(dir == 0) Flow.AddEdge(node[pos].out, node[cur].in, inf);
                else Flow.AddEdge(node[cur].in, node[pos].out, inf);
            }
            pos = node[pos].child[c];
        }
        return pos;
    }
 
    int get(int u, const string &s){
        int pos = u;
        for(char x : s){
            int c = x - '0';
            if(!node[pos].child[c]) return -1;
            pos = node[pos].child[c];
        }
        return pos;
    }
 
    void build(){
        for(int i = 1; i <= cur; i++){
            int u = node[i].in, v = node[i].out;
            if(node[i].dir == 0) Flow.AddEdge(u, v, node[i].val);
            else Flow.AddEdge(v, u, node[i].val);
        }
    }
} trie;
 
int n, m;
string s[N], rv[N];
 
void inp(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> s[i];
}
 
void proc(){
    int S = trie.newNode(0), T = trie.newNode(1);
    for(int i = 1; i <= n; i++){
        trie.add(S, s[i], 0);
        rv[i] = s[i];
        reverse(all(rv[i]));
        trie.add(T, rv[i], 1);
    }
    cin >> m;
    while(m--){
        int c, w;
        string z;
        cin >> c >> z >> w;
        if(c == 1){
            int pos = trie.get(S, z);
            if(pos != -1) mini(trie.node[pos].val, w);
        }
        else{
            reverse(all(z));
            int pos = trie.get(T, z);
            if(pos != -1) mini(trie.node[pos].val, w);
        }
    }
 
    trie.build();
 
    for(int i = 1; i <= n; i++){
        bool ok = true;
        for(int j = 1; j < i; j++) if(s[i] == s[j]) ok = false;
        if(ok) Flow.AddEdge(trie.node[trie.get(S, s[i])].out, trie.node[trie.get(T, rv[i])].out, inf);
    }
 
    Flow.init(numNode + 1, trie.node[S].in, trie.node[T].in);
    int flow = Flow.getFlow();
    cout << (flow >= inf ? -1 : flow);
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