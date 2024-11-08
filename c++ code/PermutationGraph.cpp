// https://codeforces.com/contest/1696/problem/D
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rpe(i,a,b) for(int i=a;i>=b;--i)
#define pts putchar('\n')
#define py putchar(' ')
#define pb push_back 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const ll N=3e5;
const int maxn=N+9;
const int inf=0x7f7f7f7f;
const ll linf=1e18;
const int maxm=4*N+9;
const int mod=1e9+7;
const int base=31;
const double eps=1e-4;
 
 
int n;
int a[maxn];
int f[20][maxn],g[20][maxn];
int lg[maxn];
 
int check(int l,int r,int flag){
	int len=lg[r-l+1];
	if(flag){
		if(a[f[len][l]] > a[f[len][r-(1<<len)+1]]) return f[len][l];
		return f[len][r-(1<<len)+1];
	}
	else{
		if(a[g[len][l]] < a[g[len][r-(1<<len)+1]]) return g[len][l];
		return g[len][r-(1<<len)+1];
	}
}
 
int Div(int l,int r){
	if(l==r) return 0;
	int mx=check(l,r,1);
	int mn=check(l,r,0);
	if(mx<mn){
		return Div(l,mx)+Div(mn,r)+1;
	}
	else{
		return Div(l,mn)+Div(mx,r)+1;
	}
}
 
void solve(){
	cin>>n;
	rep(i,1,n) scanf("%d",&a[i]),f[0][i]=g[0][i]=i;
	rep(j,1,18){
		rep(i,1,n){
			if( a[f[j-1][i]] > a[f[j-1][i+(1<<(j-1))]]) f[j][i]=f[j-1][i];
			else f[j][i]=f[j-1][i+(1<<(j-1))];
			if( a[g[j-1][i]] < a[g[j-1][i+(1<<(j-1))]]) g[j][i]=g[j-1][i];
			else g[j][i]=g[j-1][i+(1<<(j-1))];
		}
	}
	cout<<Div(1,n);pts;
}
 
int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
//	freopen("1.out","w",stdout);
#endif
	int T=1;
	cin>>T;
	lg[0]=-1;
	rep(i,1,N) lg[i]=lg[i>>1]+1;
	while(T--){
		solve();
	}
	return 0;
}