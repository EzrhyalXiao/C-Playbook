// https://codeforces.com/contest/1555/problem/E
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include <unordered_map>
#include<vector>
#include<set>
#include<cmath>
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
const int maxn=3e5+9;
const int maxm=4e6+9;
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


int n,m;

int t[maxm],lazy[maxm];
struct node{
	int l,r,w;
}q[maxn];

bool cmp(node a,node b){
	return a.w<b.w;
}

void pushdown(int o){
	t[o<<1]+=lazy[o];
	t[o<<1|1]+=lazy[o];
	lazy[o<<1]+=lazy[o];
	lazy[o<<1|1]+=lazy[o];
	lazy[o]=0;
}

void update(int o,int l,int r,int L,int R,int x){
	if(L<=l&&r<=R){
		t[o]+=x;lazy[o]+=x;
		return;
	}
	int mid=(l+r)>>1;
	if(lazy[o]) pushdown(o);
	if(mid>=L) update(o<<1,l,mid,L,R,x);
	if(mid<R) update(o<<1|1,mid+1,r,L,R,x);
	t[o]=min(t[o<<1],t[o<<1|1]);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
#endif
	m=read(),n=read()-1;
	rep(i,1,m){
		q[i].l=read(),q[i].r=read()-1,q[i].w=read();
	}
	sort(q+1,q+1+m,cmp);
	int ans=inf;
	int r=0;
	rep(i,1,m){
		while(! t[1] &&r<m){
			r++;
			update(1,1,n,q[r].l,q[r].r,1);
			
		}
		if(t[1]) ans=min(ans,q[r].w-q[i].w);
		else break;
		update(1,1,n, q[i].l, q[i].r, -1);
	}
	print(ans);
	return 0;
}