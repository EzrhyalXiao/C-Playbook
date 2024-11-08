// https://codeforces.com/contest/1582/problem/F2
#include<bits\stdc++.h>
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
const int maxm=(1<<13);
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

int n;
int a[maxn];
bitset<maxm>ans;
vector<int>G[maxm];
int R[maxm];
int main(){
#ifndef ONLINE_JUDGE
    freopen("in0.txt","r",stdin);
#endif
	int cse=1;
	while(cse--){
		n=read();
		rep(i,1,n) a[i]=read();
		rep(i,0,maxm-1) G[i].pb(0),R[i]=maxm-1;
		rep(i,1,n){
			for(auto x:G[a[i]]){
				int to = x^a[i];
				ans[to]=1;
				while(R[to]>a[i]){
					G[R[to]].pb(to);
					R[to]--;
				}
			}
			G[a[i]].clear();
		} 
		ans[0]=1;
		print(ans.count());pts;
		rep(i,0,maxm-1){
			if(ans[i]) print(i),ptc;
		}
	}
    return 0;
} 