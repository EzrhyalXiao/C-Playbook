// https://codeforces.com/contest/1629/problem/E
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rpe(i,a,b) for(int i=a;i>=b;--i)
#define pts putchar('\n')
#define ptc putchar(' ')
#define pb push_back 
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int N=1e3;
const int maxn=N+9;
const int maxm=2*N+9;
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
int a[maxn][maxn];
int cnt[maxn][maxn];
int main(){
 #ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
 #endif
	int cse;
	cin>>cse;
	while(cse--){
		n=read();
		rep(i,1,n) rep(j,1,n) a[i][j]=read();
		rep(i,0,n+1) rep(j,0,n+1)cnt[i][j]=0;
		int ans=0;
		rep(i,1,n){
			rep(j,1,n){
				if((cnt[i-1][j]&1)==0){
					ans^=a[i][j];
					cnt[i-1][j]++;
					cnt[i][j-1]++;
					cnt[i][j+1]++;
					cnt[i+1][j]++;
				}
			}
		}
		print(ans);pts;
	/*	puts("###################");
		rep(i,1,n){
			rep(j,1,n){
				print(cnt[i][j]);ptc;
			}
			pts;
		}*/
	}
	return 0;
}