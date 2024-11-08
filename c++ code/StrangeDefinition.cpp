// https://codeforces.com/contest/1471/problem/D
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
const int maxn=3e5+9;
const int maxm=1e6+9;
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
int n,q;
int a[maxn];
ll b[maxn];
ll w;
int main(){int tmp,num;
	T=read();
	while(T--){
		n=read();
		rep(i,1,n){
			b[i]=1;
			tmp=read();
			for(int j=2;j*j<=tmp;++j){
				if(tmp%j==0){
					num=0;
					while(tmp%j==0) num++,tmp/=j;
					if(num&1) b[i]*=j;
				}
			}
			if(tmp>1) b[i]*=tmp;
		}
		sort(b+1,b+1+n);
		int ans1=0,ans2=0,num=1;b[n+1]=0;
		rep(i,1,n){
			if(b[i]==b[i+1]) num++;
			else {
				ans1=max(ans1,num);
				if( (!(num&1)) || b[i]==1 )ans2+=num;
				num=1;
			}
		}
		ans2=max(ans2,ans1);
		q=read();
		while(q--){
			w=read();
			if(w) print(ans2);
			else print(ans1);
			pts;
		}
	}
	return 0;
}