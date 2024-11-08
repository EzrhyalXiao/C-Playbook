// https://codeforces.com/contest/1670/problem/E
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rpe(i,a,b) for(int i=a;i>=b;--i)
#define pts putchar('\n')
#define py putchar(' ')
#define pb push_back 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const ll N=2e5;
const int maxn=N+9;
const int inf=0x7f7f7f7f;
const ll linf=1e18;
const int maxm=4*N+9;
const int mod=1e9+7;
const int base=31;
const double eps=1e-4;

int n,p;
vector<P>G[maxn];
int val[maxn],Val[maxn];
int num=1;
int ans[maxn];
void dfs(int now,int fa,int sign){
	for(auto &x:G[now]){
		if(x.first==fa) continue;
		Val[x.second]=num|(sign<<p);
		val[x.first]=Val[x.second]^n;
		num++;
		dfs(x.first,now,sign^1);
	}
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
//	freopen("1.out","w",stdout);
#endif
	int cse;cin>>cse;
	while(cse--){
		scanf("%d",&p);n=(1<<p);num=1;
		rep(i,1,n-1){
			int u,v;scanf("%d %d",&u,&v);
			G[u].pb({v,i});G[v].pb({u,i});
		}
		dfs(1,0,1);val[1]=n;
		puts("1");
		rep(i,1,n) printf("%d ",val[i]);
		pts;
		rep(i,1,n-1) printf("%d ",Val[i]);
		pts;
		rep(i,1,n) G[i].clear();
	}
	return 0;
}
