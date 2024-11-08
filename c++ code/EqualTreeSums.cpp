// https://codeforces.com/contest/1656/problem/E
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rpe(i,a,b) for(int i=a;i>=b;--i)
#define pts putchar('\n')
#define ptc putchar(' ')
#define pb push_back 
#define pty puts("YES")
#define ptn puts("NO");
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
//typedef pair<ll,ll> P;
const int N=1e5;
const int maxn=N+9;
const int inf=0x7f7f7f7f;
const ll linf=1e18;
const int maxm=4*N+9;
const int mod=1e9+7;
const int base=31;
const double eps=1e-4;

int n;
vector<int>G[maxn];
int col[maxn];

void dfs(int now,int fa,int c){
	col[now]=c;
	for(auto x:G[now]){
		if(x==fa) continue;
		dfs(x,now,1-c);
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
//	freopen("1.out","w",stdout);
#endif
	int cse;cin>>cse;
	while(cse--){
		cin>>n;
		rep(i,1,n-1){
			int u,v;
			cin>>u>>v;
			G[u].pb(v);G[v].pb(u);
		}
		dfs(1,0,0);
		rep(i,1,n){
			if(col[i]) cout<<(int)G[i].size()<<" ";
			else cout<<-(int)G[i].size()<<" ";
		}
		pts;
		rep(i,1,n) G[i].clear();
	}
	return 0;
}