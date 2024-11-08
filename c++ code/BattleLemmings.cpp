// https://codeforces.com/contest/1420/problem/E
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<queue>
#include<bitset>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rpe(i,a,b) for(int i=a;i>=b;--i)
#define pts putchar('\n')
#define ptc putchar(' ')
typedef long long ll;
typedef unsigned long long ull;
const int inf=0x3f3f3f3f;
const int maxn=82;
const int mod=998244353;
const int base=131;
const double eps=1e-7;

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
inline void DEBUG(ll x){cout<<"asdasd"<<x<<endl;}

int n;
int b[maxn],m=1,c[maxn];
int dp[maxn][maxn][maxn*maxn];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in0.txt","r",stdin);
#endif
	n=read();
	int tmp;bool flag=0;
	rep(i,1,n) {
		tmp=read();
		if(tmp==1) m++;
		else b[m]++;
	}
	rep(i,1,m) c[i]=c[i-1]+b[i];
	memset(dp,0x3f,sizeof(dp));
	dp[0][0][0]=0;
	int num=n*(n-1)/2;
	rep(i,0,m-1){//枚举当前位置
		rep(j,0,c[m]){//当前可用总数量
			rep(opt,0,num){
				if(dp[i][j][opt]==0x3f3f3f3f) continue;
				rep(l,j,c[m]){
					if(opt+abs(l-c[i+1])>num) continue;
					int &tmp=dp[i+1][l][opt+abs(l-c[i+1])];
					tmp=min(tmp,dp[i][j][opt]+(l-j)*(l-j));
				}
			}
		}
	}
	int mn=0x3f3f3f3f;
	rep(i,0,num){
		mn=min(mn,dp[m][c[m]][i]);
		print((c[m]*c[m]-mn)>>1);pts;
	}
    return 0;	
}



