// https://codeforces.com/gym/103428/problem/H
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rpe(i,a,b) for(int i=a;i>=b;--i)
#define pts putchar('\n')
#define py putchar(' ')
#define pb push_back 
#define pty puts("YES")
#define ptn puts("NO");
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
const int N=1e5;
const int maxn=N+9;
const int inf=0x7f7f7f7f;
const ll linf=1e18;
const int maxm=10*N+9;
const int mod=998244353;
const int base=31;
const double eps=1e-4;

int last[maxn];
struct Edge{int v,fr,fl;}edge[maxm];
int cnt=1;

void add(int u,int v,int f){
	edge[++cnt]={v,last[u],f};
	last[u]=cnt;
	edge[++cnt]={u,last[v],0};
	last[v]=cnt;
}

int st,ed,num=0;
int dep[maxn],vis[maxn];
queue<int>q;

int bfs(){
	rep(i,1,num) dep[i]=-1;
	while(!q.empty())q.pop();
	q.push(st);dep[st]=1;
	while(!q.empty()){
		int now=q.front();q.pop();
		for(int i=last[now];i;i=edge[i].fr){
			auto x=edge[i];
			if(x.fl>0&&dep[x.v]==-1){
				dep[x.v]=dep[now]+1;
				q.push(x.v);
			}
		}
	}
	return dep[ed]!=-1;
}

int dfs(int now,int lim){
	if(now==ed) return lim;
	int sum=0;
	for(int i=last[now];i;i=edge[i].fr){
		if(edge[i].fl>0&&dep[edge[i].v]==dep[now]+1){
			int tmp=dfs(edge[i].v,min(lim,edge[i].fl));
			if(!tmp) continue;
			edge[i].fl-=tmp;
			edge[i^1].fl+=tmp;
			sum+=tmp;lim-=tmp;
			if(!lim) break;
		}
	}
	if(sum==0) dep[now]=-1;
	return sum;
}

int Dinic(){
	int sum=0;
	while(bfs()) 
		sum+=dfs(st,inf);
	return sum;
}

int n;
int w[300],v[300];

int dis[300][300];
vector<int>G[201];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
	//freopen("1.out","w",stdout);
#endif
	cin>>n;
	int sum=0;
	rep(i,1,n) scanf("%d",&w[i]);
	rep(i,1,n) scanf("%d",&v[i]);
	rep(i,1,n) rep(j,1,n) dis[i][j]=1e9;
	rep(i,1,n-1){
		int u,v;scanf("%d%d",&u,&v);
		dis[u][v]=dis[v][u]=1;
	}
	rep(i,1,n) dis[i][i]=0;
	rep(k,1,n){
		rep(i,1,n){
			rep(j,1,n){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	num=n;st=++num;ed=++num;
	rep(k,1,n){
		rep(i,0,n-1) G[i].clear();
		rep(i,1,n) G[dis[k][i]].pb(i);
		add(k,ed,w[k]);
		rep(i,0,n-1){
			add(st,++num,v[i+1]-v[i]);
			for(auto x:G[i]){
				add(num,x,inf);
			}
			if(i!=0) add(num,num-1,inf);
		}
		sum+=v[n];
	}
	cout<<sum-Dinic();
	return 0;
}

