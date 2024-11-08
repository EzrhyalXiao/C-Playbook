// https://codeforces.com/contest/1452/problem/E
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<bitset>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rpe(i,a,b) for(int i=a;i>=b;--i)
#define pts putchar('\n')
#define ptc putchar(' ')
typedef long long ll;
typedef unsigned long long ull;
const int inf=0x3f3f3f3f;
const int maxn=2e5+9;
const int mod=998244353;
const int base=131;

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

int n,m,k;
struct Point{int l,r;}Ar[maxn];
bool operator < (Point a,Point b){
	return a.l+a.r<b.l+b.r;
} 
int su[maxn];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
#endif
	n=read();m=read();k=read();
	rep(i,1,m){
		Ar[i].l=read(),Ar[i].r=read();
	}
	sort(Ar+1,Ar+m+1);
	rep(i,1,n-k+1){
		int cnt=0;
		rep(j,1,m) {
			cnt+=max(0,min(Ar[j].r,i+k-1)-max(Ar[j].l,i)+1);
			su[j]=max(su[j],cnt);
		}
	}
	int ans=0;
	rep(i,1,n-k+1){
		int cnt=0;
		rpe(j,m,1){
			cnt+=max(0,min(Ar[j].r,i+k-1)-max(Ar[j].l,i)+1);
			ans=max(ans,cnt+su[j-1]);
		}
	}
	print(ans);
    return 0;
}



