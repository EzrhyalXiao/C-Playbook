// https://codeforces.com/contest/1650/problem/F
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
const int inf=0x7f7f7f7f;
const int maxm=20*N+9;
const int mod=1e9+7;;


int n,m;
ll ddl[maxn];
struct node{int id;ll t;int p;};
vector<node>G[maxn];
vector<int>ans;
ll dp[maxn][101];

void cmin(int &x,int y){x=min(x,y);}



bool solve(){
	ll now=0;
	rep(i,1,n){
		int sze=G[i].size();
		rep(j,0,100) rep(l,0,sze) dp[l][j]=inf;
		dp[0][0]=0;
		rep(j,0,sze-1){
			rep(l,0,100) dp[j+1][l]=dp[j][l];
			auto x = G[i][j];
			rep(l,0,100){
				int y=min(100,l+x.p);
				dp[j+1][y]=min(dp[j+1][y],dp[j][l]+x.t);
			}
		}  
		now+=dp[sze][100];
		if(now>ddl[i]) {return 0;}
		int pr=100;
		rpe(j,sze-1,0){
			auto x=G[i][j];
			if(dp[j+1][pr]==dp[j][pr]) continue;
			ans.pb(x.id);
			rep(l,0,100){
				int y=min(100,l+x.p);
				if(y==pr&&dp[j][l]+x.t==dp[j+1][y]){
					pr=l;break;
				}
			}
		}
	}
	return 1;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
	//freopen("2.out","w",stdout);
#endif
	int cse;cin>>cse;
	while(cse--){getchar();
		cin>>n>>m;ans.clear();
		rep(i,1,n) cin>>ddl[i],G[i].clear();
		rep(i,1,m){
			int x,y,z;cin>>x>>y>>z;
			G[x].pb((node){i,y,z});
		}
		if(solve()) {
			cout<<ans.size()<<"\n";
			for(auto x:ans) cout<<x<<" ";
			cout<<"\n";
		}
		else puts("-1");
	}
	return 0;
}