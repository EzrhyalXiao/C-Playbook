// https://codeforces.com/contest/1612/problem/D
#include<cstdio>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include <unordered_map>
#include<vector>
#include<set>
#include<cmath>
#include<bitset>
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
const int maxn=1e5+9;
const int maxm=4e5+9;
const double PI=3.1415926;
const double eps=1e-5;
const ll mod=998244353;
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

ll x;

ll solve(ll a,ll b){
	if(a==0||b==0) return 0;
	if(x>a) return 0;
	if(x==a||x==b) return 1;
	if(a==b) return 0;
	if(a-b>b) {
		if(a%b==x%b) return 1;
		return solve(b,a%b);
	}
	else{
		b=a-b;
		if(x==b) return 1;
		if(a%b==x%b) return 1;
		return solve(b,a%b);
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
#endif
	int cse=read();
	ll a,b;
	while(cse--){
		a=read(),b=read(),x=read();
		if(a<b) swap(a,b);
		if(solve(a,b)) puts("YES");
		else puts("NO");
	}
    return 0;
} 