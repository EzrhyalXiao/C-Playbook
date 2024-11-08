// https://codeforces.com/contest/1602/problem/D
#include<bits\stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rpe(i,a,b) for(int i=a;i>=b;--i)
#define pts putchar('\n')
#define ptc putchar(' ')
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>P;
const int inf=0x7f7f7f7f;
const ll linf=1e18;
const int maxn=3e5+9;
const int maxm=(1<<13);
const double PI=3.1415926;
const double eps=1e-5;
const ll mod=998244353;
const int base=131;
const int N=1e6;

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

int n;
int a[maxn],b[maxn];
vector<int>G[maxn<<2],W[maxn<<2];
int num;
int root;
int lson[maxn<<2],rson[maxn<<2];

void link(int u,int v,int val){
	G[u].pb(v);W[u].pb(val);
}

void build(int &o,int l,int r){
	if(l==r){
		o=l;return;
	}
	if(!o) o=++num;
	int mid=(l+r)>>1;
	build(lson[o],l,mid);
	build(rson[o],mid+1,r);
	link(o,lson[o],0);link(o,rson[o],0);
}

void Add(int o,int l,int r,int L,int R,int pos){
	if(L<=l && r<=R) {link(pos,o,1);return;}
	int mid=(l+r)>>1;
	if(L<=mid)Add(lson[o],l,mid,L,R,pos);
	if(R>mid) Add(rson[o],mid+1,r,L,R,pos);
}

int dis[maxn<<2],fa[maxn<<2];
bool vis[maxn<<2];
struct node{int u,v;};
priority_queue<node>q;
bool operator < (node a,node b){return a.v>b.v;}

void Debug(){
	int a;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in0.txt","r",stdin);
#endif
	num=n=read();
	rep(i,1,n) a[i]=read();
	rep(i,1,n) b[i]=read();
	build(root,1,n);
	rpe(i,n,1){
		Add(root,1,n, max(i-a[i],0), i, i+num);
		if(i-a[i]<=0) link(i+num,0,1);
		link(i,min(i+b[i],n)+num,0);
	}
	rep(i,0,num+n) dis[i]=inf;
	dis[n+num]=0;q.push(node{n+num,0});
	while(!q.empty()){
		node x=q.top();q.pop();
		if(vis[x.u]) continue;
		vis[x.u]=1;
		if(x.u==4) Debug();
		for(int i=0,k=G[x.u].size();i<k;++i){
			int v=G[x.u][i],w=W[x.u][i];
			if(dis[v]>dis[x.u]+w){
				dis[v]=dis[x.u]+w;
				fa[v]=x.u;
				if(!vis[v]) q.push((node){v,dis[v]});
			}
		}
	}
	if(dis[0]==inf) puts("-1");
	else {
		print(dis[0]);pts;
		int  now=0;
		vector<int>ans;
		while(now!=n+num) {
			if(now<=n) ans.pb(now);
			now=fa[now];
		}
		reverse(ans.begin(),ans.end());
		for(auto x:ans) print(x),ptc;
	}
    return 0;
} 