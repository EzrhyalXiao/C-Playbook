// https://codeforces.com/contest/1634/problem/F
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rpe(i,a,b) for(int i=a;i>=b;--i)
#define pts putchar('\n')
#define ptc putchar(' ')
#define pb push_back 
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int N=3e5;
const int maxn=N+9;
const int inf=0x7f7f7f7f;
const int maxm=20*N+9;
namespace IO{
    ll read(){	
		ll a=1,b=0;char c=getchar();
		while(c>'9'||c<'0'){if(c=='-')a=-1;c=getchar();} 
		while(c>='0'&&c<='9'){b=(b<<3)+(b<<1)+c-'0';c=getchar();}
		return a*b ;
	}
	void print (ll x){
		if(x<0) putchar('-'),x=-x;
		if(x>9) print(x/10);
		putchar(x%10+'0');
	} 
}
using namespace IO;	

int n,q,mod;
int c[maxn],d[maxn];
int sum=0;
ll fib[maxn];

void update(int pos,int val){
	sum-=(d[pos])? 1:0;
	d[pos]=(d[pos]+val);
	if(d[pos]>=mod) d[pos]-=mod;
	sum+=(d[pos])? 1:0;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
#endif
	ios_base::sync_with_stdio(false);
	fib[1]=1;fib[2]=1;int tmp=N+2;
	//n=read(),q=read(),mod=read();
	cin>>n>>q>>mod;
	//scanf("%d %d %d",&n,&q,&mod);
	rep(i,3,maxn-1) fib[i]=(fib[i-1]+fib[i-2])%mod; 
	rep(i,1,n) cin>>c[i],c[i]%=mod;
	rep(i,1,n){
		int x;cin>>x;
		c[i]=(c[i]-x+mod)%mod;
	}
	d[1]=c[1];d[2]=(c[2]-c[1]+mod)%mod;
	rep(i,3,n) d[i] = ((ll)c[i] - c[i-1] - c[i-2]+2*mod)%mod,d[i]=(d[i]+mod)%mod;
	rep(i,1,n) sum+=(d[i])? 1:0;
	while(q--){
		char opt;int l,r;
		cin>>opt>>l>>r;
		if(opt=='A'){
			update(l,1);
			if(r+1<=n) update(r+1,mod-fib[r-l+2]);
			if(r+2<=n) update(r+2,mod-fib[r-l+1]);
		}
		else{
			update(l,mod-1);
			if(r+1<=n) update(r+1,fib[r-l+2]);
			if(r+2<=n) update(r+2,fib[r-l+1]);
		}
		puts(sum? "NO":"YES");
	}
	return 0;
}