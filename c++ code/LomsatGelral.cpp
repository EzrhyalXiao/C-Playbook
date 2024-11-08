// https://codeforces.com/contest/600/problem/E
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rpe(i,a,b) for(int i=a;i>=b;--i)
#define pts putchar('\n')
#define ptc putchar(' ')
#define pb push_back 
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int N=1e5;
const int maxn=N+9;
const int maxm=20*N+9;
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
int col[maxn];
vector<int>G[maxn];
int cnt[maxn];
ll ans[maxn];
int son[maxn],sze[maxn];

void dfs1(int now,int fa){
	sze[now]=1;
	for(auto x:G[now]){
		if(x==fa) continue;
		dfs1(x,now);
		sze[now]+=sze[x];
		if(sze[x]>sze[son[now]]) son[now]=x;
	}
}
ll sum;
int maxx,Son;
void add(int now,int fa,int val){
	cnt[col[now]]+=val;
	if(cnt[col[now]]>maxx) maxx=cnt[col[now]],sum=col[now];
	else if(cnt[col[now]]==maxx) sum+=(ll)col[now];
	for(auto x:G[now]){
		if(x==fa||x==Son) continue;
		add(x,now,val);
	}
}

void dfs2(int now,int fa,bool flag){
	for(auto x:G[now]){
		if(x==fa || x==son[now]) continue;
		dfs2(x,now,0);
	}
	if(son[now]) dfs2(son[now],now,1),Son=son[now];
	int ts=sum,tmaxx=maxx;
	add(now,fa,1);
	ans[now]=sum;Son=0;
	if(!flag) add(now,fa,-1),sum=maxx=0;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
#endif
	n=read();
	rep(i,1,n) col[i]=read();
	rep(i,1,n-1){
		int u,v;
		u=read(),v=read();
		G[u].pb(v);G[v].pb(u);
	}
	dfs1(1,0);
	dfs2(1,0,1);
	rep(i,1,n) print(ans[i]),ptc;
    return 0;
}