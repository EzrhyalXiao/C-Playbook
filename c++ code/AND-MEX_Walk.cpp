// https://codeforces.com/contest/1659/problem/E
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rpe(i,a,b) for(int i=a;i>=b;--i)
#define pts putchar('\n')
#define py putchar(' ')
#define pb push_back 
#define pty puts("YES")
#define ptn puts("NO")
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const ll N=2e5;
const int maxn=N+9;
const int inf=0x7f7f7f7f;
const ll linf=1e18;
const int maxm=4*N+9;
const int mod=2;
const int base=31;
const double eps=1e-4;

int n,m;
struct Edge{int u,v,w;}G[maxn];

int fa[40][maxn];
int vis[maxn],even[maxn];
int find(int *f,int x){return f[x]==x? x:f[x]=find(f,f[x]);}
int check(int u,int v){
	rep(i,0,29){
		if(fa[i][find(fa[i],u)] == fa[i][find(fa[i],v)]) return 0;
	}
	if(even[u]) return 1;
	return 2;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
	//freopen("1.out","w",stdout);
#endif
	cin>>n>>m;
	rep(i,1,m){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		G[i]={u,v,w};
	}
	rep(i,0,29) rep(j,1,n) fa[i][j]=j;
	rep(i,0,29){
		rep(j,1,m){
			int u,v,w;
			u=G[j].u,v=G[j].v,w=G[j].w;
			if(w>>i&1){
				fa[i][find(fa[i],u)] = find(fa[i],v); 
			}
		}
	}
	rep(i,1,29){
		rep(i,1,n) vis[i]=0;
		rep(j,1,m){
			int u,v,w;
			u=G[j].u,v=G[j].v,w=G[j].w;
			if(!(w&1)){
				vis[fa[i][find(fa[i],u)]]=1;
				vis[fa[i][find(fa[i],v)]]=1;
			}
		}
		rep(j,1,n) 
			if(vis[fa[i][find(fa[i],j)]]) even[j]=1; 
	}
	int q;cin>>q;
	while(q--){
		int u,v;scanf("%d %d",&u,&v);
		cout<<check(u,v)<<endl;
	}
	return 0;
}
