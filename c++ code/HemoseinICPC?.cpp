// https://codeforces.com/contest/1592/problem/D
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
const int maxn=1e3+9;
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
vector<int>G[maxn];
int maxx;
P g[maxn];int cnt=0;

vector<int>A;
int ask(){
	printf("? ");
	print(A.size());ptc;
	for(auto x:A) print(x),ptc;
	fflush(stdout);
	int x;
	cin>>x;
	return x;
}

void dfs(int u,int fa){
	for(auto x:G[u]){
		if(x==fa) continue;
		g[++cnt] = P(u,x);
		dfs(x,u);
	}
}
set<int>s;
void get(int L,int R){
	s.clear();
	rep(i,L,R){
		s.insert(g[i].first);
		s.insert(g[i].second);
	}
	A.clear();
	for(auto x:s){
		A.pb(x);
	}
}
int main(){
#ifndef ONLINE_JUDGE
	//freopen("in0.txt","r",stdin);
   // freopen("5.out","w",stdout);
#endif
	n=read();int u,v;
	rep(i,1,n-1){
		u=read(),v=read();
		G[u].pb(v);G[v].pb(u);
		A.pb(i);
	}
	A.pb(n);
	maxx=ask();
	dfs(1,0);
	int l=1,r=cnt,ans=n-1;
	while(l<=r){
		int mid=(l+r)>>1;
		get(l,mid);
		int tmp = ask();
		if(tmp == maxx) ans = mid,r=mid-1;
		else l=mid+1;
	}
	printf("! %d %d",g[ans].first,g[ans].second);
    return 0;
} 