// https://codeforces.com/gym/103409/problem/K
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rpe(i,a,b) for(int i=a;i>=b;--i)
#define pts putchar('\n')
#define ptc putchar(' ')
#define pb push_back 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int N=100;
const int maxn=N+9;
const int inf=0x7f7f7f7f;
const ll linf=1e18;
const int maxm=N*N+9;
const int mod=998244353;
const int base=131;

int n,m;
int w[maxm];
int dis[maxn][maxn],Dis[maxn];
int col[maxn][maxn];
vector<int>g[maxn];
int cnt[maxm];

ll cost[maxn];
int vis[maxn];
int maxx=-1;

void dfs(int now,ll d,ll sum){//d为当前距离
	if(d>Dis[now]) return;
	if(d==Dis[now])cost[now]=min(cost[now],sum);
	if(d>=maxx) return;
	for(auto x:g[now]){
		if(vis[x]) continue;
		if(Dis[x]!=Dis[now]+1) continue;
		vis[x]=1;
		int C=col[now][x];
		cnt[C]++;ll val=1LL*cnt[C] *  w[C];
		dfs(x,d+1,sum+1LL*cnt[C]*w[C]);
		vis[x]=0;
		cnt[C]--;
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
	//freopen("2.out","w",stdout);
#endif
	cin>>n>>m;
	rep(i,1,m) cin>>w[i];
	rep(i,1,n) rep(j,1,n) dis[i][j]=maxm;
	rep(i,1,n) dis[i][i]=0;
	rep(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		g[x].pb(y);g[y].pb(x);
		dis[x][y]=dis[y][x]=1;
		col[x][y]=col[y][x]=z;
	}
	rep(k,1,n){
		cost[k]=inf;
		rep(i,1,n){
			rep(j,1,n){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	vis[1]=1;
	rep(i,1,n) Dis[i]=dis[1][i],maxx=max(maxx,Dis[i]);
	dfs(1,0,0);
	rep(i,2,n) cout<<cost[i]<<"\n";
	return 0;
}