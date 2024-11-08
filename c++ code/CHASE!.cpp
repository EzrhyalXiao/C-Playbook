// https://codeforces.com/gym/103428/problem/E
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
int n,k,q;
int w[maxn];
ll a[maxn],b[maxn];
double even;
double dp[200];
ll sum;
ll sa,sb;
ll na,nb;

int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
//	freopen("1.out","w",stdout);
#endif
	cin>>n>>k>>q;
	rep(i,1,n) cin>>w[i],a[i]=w[i];
	sort(a+1,a+1+n);
	rep(i,1,n) b[i]=b[i-1]+a[i];
	sum=b[n];
	even = sum*2.0/n;
	dp[0]=even;sum*=(n-1);
	rep(j,1,k){
		sa=0,sb=0;na=0;
		int pos=n;
		rep(i,1,n){
			if(a[1] + a[i]>=dp[j-1]) {pos=i-1;break;} 
		}
		rep(i,1,n){		
			while(a[i]+a[pos]>=dp[j-1]) pos--;
			if(pos<=i) break;
			sa+=(a[i] * (pos-i)) + b[pos] - b[i];
			na+=(pos-i);
		}
		sb=sum - sa;nb=n*(n-1)/2-na;
		dp[j] = 2.0*sb/n/(n-1) + 2.0*na/n/(n-1) * dp[j-1]; 
	}
	printf("%.10lf\n",dp[k]);
	while(q--){
		int x,y,c;
		cin>>x>>y>>c;
		if(c==0) puts("accept");
		else{
			c--;
			double tmp=w[x]+w[y];
			if(tmp-dp[c]>eps) puts("accept");
			else if(dp[c] - tmp > eps) puts("reselect");
			else puts("both");
		}
	}
	return 0;
}