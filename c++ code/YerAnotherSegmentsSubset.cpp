// https://codeforces.com/contest/1399/problem/F
#include<bits/stdc++.h>
#define pts putchar('\n')
#define ptc putchar(' ')
#define rep(i,a,b) for(register int i=a;i<=b;++i)
#define rpe(i,a,b) for(register int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=3e3+9;
const int maxm=1e5+9;
const ll inf=1e18;
const int mod=1e9+7;
int T,n;
int l[maxn],r[maxn],num[maxn*2],cnt=0;
struct SEG{int l,r;}seg[maxn];
vector<int>G[maxn*2];
int dp[maxn*2][maxn*2];
int read(){
	int a=1,b=0;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')a=-1;c=getchar();} 
	while(c>='0'&&c<='9'){b=(b<<3)+(b<<1)+c-'0';c=getchar();}
	return a*b ;
}
void print (int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) print(x/10);
	putchar(x%10+'0');
}
int solve(int ll,int rr){
	if(dp[ll][rr]!=-1) return dp[ll][rr];
	int val=count(G[ll].begin(),G[ll].end(),rr);
	dp[ll][rr]=0;
	dp[ll][rr]=max(dp[ll][rr],val+((ll==rr)? 0:solve(ll+1,rr)));
	int sze=G[ll].size();
	rep(i,0,sze-1){
		int to=G[ll][i];
		if(to>=rr) continue;
		dp[ll][rr]=max(dp[ll][rr],val+solve(ll,to)+solve(to+1,rr));
	}
	return dp[ll][rr];
}
int main (){
	
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
#endif

	T=read();
	while(T--){		
		n=read();cnt=0; 			
		rep(i,1,n) {
			l[i]=read(),r[i]=read();
			num[++cnt]=l[i];
			num[++cnt]=r[i];
		}
		sort(num+1,num+1+cnt);
		cnt=unique(num+1,num+1+cnt)-num-1;
		rep(i,1,cnt) rep(j,1,cnt) dp[i][j]=-1;
		rep(i,1,n){
			seg[i].l=lower_bound(num+1,num+1+cnt,l[i])-num;
			seg[i].r=lower_bound(num+1,num+1+cnt,r[i])-num;
			G[seg[i].l].push_back(seg[i].r);
		}
		print(solve(1,cnt));pts;
		rep(i,1,cnt) G[i].clear();		
	}
	return 0;	
} 

 