// https://codeforces.com/gym/103428/problem/G
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
const int maxm=4*N+9;
const int mod=998244353;
const int base=31;
const double eps=1e-4;

int n,m;
set<int>s;
int cnt[maxn];
ll fac[maxn],inv[maxn];


ll qpow(ll a,ll b){
	ll sum=1;
	while(b){
		if(b&1) sum=sum*a%mod;
		a=a*a%mod;b>>=1;
	}
	return sum;
}

ll C(int a,int b){
	if(a==0) return 0;
	if(b>=a) return 1;
	return fac[a]*inv[a-b]%mod*inv[b]%mod;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
//	freopen("1.out","w",stdout);
#endif
	fac[0]=1;
	rep(i,1,N) fac[i]=fac[i-1]*i%mod;
	inv[N] = qpow(fac[N],mod-2);
	rpe(i,N-1,0) inv[i] = inv[i+1] * (i+1)%mod; 
	cin>>n>>m;
	rep(i,1,n){
		int x;cin>>x;
		if(s.find(x)!=s.end()) cnt[x]++;
		else s.insert(x),cnt[x]=1;
	}
	int x=*s.rbegin();
	rep(now,1,m){
		if(now<x) {puts("0");continue;}
		ll ans=1;
		ll tmp=0,id=0;
		for(auto x:s){
			ans=ans * qpow(C(now,x),cnt[x])%mod;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
