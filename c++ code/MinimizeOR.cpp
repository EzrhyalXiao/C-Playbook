// https://codeforces.com/contest/1665/problem/E
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rpe(i,a,b) for(int i=a;i>=b;--i)
#define pts putchar('\n')
#define py putchar(' ')
#define pb push_back 
#define pty puts("YES")
#define ptn puts("NO");
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int N=1e5;
const int maxn=N+9;
const int inf=0x7f7f7f7f;
const ll linf=1e18;
const int maxm=4*N+9;
const int mod=998244353;
const int base=31;
const double eps=1e-4;


int a[maxn];

P t[maxm];

void up(P &x,P y,P z){
	if(y.first<z.first) x=y;
	else x=z;
}

void build(int o,int l,int r){
	if(l==r) {t[o].first=a[l];t[o].second=l;return;}
	int mid=(l+r)>>1;
	build(o<<1,l,mid);build(o<<1|1,mid+1,r);
	up(t[o],t[o<<1],t[o<<1|1]);
}

void update(int o,int l,int r,int pos,int val){
	if(l==r) {t[o].first=val;return;}
	int mid=(l+r)>>1;
	if(pos<=mid) update(o<<1,l,mid,pos,val);
	else update(o<<1|1,mid+1,r,pos,val);
	up(t[o],t[o<<1],t[o<<1|1]);
}
P query(int o,int l,int r,int L,int R){
	if(L<=l&&r<=R){return t[o];}
	int mid=(l+r)>>1;
	P x,y;x=y=P(inf,0);
	if(L<=mid) x=query(o<<1,l,mid,L,R);
	if(mid<R) y=query(o<<1|1,mid+1,r,L,R);
	up(x,x,y);
	return x; 
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
	//freopen("1.out","w",stdout);
#endif
	int cse;cin>>cse;
	while(cse--){
		int n;
		cin>>n;
		rep(i,1,n) scanf("%d",&a[i]);
		build(1,1,n);
		int m;cin>>m;
		while(m--){
			int l,r;scanf("%d%d",&l,&r);
			vector<P>rev;
			int tmp=min(31,r-l+1);
			rep(i,1,tmp){
				P x = query(1,1,n,l,r);
				rev.pb(x);
				update(1,1,n,x.second,inf);
			}
			int ans=inf;
			rep(i,0,tmp-1){
				rep(j,i+1,tmp-1){
					ans=min(ans,rev[i].first|rev[j].first);
				}
			}
			printf("%d\n",ans);
			for(auto x:rev) update(1,1,n,x.second,x.first);
		}
	}
	return 0;
}
