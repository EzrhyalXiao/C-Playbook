// https://codeforces.com/contest/1654/problem/D
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
const ll linf=1e18;
const int maxm=4*N+9;
const int mod=998244353;

int n;
struct node{int a,b,c;};
vector<node>G[maxn];



bool vis[maxn];
int prime[maxn],num=0,from[maxn];
vector<P>pr[maxn];
ll ans,sum;

int S[maxn],s[maxn];

void pre(){
	rep(i,2,N){
		if(!vis[i]){
			prime[++num]=i;from[i]=i;
		}
		rep(j,1,num){
			if(1LL*i*prime[j]>N) break;
			vis[i*prime[j]]=1;
			from[i*prime[j]]=prime[j];
		}
	}
	rep(i,2,N){
		int now=i,last=from[i],x=0;
		while(now!=1){
			x++;now/=from[now];
			if(from[now]!=last){
				pr[i].pb({last,x});
				x=0;last=from[now];
			}
		}
	}
}

void add(int i){
	for(auto x:pr[i]){
		s[x.first]+=x.second;
		S[x.first]=max(S[x.first],s[x.first]);
	}
}
void del(int i){
	for(auto x:pr[i]){
		s[x.first]-=x.second;
	}
}
void dfs(int now,int fa){
	for(auto x:G[now]){
		if(x.a==fa) continue;
		add(x.b);
		del(x.c);
		dfs(x.a,now);
		del(x.b);
		add(x.c);
	}
}


ll qpow(ll a,ll b){
	ll sum=1;
	while(b){
		if(b&1) sum=sum*a%mod;
		a=a*a%mod;b>>=1;
	}
	return sum;
}

void Dfs(int now,int fa,ll Snow){
	ans = ans+Snow;ans%=mod;
	for(auto x:G[now]){
		if(x.a==fa) continue;
		Dfs(x.a,now,Snow*x.c%mod*qpow(x.b,mod-2)%mod);
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
	//freopen("2.out","w",stdout);
#endif
	pre();
	int cse=1;cin>>cse;
	while(cse--){
		scanf("%d",&n);
		rep(i,1,n-1){
			int u,v,x,y;
			scanf("%d %d %d %d",&u,&v,&x,&y);
			int c=__gcd(x,y);x/=c;y/=c;
			G[u].pb({v,x,y});G[v].pb({u,y,x});
		}	
		dfs(1,0);
		sum=1;ans=0;
		rep(i,1,n) {
			if(S[i]) sum=sum*qpow(i,S[i])%mod;
		}
		Dfs(1,0,sum);
		cout<<ans<<endl;

		rep(i,1,n) G[i].clear(),S[i]=0;
	}
	return 0;
}