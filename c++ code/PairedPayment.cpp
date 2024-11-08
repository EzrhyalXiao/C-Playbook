// https://codeforces.com/contest/1486/problem/E
#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<bitset>
#include<vector>
#include<string>
#include<set>
using namespace std;
#define rep(i,a,b) for(register int i=a;i<=b;++i)
#define rpe(i,a,b) for(register int i=a;i>=b;--i)
#define pts putchar('\n')
#define ptc putchar(' ')
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
const int inf=0x7f7f7f7f;
const ll linf=1e18;
const int maxn=2e5+9;
const int maxm=2e6+9;
const int mod=20101009;
const double PI=3.1415926;
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


int n,m;
vector< pair<int,int> >G[maxn];

void add(int u,int v,int w){
	G[u].pb(make_pair(v,w));
	G[v].pb(make_pair(u,w));
}

ll dis[52][maxn];
bool vis[52][maxn];
struct node{int x,y;ll val;};
bool operator < (node a,node b){return a.val>b.val;}
priority_queue< node >q;

int main(){
#ifndef ONLINE_JUDGE
    freopen("in0.txt","r",stdin);
   // freopen("2.out","w",stdout);
#endif  
	int a,b,c;
    n=read(),m=read();
	rep(i,1,m){
		a=read(),b=read(),c=read();
		add(a,b,c);
	}
	memset(dis,0x7f,sizeof(dis));
	dis[0][1]=0;
	q.push((node){1,0,0});
	while(!q.empty()){
		int now=q.top().x,flag=q.top().y;
		q.pop();
		if(vis[flag][now]) continue;
		vis[flag][now]=1;
		int k=G[now].size();
			if(flag==0){
				rep(i,0,k-1){
					int v=G[now][i].first,w=G[now][i].second;
					if(dis[w][v]>dis[0][now]){
						dis[w][v]=dis[0][now];
						q.push((node){v,w,dis[w][v]});
					}
				}
			}
			else{
				rep(i,0,k-1){	
					int v=G[now][i].first,w=G[now][i].second;
					ll d=1LL*(flag+w)*(flag+w);
					if(dis[0][v]>dis[flag][now]+d){
						dis[0][v]=dis[flag][now]+d;
						q.push((node){v,0,dis[0][v]});
					}
				}
			}
		 
	}
	rep(i,1,n){
		if(dis[0][i]==0x7f7f7f7f7f7f7f7f) print(-1);
		else print(dis[0][i]);
		ptc;
	}
    return 0;
}