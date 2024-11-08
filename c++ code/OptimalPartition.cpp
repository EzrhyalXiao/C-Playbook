// https://codeforces.com/contest/1668/problem/D
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
const ll N=5e5;
const int maxn=N+9;
const int inf=0x7f7f7f7f;
const ll linf=1e18;
const int maxm=4*N+9;
const int mod=2;
const int base=31;
const double eps=1e-4;

int n;
int a[maxn];
ll s[maxn],ss[maxn],id[maxn];
struct Seg{
	int t[maxn<<2];
	void build(int o,int l,int r){
		if(l==r) {t[o]=-inf;return;}
		int mid=(l+r)>>1;
		build(o<<1,l,mid);build(o<<1|1,mid+1,r);
		t[o]=max(t[o<<1],t[o<<1|1]);
	}
	void update(int o,int l,int r,int pos,int val){
		if(l==r){t[o]=max(t[o],val);return;}
		int mid=(l+r)>>1;
		if(mid>=pos) update(o<<1,l,mid,pos,val);
		else update(o<<1|1,mid+1,r,pos,val);
		t[o]=max(t[o<<1],t[o<<1|1]);
	}
	int query(int o,int l,int r,int L,int R){
		if(L>R) return -inf;
		if(L<=l&&r<=R){return t[o];}
		int res=-inf,mid=(l+r)>>1;
		if(L<=mid) res=max(res,query(o<<1,l,mid,L,R));
		if(mid<R) res=max(res,query(o<<1|1,mid+1,r,L,R));
		return res;
	}
}T1,T2;
int dp[maxn];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
	//freopen("1.out","w",stdout);
#endif
	int cse=1;cin>>cse;
	while(cse--){
		cin>>n;
		rep(i,1,n){ 
			scanf("%d",&a[i]);
			s[i] = s[i-1] + a[i];
			ss[i] = s[i];
		}ss[0]=0;
		sort(ss,ss+1+n);
		rep(i,0,n) id[i] = lower_bound(ss,ss+1+n,s[i])-ss+1;
		T1.build(1,1,n);T2.build(1,1,n);
		T1.update(1,1,n,id[0],0);
		T2.update(1,1,n,id[0],0);
		rep(i,1,n){
			if(a[i]==0) dp[i]=dp[i-1];
			else if(a[i]>0) dp[i]=dp[i-1]+1;
			else dp[i]=dp[i-1]-1;
			int tmp = T1.query(1,1,n,1,id[i]-1);
			if(tmp!=-inf) dp[i]=max(dp[i],tmp+i);
			T1.update(1,1,n,id[i],dp[i]-i);
			T2.update(1,1,n,id[i],dp[i]+i); 
		}
		printf("%d\n",dp[n]);
	}
	return 0;
}