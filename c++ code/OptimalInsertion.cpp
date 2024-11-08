// https://codeforces.com/contest/1602/problem/E
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

int T;
int n,m;
P a[maxn];
int b[maxn];

struct Bit{
	int t[maxn];
	int low(int x){return x&(-x);}
	void update(int x){for(int i=x;i<=n;i+=low(i))t[i]++;}
	int sum(int x){int s=0;
		for(int i=x;i;i-=low(i)) s+=t[i];
		return s;
	}
	void clear(){rep(i,1,n) t[i]=0;} 
}t1;

struct SEG{
	int mn[maxn<<2];
	int lazy[maxn<<2];
	void build(int o,int l,int r){
		mn[o]=l;lazy[o]=0;;
		if(l==r) return;
		int mid=(l+r)>>1;
		build(o<<1,l,mid);build(o<<1|1,mid+1,r);
	}
	void pushdown(int o){
		mn[o<<1]+=lazy[o];
		mn[o<<1|1]+=lazy[o];
		lazy[o<<1]+=lazy[o];
		lazy[o<<1|1]+=lazy[o];
		lazy[o]=0;
	}
	void update(int o,int l,int r,int L,int R,int val){
		if(L<=l&&r<=R){lazy[o]+=val;mn[o]+=val;return;}
		int mid=(l+r)>>1;
		if(lazy[o]) pushdown(o);
		if(L<=mid) update(o<<1,l,mid,L,R,val);
		if(mid<R) update(o<<1|1,mid+1,r,L,R,val);
		mn[o] = min(mn[o<<1],mn[o<<1|1]);
	}
	int query(){return mn[1];}
}t2;

int main(){
#ifndef ONLINE_JUDGE
    freopen("in0.txt","r",stdin);
#endif
	T=read();
	while(T--){
		n=read(),m=read();
		t2.build(1,0,n);
		rep(i,1,n){
			a[i].first=read();a[i].second=i;
		}
		t1.clear();
		sort(a+1,a+1+n);
		ll ans=0;
		rep(i,1,n){
			t1.update(a[i].second);
			ans+=i-t1.sum(a[i].second);
		}
		rep(i,1,m) b[i]=read();
		sort(b+1,b+1+m);
		int l=0,r=1;
		rep(i,1,m){
			while(l<n && a[l+1].first<b[i]) 
				t2.update(1,0,n,0,a[++l].second-1,1);
			while(r<=n&& a[r].first<=b[i])
				t2.update(1,0,n,a[r++].second,n,-1);
			ans+=t2.query();
		}
		print(ans);pts;
	}
    return 0;
} 