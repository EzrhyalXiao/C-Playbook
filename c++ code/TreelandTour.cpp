// https://codeforces.com/contest/490/problem/F
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rpe(i,a,b) for(int i=a;i>=b;--i)
#define pts putchar('\n')
#define ptc putchar(' ')
#define pb push_back 
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int N=6e3;
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
int val[maxn];
vector<int>G[maxn];
int ans=0;
int f[maxn];

void dfs(int now,int fa){
	for(auto x:G[now]){
		if(x==fa) continue;
		int pos=lower_bound(f+1,f+1+n,val[x])-f;
		ans=max(ans,pos);
		int tmp=f[pos];
		f[pos]=val[x];
		dfs(x,now);
		f[pos]=tmp;
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
#endif
	n=read();
	rep(i,1,n)val[i]=read();
	rep(i,1,n-1){
		int u=read(),v=read();
		G[u].pb(v);G[v].pb(u);
	}
	rep(i,1,n){
		memset(f,0x3f,sizeof(f));
		f[1]=val[i];
		dfs(i,0);
	}
	print(ans);
    return 0;
}