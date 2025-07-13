#pragma GCC optimize("O3")

#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
#include<assert.h>

#define lint int64_t

using namespace std;

class Flow{
    
    #define Type int
    
    public:
    
    int n,m,cnt;
    int s,t;
    static const Type inf=1e9;
    
    vector<int> head,to,nxt,dep;
    vector<Type> w;
    
    void init(int n_,int m_,int s_,int t_){
        
        cnt=0;
        
        m_<<=1;
        n=n_,m=m_;
        head.resize(n,-1);
        fill(head.begin(),head.end(),-1);
        to.resize(m);
        nxt.resize(m);
        w.resize(m);
        dep.resize(n);
        
        s=s_,t=t_;
    }
    
    Flow(int n_,int m_,int s_,int t_){
        
        init(n_,m_,s_,t_);
    }
    
    void clear(){
        
        fill(head.begin(),head.end(),-1);
        cnt=0;
    }
    
    void add_edge(int u,int v,Type w_){
        
        to[cnt]=v;
        w[cnt]=w_;
        nxt[cnt]=head[u];
        head[u]=cnt++;
    }
    
    void insert(int u,int v,Type w_){
        
        add_edge(u,v,w_);
        add_edge(v,u,0);
    }
    
    int bfs(){
        
        fill(dep.begin(),dep.end(),0);
        
        queue<int> q;
        
        q.push(s);
        dep[s]=1;
        
        while(!q.empty()){
            
            int u=q.front();
            q.pop();
            
            for(int e=head[u];~e;e=nxt[e]){
                
                int v=to[e];
                
                if(w[e]&&!dep[v]){
                    
                    dep[v]=dep[u]+1;
                    q.push(v);
                }
            }
        }
        
        return dep[t];
    }
    
    Type dfs(int u,Type in=inf){
        
        if(u==t) return in;
        
        Type out=0;
        
        for(int e=head[u];~e&&in;e=nxt[e]){
            
            int v=to[e];
            
            if(w[e]&&dep[v]==dep[u]+1){
                
                Type res=dfs(v,min(w[e],in));
                
                w[e]-=res;
                w[e^1]+=res;
                
                in-=res;
                out+=res;
            }
        }
        if(!out) dep[u]=0;
        return out;
    }
    
    Type getMaxFlow(){
        
        Type ans=0;
        
        while(bfs()){
            
            ans+=dfs(s);
        }
        
        return ans;
    }
    
    #undef Type
};

#define maxn 502

int n,m;
int a[maxn][maxn];
int vis[maxn][maxn];
Flow f(0,0,0,0); 

namespace sub1{
    void move(vector<int> &v){
        int temp=v[0];
        v.erase(v.begin());
        v.push_back(temp);
        return;
    }
    void solve(){
        vector<int> v(n);
        for(int i=0;i<n;i++) v[i] = a[1][i + 1];
        for(int i=0;i<n;i++) {
            if(i > 0){
                for(int j=0;j<n;j++) cout<<v[j]<<" ";
                cout<<"\n";
            }
            move(v);
        }
    }
}

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin>>m >> n;

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            vis[j][a[i][j]]=1;
        }
    }

    if(m == 1){
        sub1::solve();
        return 0;
    }
    
    f.init(2*n+2,n*n+2*n,0,2*n+1);
    
    for(int i=m+1;i<=n;i++){
        
        f.clear();
        
        for(int j=1;j<=n;j++){
            
            for(int i=1;i<=n;i++){
                
                if(!vis[j][i]) f.insert(j,i+n,1);
            }
        }
        
        for(int j=1;j<=n;j++) f.insert(0,j,1);
        for(int j=1;j<=n;j++) f.insert(j+n,2*n+1,1);
        
        f.getMaxFlow();
        
        for(int j=1;j<=n;j++){
            
            for(int e=f.head[j];~e;e=f.nxt[e]){
                
                if(!f.w[e]&&f.to[e]>=n+1&&f.to[e]<=2*n) a[i][j]=f.to[e]-n;
            }
        }
        
        for(int j=1;j<=n;j++){
            
            vis[j][a[i][j]]=1;
        }
    }
    
    for(int i=m + 1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
    
end:
    return 0;
}
