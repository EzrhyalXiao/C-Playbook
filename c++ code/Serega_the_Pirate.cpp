// https://codeforces.com/contest/1700/problem/E
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
const ll N=2e5;
const int maxn=N+9;
const int inf=0x7f7f7f7f;
const ll linf=1e18;
const int maxm=4*N+9;
const int mod=1e9+7;
const int base=31;
const double eps=1e-4;
 
int n,m;
vector<vector<int>>a,vis,pre;
int mov[5][2]={0,0,0,1,0,-1,1,0,-1,0};
 
struct node{int a,b,c,d;};
bool operator < (node a,node b){
	if(a.a!=b.a) return a.a<b.a;
	else if(a.b!=b.b) return a.b<b.b;
	else if(a.c!=b.c) return a.c<b.c;
	else return a.d<b.d;
}
map<node,bool>mp;
vector<P>bad;
 
bool isbound(int x,int y){
	return (x>=1&&x<=n)&&(y<=m&&y>=1);
}
bool check_bad(int x,int y){
	int tmp=a[x][y];
	if(tmp==1) return 0;
	rep(i,1,4){
		int xx=x+mov[i][0],yy=y+mov[i][1];
		if(isbound(xx,yy)){
			if(a[xx][yy]<=tmp) return 0;
		} 
	}
	return 1;
}
bool check(int x,int y,int xx,int yy){
	int num=0;
	swap(a[x][y],a[xx][yy]);
	rep(i,0,4){
		int nx=x+mov[i][0],ny=y+mov[i][1];
		if(!isbound(nx,ny)) continue;
		if(!vis[nx][ny]) {
			num+=pre[nx][ny]-check_bad(nx,ny);
			vis[nx][ny]=1;
		}
	}
	rep(i,0,4){
		int nx=xx+mov[i][0],ny=yy+mov[i][1];
		if(!isbound(nx,ny)) continue;
		if(!vis[nx][ny]) {
			num+=pre[nx][ny]-check_bad(nx,ny);
			vis[nx][ny]=1;
		}
	}
	rep(i,0,4){
		int nx=xx+mov[i][0],ny=yy+mov[i][1];
		if(isbound(nx,ny)) vis[nx][ny]=0;
		nx=x+mov[i][0],ny=y+mov[i][1];
		if(isbound(nx,ny)) vis[nx][ny]=0;
	}
	swap(a[x][y],a[xx][yy]);
	return num==bad.size();
}
void Gett(){
	int a;
}
void solve(){
	cin>>n>>m;
	a.clear();mp.clear();bad.clear();
	vis.clear();pre.clear();
	a.resize(n+1,vector<int>(m+1));
	vis.resize(n+1,vector<int>(m+1));
	pre.resize(n+1,vector<int>(m+1));
	rep(i,1,n) rep(j,1,m) scanf("%d",&a[i][j]);
	rep(i,1,n) rep(j,1,m) if(check_bad(i,j)) bad.pb({i,j}),pre[i][j]=1;
	int sze=bad.size();
	if(!sze) {puts("0");return;}
	else if(sze>10) {puts("2");return;}
	int x=bad[0].first,y=bad[0].second;
	int res=0;
	rep(i,0,4){
		int xx=x+mov[i][0],yy=y+mov[i][1];
		if(!isbound(xx,yy)) continue;
		rep(i,1,n){
			rep(j,1,m){
				if(mp[{i,j,xx,yy}] || mp[{xx,yy,i,j}]) continue;
				if(i==1&&j==1&&xx==1&&yy==5) Gett();
				if(!check(i,j,xx,yy)) continue;	
			//	printf("%d %d %d %d\n",i,j,xx,yy);
				mp[{i,j,xx,yy}]=mp[{xx,yy,i,j}]=1;
				res++;
			}
		}	
	}
	if(!res) puts("2");
	else printf("1 %d\n",res);
}
 
int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
//	freopen("1.out","w",stdout);
#endif
	int T=1;
	//cin>>T;
	while(T--){
		solve();
	}
	return 0;
}