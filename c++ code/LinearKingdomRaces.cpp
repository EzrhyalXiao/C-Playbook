// https://codeforces.com/contest/115/problem/E
#include<bits/stdc++.h>
#define pts putchar('\n')
#define ptc putchar('\n')
#define rep(i,a,b) for(register int i=a;i<=b;++i)
#define rpe(i,a,b) for(register int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=2e5+9;
const ll inf=1e18+9;
const int mod=1e9+7;
struct PAIR{ll from,profit;};
vector<PAIR>G[maxn];
int n,m;
bool operator < (PAIR a,PAIR b){return a.from<b.from;}
ll cost[maxn],ans;

namespace SEG_TREE{
	ll lazy[maxn<<2],seg[maxn<<2];
	void pushup(int o){seg[o]=max(seg[o<<1],seg[o<<1|1]);}
	void build(int o,int l,int r){
		lazy[o]=0;
		if(l==r) {seg[o]=0;return;}
		int mid=(l+r)>>1;
		build(o<<1,l,mid);
		build(o<<1|1,mid+1,r);
		pushup(o);
	}
	void pushdown(int o,int l,int r){
		int mid=(l+r)>>1;
		lazy[o<<1]+=lazy[o];seg[o<<1|1]+=lazy[o];
		lazy[o<<1|1]+=lazy[o];seg[o<<1]+=lazy[o];
		lazy[o]=0;
	}
	void modify(int o,int l,int r,int L,int R,ll val){
		if((l>=L&&r<=R)) {lazy[o]+=val;seg[o]+=val;return;}
		if(lazy[o])pushdown(o,l,r);
		int mid=(l+r)>>1;
		if(L<=mid) modify(o<<1,l,mid,L,R,val);
		if(mid<R) modify(o<<1|1,mid+1,r,L,R,val);
		pushup(o);
	}
	ll query(int o,int l,int r,int L,int R){
		if(l>=L&&r<=R){return seg[o];}
		if(lazy[o]) pushdown(o,l,r);
		ll sum=-inf;int mid=(l+r)>>1;
		if(L<=mid) sum=query(o<<1,l,mid,L,R);
		if(mid<R) sum=max(sum,query(o<<1|1,mid+1,r,L,R));
		return sum;
	}
} 
using namespace SEG_TREE;
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


int main (){ll a,b,c;int lon;
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
#endif
	n=read(),m=read();ans=0;
	rep(i,1,n) cost[i]=read();
	rep(i,1,m) {
		a=read(),b=read(),c=read();
		G[b].push_back((PAIR){a,c});
	}
	rep(i,1,n){
		lon=G[i].size();
		modify(1,1,n,1,i,-cost[i]);
		rep(j,0,lon-1){
			a=G[i][j].from,b=G[i][j].profit;
			modify(1,1,n,1,a,b);
		}
		ans=max(ans,seg[1]);
		modify(1,1,n,i+1,i+1,ans);
	}
	print(ans);
	return 0;
} 

 