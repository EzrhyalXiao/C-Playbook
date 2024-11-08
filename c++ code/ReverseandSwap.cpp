// https://codeforces.com/contest/1401/problem/F
#include<bits/stdc++.h>
#define pts putchar('\n')
#define ptc putchar(' ')
#define rep(i,a,b) for(register int i=a;i<=b;++i)
#define rpe(i,a,b) for(register int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=3e5+9;
const int maxm=6e5+9;
const ll inf=1e18;
const int mod=1e6;
int n,q;
ll tree[maxm];int dep[maxm];
bool rev[50];

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
void up(int o){tree[o]=tree[o<<1]+tree[o<<1|1];}
void build(int o,int l,int r,int depth){
	dep[o]=depth;
	if(l==r){tree[o]=read();return;}
	int mid=(l+r)>>1;
	build(o<<1,l,mid,depth-1);build(o<<1|1,mid+1,r,depth-1);
	up(o); 
}
void modify(int o,int l,int r,int pos,ll val){
	if(l==r){tree[o]=val;return;}
	int mid=(l+r)>>1;
	if(pos<=mid) modify((o<<1)^ rev[dep[o]],l,mid,pos,val);
	else modify((o<<1|1)^rev[dep[o]],mid+1,r,pos,val);
	up(o);
}
ll query(int o,int l,int r,int L,int R){
	if(l>=L&&r<=R){return tree[o];}	
	int mid=(l+r)>>1;
	ll sum=0;
	if(L<=mid) sum+=query((o<<1)^rev[dep[o]],l,mid,L,R);
	if(R>mid) sum+=query((o<<1|1)^rev[dep[o]],mid+1,r,L,R);
	return sum;
}
int main (){int opt,x,y;
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
#endif
	n=read(),q=read();
	rep(i,1,n) rev[i]=0;
	build(1,1,1<<n,n);n=(1<<n);
	while(q--){
		opt=read();
		switch(opt){
			case 1:{x=read(),y=read();modify(1,1,n,x,y);break;}
			case 2:{x=read();rep(i,0,x)rev[i]^=1 ;break;}
			case 3:{x=read();rev[x+1]^=1;break;}
			case 4:{
				x=read(),y=read();
				print(query(1,1,n,x,y));pts;
				break;
			}
		}
	}
	return 0;	
} 

 