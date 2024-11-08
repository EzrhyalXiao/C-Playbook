// https://codeforces.com/contest/1634/problem/E
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rpe(i,a,b) for(int i=a;i>=b;--i)
#define pts putchar('\n')
#define ptc putchar(' ')
#define pb push_back 
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int N=3e5;
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

int m;
vector<P>G[maxn];
map<int,int>mp,s;
vector<int>ans[maxn];
int is[maxn];

void dfs(int now,int flag){
	while(is[now]){
		is[now]--;
		auto v=G[now][is[now]];
		auto &x = ans[min(now,v.first)][v.second];
		if(x==-1){
			x=flag;dfs(v.first,flag^1);
		}
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
#endif
	m=read();int cnt=m;
	rep(i,1,m){
		int n=read();
		ans[i].resize(n+1,-1);
		rep(j,1,n) {
			int u=read();
			if(!mp[u]) mp[u]=++cnt;
			u=mp[u];s[u]++;
			G[i].pb(P(u,j));
			G[u].pb(P(i,j));
			is[i]++;is[u]++;
		}
	}	
	for(auto x:s){
		if(x.second&1) {puts("NO");return 0;}
	}
	puts("YES");
	rep(i,1,m) dfs(i,0);
	rep(i,1,m){
		int u=ans[i].size();
		rep(j,1,u-1){
			putchar(ans[i][j]? 'L':'R');
		}
		pts;
	}
    return 0;
}