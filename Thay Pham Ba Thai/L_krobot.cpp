
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
const int inf = 1e7+9;
const ll oo = 1e18l+7;
const int M = 5e5+6;
const int N = 1e3+3;
const int LOG = 31 - __builtin_clz(N);
 
struct Edge{
	int v;
	ll flow, cap;
};
 
struct Dinic{
	int n, m, s, t, work[M], d[M];
	vector<Edge> e;
	vi adj[M];
 
	int mxFlow = 0;
 
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
		while(bfs()){
			for(int i = 1; i <= n; i++) work[i] = 0;
			while(ll delta = dfs(s, inf)) mxFlow += delta;
		}
		//for(int i = 0; i < e.size(); i += 2) cout << e[i].flow << endl;
        return mxFlow;
	}
};
 
Dinic Flow;
 
int n, m, k, cnt[N][N];
vi adj[N];
pii edge[N];
bool vis[N];
int node = 0, id[2][100005], cntE = 0;
 
void inp(){
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
    	int u, v; cin >> u >> v;
    	if(cnt[u][v] == 0){
    		adj[u].pb(v);
    		edge[++cntE] = {u, v};
    	}
    	cnt[u][v]++;
    }
}
 
void dfs(int u){
	vis[u] = true;
	for(int v : adj[u]){
		if(vis[v]) continue;
		dfs(v);
	}
}
 
void proc(){
	dfs(1);
    if(!vis[n]){
    	cout << -1;
    	return;
    }
 
    int S = ++node, T = ++node, tm = 0;
    while(true){
    	int cur = tm & 1;
    	for(int i = 1; i <= n; i++) id[cur][i] = ++node;
     	if(tm == 0) Flow.AddEdge(S, id[cur][1], k);
    	else{
    		int pre = cur ^ 1;
    		Flow.AddEdge(id[cur][n], T, k);
    		for(int i = 1; i <= cntE; i++){
	    		int u = edge[i].fi, v = edge[i].se;
	    		Flow.AddEdge(id[pre][u], id[cur][v], cnt[u][v]);
	    	}
    	}
 
    	Flow.init(node, S, T);
    	int flow = Flow.getFlow();
    	if(flow >= k){
    		cout << tm;
    		return;
    	}
    	tm++;
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