// https://codeforces.com/contest/1139/problem/E
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rpe(i,a,b) for(int i=a;i>=b;--i)
#define pts putchar('\n')
#define py putchar(' ')
#define pb push_back 
#define pty puts("YES")
#define ptn puts("NO")
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int N=5e3;
const int maxn=2*N+9;
const int inf=0x7f7f7f7f;
const ll linf=1e18;
const int maxm=4*N+9;
const int mod=1e9+7;
const int base=31;
const double eps=1e-4;

int n,d,m;
int p[maxn],c[maxn];

int k[maxn],is[maxn];
int vis[maxn];
int match[maxn];

int ans[maxn];
vector<int>G[maxn];
inline void add(int x,int y){G[x].pb(y);}

int dfs(int now){
	if(vis[now]) return 0;
	vis[now]=1;
	for(auto x:G[now]){
		if(match[x]==-1||dfs(match[x])){
			match[x]=now;
			return 1;
		}
	}
	return 0;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
//	freopen("1.out","w",stdout);
#endif
	cin>>n>>d;
	rep(i,1,n) cin>>p[i],match[i]=-1;
	match[0]=-1;
	rep(i,1,n) cin>>c[i];
	cin>>m;
	rep(i,1,m){
		cin>>k[i];is[k[i]]=1;
	}
	rep(i,1,n){
		if(!is[i]) add(p[i],c[i]);
	}
	rpe(i,m,1){
		ans[i]=ans[i+1];
		while(1){
			rep(i,0,n) vis[i]=0;
			if(dfs(ans[i])) ans[i]++;
			else break;
		}
		add(p[k[i]],c[k[i]]);
	}
	rep(i,1,m) cout<<ans[i]<<endl;
	return 0;
}