// https://codeforces.com/contest/1592/problem/E
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
const int maxn=1e6+9;
const int maxm=4e5+9;
const double PI=3.1415926;
const double eps=1e-5;
const ll mod=1e9+7;
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

int n;
int a[maxn];

int And[maxn];
int Xor[maxn];
int last[maxn];

int ans=0;

int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
   // freopen("5.out","w",stdout);
#endif
	n=read();
	rep(i,1,n) a[i]=read();	
	rpe(j,19,0){
		rep(i,1,n){
			And[i] = And[i-1] + ((a[i]>>j)&1);
			Xor[i] ^= ((And[i]&1)<<j);
		}
		memset(last,-1,sizeof(last));
		last[0] = 0;
		rep(i,1,n){
			if(last[Xor[i]]==-1) last[Xor[i]]=i;
			else{
				int pos=last[Xor[i]];
				if(And[i] - And[pos] == i-pos) ans=max(ans,i-pos);
				else last[Xor[i]]=i;
			}
		}	
	}
	print(ans);
    return 0;
} 