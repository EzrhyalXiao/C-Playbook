// https://codeforces.com/gym/103428/problem/M
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
const int N=2e5;
const int maxn=N+9;
const int inf=0x7f7f7f7f;
const ll linf=1e18;
const int maxm=4*N+9;
const int mod=998244353;
const int base=31;
const double eps=1e-4;



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
	return fac[a]*inv[a-b]%mod*inv[b]%mod;
}

ll solve(ll n,ll m,ll k){
	ll ans=0;
	rep(i,0,m){
		if(k-n*i<0) break;
		if(i&1) ans=(ans+mod-C(m,i)*C(k+m-1-n*i,m-1)%mod)%mod;
		else ans=(ans+C(m,i)*C(k+m-1-n*i,m-1)%mod)%mod;
	}
	return ans;
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
	int cse=1;ll n,m,k;
	while(cse--){
		scanf("%lld%lld%lld",&n,&m,&k);
		printf("%lld\n",(solve(k+1,n-m+1,m) - solve(k,n-m+1,m)+mod)%mod);
	}
	return 0;
}