// https://codeforces.com/contest/1404/problem/D
#include<bits/stdc++.h>
#define pts putchar('\n')
#define ptc putchar(' ')
#define pb push_back
#define rep(i,a,b) for(register int i=a;i<=b;++i)
#define rpe(i,a,b) for(register int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
const int maxn=1e6+9;
const int maxm=2e5+9;
const ll inf=1e18;
const int mod=1e6;
int n,m;
int id[maxn];
namespace IO{
	inline int read(){	
		int a=1,b=0;char c=getchar();
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
void One(){
	cout<<"First"<<endl;
	rep(i,1,2*n) cout<<i%n+1<<' ';
}
vector<int>G[maxn];bool vis[maxn],col[maxn];int sum=0;
void dfs(int now,int Col){
	vis[now]=1;col[now]=Col;
	if(Col==1) sum=(sum+now)%m;
	int sze=G[now].size();
	rep(i,0,sze-1){
		int to=G[now][i];
		if(!vis[to]) dfs(to,Col^1);
	}
}
void Two(){int A;
	m=n<<1;
	cout<<"Second"<<endl;
	rep(i,1,m){
		A=read();
		if(!id[A]) id[A]=i;
		else G[i].pb(id[A]),G[id[A]].pb(i);
	}
	rep(i,1,n)G[i].pb(i+n),G[i+n].pb(i);
	rep(i,1,m)if(!vis[i]) dfs(i,1);
	if(sum) rep(i,1,m) col[i]^=1;
	rep(i,1,m){
		if(col[i]) cout<<i<<' ';
	}
}
int main (){int A,B; 
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
#endif
	n=read();
	if(n%2==0) One();
	else Two();	
	return 0;	
} 

 