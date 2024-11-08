// https://codeforces.com/gym/103446/problem/H
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rpe(i,a,b) for(int i=a;i>=b;--i)
#define pts putchar('\n')
#define ptc putchar(' ')
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,ll>P;
const int inf=2e9;
const ll linf=1e18;
const double PI=3.1415926;
const double eps=1e-5;
const ull base=131;
const int N=2e5;
const ll mod=998244353;
namespace IO{
    ll read(){	
		ll a=1,b=0;char c=getchar();
		while(c>'9'||c<'0'){if(c=='-')a=-1;c=getchar();} 
		while(c>='0'&&c<='9'){b=(b<<3)+(b<<1)+c-'0';c=getchar();}
		return a*b ;
	}
	void print (ll x){
		if(x<0) putchar('-'),x=-x;
		if(x>9) print(x/10);
		putchar(x%10+'0');
	} 
}
using namespace IO;	


int n,m,q;
int a[N+9];
ll sum[N+9];
struct Edge{
	int u,v,w;
	bool operator < (Edge a){
		return w<a.w;
	}
}G[N+9];
vector<int>T[N+9];
int fa[N+9];
ll val[N+9];
int gr[20][N+9];
int find(int x){return x==fa[x]? x:fa[x]=find(fa[x]);}
void dfs(int now,int f){
	gr[0][now]=f;sum[now]=a[now];
	for(auto x:T[now]){
		dfs(x,now);
		sum[now]+=sum[x];
	}
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
#endif
	n=read(),m=read(),q=read();
	rep(i,1,n) a[i]=read(),fa[i]=i;
	rep(i,n,n<<1) fa[i]=i;
	rep(i,1,m){
		int u,v,w;
		u=read(),v=read(),w=read();
		G[i]=(Edge){u,v,w};
	}
	sort(G+1,G+1+m);
	int nn=n;
	rep(i,1,m){
		int u=find(G[i].u),v=find(G[i].v);
		if(u!=v){
			++nn;
			fa[u]=fa[v]=nn;
			T[nn].pb(u);T[nn].pb(v);
			val[nn]=G[i].w;
		}
	}
	dfs(nn,0);
	rep(j,1,18){
		rep(i,1,nn){
			gr[j][i]=gr[j-1][gr[j-1][i]];
		}
	}
	val[0]=linf;
	while(q--){
		int x=read();
		ll k=read();
		ll now=k+sum[x];
		int last=0;
		while(last!=x){
			last=x;
			rpe(i,18,0){
				if(gr[i][x]==0) continue;
				if(val[gr[i][x]]<=now) x=gr[i][x];
			}
			now=k+sum[x];
		}
		print(now);pts;
	}
	return 0;
} 