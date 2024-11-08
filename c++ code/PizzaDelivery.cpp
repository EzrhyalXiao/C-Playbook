// LV 4
// https://codeforces.com/gym/101986/problem/F
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int maxn=1e5+9;
const ll linf = 1e18;
const int inf = 1e9;
 
struct Graph{
    bool vis[maxn];
    vector<ll>dis;
 
    struct Edge{int v,w,id;};
 
    struct node{
        ll dis;int id;
        bool operator < (const node &a)const{
            return dis>a.dis;
        }
    };
    priority_queue<node>q;
    vector<Edge>G[maxn];
 
    int n,m;
    int dfn[maxn],low[maxn],timee;
    int bcc_cnt;
 
    bool isBridge[maxn<<1];
    bool visNode[maxn],visEdge[maxn<<1];
 
    void add(int u,int v,int w,int id){
        G[u].push_back({v,w,id});
    }
    inline void clear(){rep(i,1,n) G[i].clear();}
    void Dijk(int st){
        while(!q.empty()) q.pop();
        rep(i,1,n) vis[i]=0;
        dis.clear();
        dis.resize(n+1,linf);
        dis[st]=0;
        q.push((node){0,st});
        while(!q.empty()){
            int u=q.top().id;q.pop();
            if(vis[u]) continue;
            vis[u]=1;
            for(auto x:G[u]){
                int w=x.w,v=x.v;
                if(dis[v]>dis[u]+w){
                    dis[v]=dis[u]+w;
                    q.push((node){dis[v],v});
                } 
            }
        }
    }
 
 
    void tarjan(int now,int fa){
        dfn[now]=low[now]=++timee;
        for(auto x:G[now]){
            int to = x.v;
            if(to==fa) continue;
            if(!dfn[to]) {
                tarjan(to,now);
                low[now]=min(low[now],low[to]);
                if(low[to]>dfn[now]){
                    isBridge[x.id]=1;
                    bcc_cnt++;
                }
            }
            else low[now]=min(low[now],dfn[to]);
        } 
    }
    void getBcc(){
        rep(i,1,n){
            if(!dfn[i]) tarjan(i,-1);
        }
    }
 
}G1,G2,G3;
 
int n,m;
 
 
int main(){
    scanf("%d %d",&n,&m);
    rep(i,1,m){
        int u,v,w;scanf("%d %d %d",&u,&v,&w);
        G1.add(u,v,w,i);
        G2.add(v,u,w,i);
    }
    G1.n=n;G1.m=m;
    G2.n=n;G2.m=m;
    G1.Dijk(1);
    G2.Dijk(2);
    ll shortPath = G1.dis[2];
    rep(u,1,n){
        for(auto x:G1.G[u]){
            int v=x.v,w=x.w;
            if(G1.dis[u]+G2.dis[v]+w == shortPath){
                G3.add(u,v,w,x.id);
                G3.add(v,u,w,x.id);
            }
        }
    }
    G3.n=n;G3.m=m;
    G3.tarjan(1,0);
    vector<string>ans(m+1);
    rep(u,1,n){
        for(auto x:G1.G[u]){
            int v=x.v,w=x.w;
            if(G1.dis[v] + G2.dis[u] + w <shortPath){
                ans[x.id] = "HAPPY";
            }else if(G3.isBridge[x.id]){
                ans[x.id] = "SAD";
            }
            else ans[x.id] = "SOSO";
        }
    }
    rep(i,1,m) cout<<ans[i],puts("");
    return 0;
}