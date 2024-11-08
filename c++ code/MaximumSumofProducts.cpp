// https://codeforces.com/contest/1519/problem/D
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rpe(i,a,b) for(int i=a;i>=b;--i)
#define pts putchar('\n')
#define ptc putchar(' ')
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
const int inf=0x7f7f7f7f;
const int maxn=2e5+9;
const int maxm=2e2+9;
const double PI=3.1415926;
const double eps=1e-7;
const int mod=1e9+7;
const int base=131;
const int N=1e6;
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
int T;
int n;
ll a[maxn],b[maxn],c[maxn];
ll ans=0;
int main(){
#ifndef ONLINE_JUDGE
    freopen("in0.txt","r",stdin);
#endif
	T=1;
	while(T--){
		n=read();
		rep(i,1,n) a[i]=read();
		rep(i,1,n) b[i]=read(),c[i]=1LL*b[i]*a[i];
		rep(i,1,n) c[i]+=c[i-1];
		ans=c[n];
		rep(i,1,n){
			ll tmp=0;
			int l,r;l=r=i;
			while(l>1&&r<n){
				l--;r++;
				tmp+= a[r]*b[l]+a[l]*b[r] - a[l]*b[l] -a[r]*b[r];
				ans=max(ans,tmp+c[n]);
			}
		}
		rep(i,1,n-1){
			ll tmp=0;
			int l=i+1,r=i;
			while(l>1&&r<n){
				l--;r++;
				tmp+= a[r]*b[l]+a[l]*b[r] - a[l]*b[l] -a[r]*b[r];
				ans=max(ans,tmp+c[n]);
			}
		}
		print(ans);pts;
	}
    return 0;
}