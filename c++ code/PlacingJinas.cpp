// https://codeforces.com/contest/1696/problem/E
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
const ll N=4e5;
const int maxn=N+9;
const int inf=0x7f7f7f7f;
const ll linf=1e18;
const int maxm=4*N+9;
const int mod=1e9+7;
const int base=31;
const double eps=1e-4;
 
 
int n;
int a[maxn];
struct combinatorial{
	ll inv[maxn],fac[maxn];
	int qpow(ll a,ll b){
		ll c=1;
		while(b){
			if(b&1) c=c*a%mod;
			a=1LL*a*a%mod;b>>=1;
		}
		return c;
	}
	void build(){
		fac[0]=1;
		rep(i,1,N) fac[i]=fac[i-1]*i%mod;
		inv[N]=qpow(fac[N],mod-2)%mod;
		rpe(i,N-1,0) inv[i]=inv[i+1]*(i+1)%mod;
	}
	ll C(int a,int b){
		if(b==0) return 1;
		return fac[a]*inv[b]%mod*inv[a-b]%mod;
	}
}com;
 
 
void solve(){
	cin>>n;n++;
	com.build();
	rep(i,1,n) cin>>a[i];
	ll ans=0;
	rep(i,1,n){
		ans+=com.C(i+a[i]-1,i);
		//cout<<com.C(i+a[i]-1,i)<<endl;
		ans%=mod;
	}
	cout<<ans;
}
 
int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
//	freopen("1.out","w",stdout);
#endif
	int T=1;
	//cin>>T;
	while(T--){
		solve();
	}
	return 0;
}