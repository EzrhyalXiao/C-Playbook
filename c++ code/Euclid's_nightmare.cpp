// https://codeforces.com/contest/1466/problem/F
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<bitset>
#include<vector>
#include<string>
#include<set>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rpe(i,a,b) for(int i=a;i>=b;--i)
#define pts putchar('\n')
#define ptc putchar(' ')
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
const int inf=0x3f3f3f3f;
const int maxn=5e5+9;
const int mod=1e9+7;
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

int T;
int n,m;
int fa[maxn];
ll ans=0;
vector<int>G;
int find(int x){return fa[x]==x? fa[x]:fa[x]=find(fa[x]);}
inline ll qpow(ll a,ll b){
	ll sum=1;
	while(b){
		if(b&1) sum=(sum*a)%mod;
		a=a*a%mod;b>>=1;
	}
	return sum;
}
int main(){ll tmp,x,y,a,b;
	T=1;
	while(T--){
		n=read(),m=read();
		rep(i,1,m+1) fa[i]=i;
		rep(i,1,n){
			tmp=read();
			if(tmp==1) x=read(),y=m+1;
			else x=read(),y=read();
			a=find(x),b=find(y);
			if(a==b) continue;
			fa[a]=b;
			G.pb(i);
		}
		print(qpow(2,G.size()));ptc;print(G.size());pts;
		int k=G.size();
		rep(i,0,k-1) print(G[i]),ptc; 
	}
	return 0;
}