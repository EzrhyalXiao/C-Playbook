// https://codeforces.com/contest/1626/problem/D
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rpe(i,a,b) for(int i=a;i>=b;--i)
#define pts putchar('\n')
#define ptc putchar(' ')
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll>P;
const int inf=1e9;
const ll linf=1e18;
const int maxn=2e5+9;
const int maxm=1e6+9;
const double PI=3.1415926;
const double eps=1e-5;
const ull base=131;
const int N=2e5;
const ll mod=998244353;
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

int n;
int num[N+9];
int sum[N+9];
int to[N+9],is[N+9];
//到距离最近的2的次方的距离
int a[N+9];

int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
#endif
	memset(to,-1,sizeof(to));
	int now=1;
	to[0]=1;is[0]=1;
	while(now<=N){
		is[now]=now;
		to[now]=0;now<<=1;
	}
	to[N]=now-N;
	rpe(i,N,1){
		if(to[i]!=-1) continue;
		to[i]=to[i+1]+1;
		is[i]=is[i+1];
	}
	int cse=read();
	while(cse--){
		n=read();
		rep(i,1,n) {
			int x=read();
			num[x]++;a[i]=x;
		}
		sort(a+1,a+1+n);
		int m=unique(a+1,a+1+n)-a-1;
		rep(i,1,m){
			sum[i]=sum[i-1] + num[a[i]];
		}
		int ans=inf,tans,Sum=sum[m];
		//O(n*log(2e5)*log(n)*2)
		rep(i,1,m){
			tans=to[sum[i]];
			int y=is[Sum-sum[i]];
			ans=min(ans,tans+to[Sum-sum[i]]+1);
			while(y){
				y>>=1;
				int l=i+1,r=m,pos=l-1;
				while(l<=r){
					int mid=(l+r)>>1;
					if(sum[mid] - sum[i] <= y) pos=mid,l=mid+1;
					else r=mid-1;
				}
				ans=min(ans,tans+to[sum[pos]-sum[i]] + to[Sum-sum[pos]]);
			}
			y=is[Sum-sum[i]];
			while(y){
				y>>=1;
				int l=i+1,r=m,pos=m;
				while(l<=r){
					int mid=(l+r)>>1;
					if(sum[m] - sum[mid] <= y) pos=mid,r=mid-1;
					else l=mid+1;
				}
				ans=min(ans,tans+to[sum[pos]-sum[i]] + to[Sum-sum[pos]]);
				//cout<<sum[pos-1]-sum[i]<<"ASDASD"<<to[sum[pos-1]-sum[i]];
			}
		}
		print(ans);
		pts;
		rep(i,1,n) num[i]=sum[i]=0;
	}
	return 0;
} 