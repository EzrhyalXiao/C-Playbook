// https://codeforces.com/contest/1401/problem/E
#include<bits/stdc++.h>
#define pts putchar('\n')
#define ptc putchar(' ')
#define rep(i,a,b) for(register int i=a;i<=b;++i)
#define rpe(i,a,b) for(register int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=1e5+9;
const int maxm=1e6+9;
const ll inf=1e18;
const int mod=1e6;
int n,m;
struct Tree{
	int T[maxm];
	int lowbit(int i){return i&(-i);}
	void modify(int pos,int num){
		for(int i=pos;i<=mod;i+=lowbit(i)) T[i]+=num;
	}
	int query(int pos){
		int sum=0;
		for(int i=pos;i;i-=lowbit(i)) sum+=T[i];
		return sum;
	}
}tree;
struct OPT{
	int pos,l,r;
}upd[maxn*2],sum[maxn];
ll ans=1;
int read(){
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
bool cmp1(OPT a,OPT b){return a.l<b.l;}
bool cmp2(OPT a,OPT b){return a.pos<b.pos;}
int main (){int x,y,z;
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
#endif
	n=read(),m=read();
	rep(i,1,n){
		x=read()+1,y=read()+1,z=read()+1;
		if(z-y==mod) ans++;
		upd[i]=(OPT){x,y-1,1};
		upd[i+n]=(OPT){x,z,-1};
	}
	rep(i,1,m){
		x=read()+1,y=read()+1,z=read()+1;
		if(z-y==mod) ans++;
		sum[i]=(OPT){x,y,z};
	}
	n*=2;
	sort(upd+1,upd+1+n,cmp1);
	sort(sum+1,sum+1+m,cmp2);
	int n0=1,m0=1;
	while(n0<=n&&upd[n0].l==0) tree.modify(upd[n0].pos,upd[n0].r),n0++;
	rep(i,1,mod){
		while(m0<=m&&sum[m0].pos==i) ans+=tree.query(sum[m0].r)-tree.query(sum[m0].l-1),m0++;
		while(n0<=n&&upd[n0].l==i) tree.modify(upd[n0].pos,upd[n0].r),n0++;		
	}		
	print(ans);
	return 0;	
} 

 