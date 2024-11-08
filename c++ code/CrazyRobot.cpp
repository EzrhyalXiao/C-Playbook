// https://codeforces.com/contest/1613/problem/E
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
const int maxm=1e5+9;
const double PI=3.1415926;
const double eps=1e-5;
const int base=131;
const int N=1e6;
const ll mod=1e9+7;

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

int n,m;
vector<vector<char>>s;
vector<vector<bool>>vis;
P lab;
queue<P>q;
int mov[4][2]={0,1,1,0,0,-1,-1,0};
int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
#endif
	int cse=read();
	while(cse--){
		n=read(),m=read();
		s.resize(n+1);vis.resize(n+1);
		rep(i,1,n) s[i].resize(m+1),vis[i].resize(m+1);
		char tmp[maxn];

		rep(i,1,n){
			cin>>tmp+1;int len=strlen(tmp+1);
			rep(j,1,len){
				s[i][j]=tmp[j];vis[i][j]=0;
				if(s[i][j]=='L') lab=P(i,j);
			}
		}
		
		vis[lab.first][lab.second]=1;
		while(!q.empty()) q.pop();
		rep(i,0,3){
			int nx=lab.first+mov[i][0],ny=lab.second+mov[i][1];
			if(nx<1||ny<1||nx>n||ny>m) continue;
			if(s[nx][ny]=='#') continue;
			q.push(P(nx,ny));
		}	
		while(!q.empty()){
			P now=q.front();q.pop();
			int tmp=0;P nxt;
			rep(i,0,3){
				int nx=now.first+mov[i][0],ny=now.second+mov[i][1];
				if(nx<1||ny<1||nx>n||ny>m) continue;
				if(vis[nx][ny]||s[nx][ny]=='#') continue;
				tmp++;
				nxt=P(nx,ny);
			}
			if(tmp<=1){
				if(tmp==1)q.push(nxt);
				vis[now.first][now.second]=1;
				s[now.first][now.second]='+';
			}
		}
		rep(i,1,n){
			rep(j,1,m){
				putchar(s[i][j]);
			}
			pts;
		}
		s.clear();vis.clear();
	}
	return 0;
} 