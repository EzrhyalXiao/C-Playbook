// https://codeforces.com/contest/1611/problem/F
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rpe(i,a,b) for(int i=a;i>=b;--i)
#define pts putchar('\n')
#define ptc putchar(' ')
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>P;
const int inf=0x7f7f7f7f;
const ll linf=1e18;
const int maxn=2e5+9;
const int maxm=2e7+9;
const double PI=3.1415926;
const double eps=1e-5;
const int base=131;
const int N=1e6;
const ll mod=1e9+7;

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
ll s,a[maxn];
P ans;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
#endif
	int cse=read();
	while(cse--){
		n=read();s=read();
		rep(i,1,n) a[i]=read();
		int l=1;
		ans.first=0,ans.second=-1;
		ll sum=0;
		rep(i,1,n){
			sum+=a[i];
			if(sum+s>=0) {
				if(i-l>ans.second-ans.first){
					ans=P(l,i);
				}
			}
			else{
				while(sum+s<0&&l<=i){
					sum-=a[l];l++;
				}
			}
		}
		if(ans.first==0) puts("-1");
		else printf("%d %d\n",ans.first,ans.second);
	}
	return 0;
} 