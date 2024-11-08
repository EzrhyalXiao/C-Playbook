// https://codeforces.com/contest/1650/problem/G
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rpe(i,a,b) for(int i=a;i>=b;--i)
#define pts putchar('\n')
#define ptc putchar(' ')
#define pb push_back 
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int N=2e5;
const int maxn=N+9;
const int inf=0x7f7f7f7f;
const int maxm=20*N+9;
const int mod=1e9+7;;

int n,m,s,t;
vector<int>G[maxn];

void bfs(int now,vector<int>&dis,vector<int>&f){
	queue<int>q;q.push(now);
	f[now]=1;dis[now]=0;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(auto y:G[x]){
			if(dis[y]==-1) {dis[y]=dis[x]+1;q.push(y);}
			if(dis[y]==dis[x]+1) {f[y]+=f[x];f[y]%=mod;}
		}
	}		
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
	//freopen("2.out","w",stdout);
#endif
	int cse;cin>>cse;
	while(cse--){getchar();
		cin>>n>>m;
		cin>>s>>t;
		rep(i,1,m){
			int x,y;cin>>x>>y;
			G[x].pb(y);G[y].pb(x);
		}
		vector<int>ds(n+1,-1),fs(n+1,0),dt(n+1,-1),ft(n+1,0);
		bfs(s,ds,fs);
		bfs(t,dt,ft);
		ll ans=0,dist=ds[t];
		rep(i,1,n){
			for(auto j:G[i]){
				if(ds[i]+dt[j]==dist&&ds[i]==ds[j]){
					ans=(ans+1LL*fs[i]*ft[j])%mod;
				}
			}
		}
		cout<<(ans+fs[t])%mod<<endl;
		rep(i,1,n) G[i].clear();
	}
	return 0;
}