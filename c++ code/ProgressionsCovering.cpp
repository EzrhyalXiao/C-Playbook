// https://codeforces.com/contest/1661/problem/D
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
const int N=3e5;
const int maxn=N+9;
const int inf=0x7f7f7f7f;
const ll linf=1e18;
const int maxm=4*N+9;
const int mod=998244353;
const int base=31;
const double eps=1e-4;
int n,k;
ll b[maxn];
ll t[maxm],lz[maxm];

void pushdown(int o,int l,int r){
	int mid=(l+r)>>1;
	t[o<<1]+=lz[o] * (mid-l+1);
	t[o<<1|1]+=lz[o]*(r-mid);
	lz[o<<1]+=lz[o];lz[o<<1|1]+=lz[o];
	lz[o]=0;
}

void update(int o,int l,int r,int L,int R,ll val){
	if(L<=l&&r<=R) {t[o]+=val*(r-l+1);lz[o]+=val;return;}
	if(lz[o]) pushdown(o,l,r);
	int mid=(l+r)>>1;
	if(L<=mid) update(o<<1,l,mid,L,R,val);
	if(mid<R) update(o<<1|1,mid+1,r,L,R,val);
	t[o]=t[o<<1]+t[o<<1|1];
}

ll query(int o,int l,int r,int L,int R){
	if(L<=l&&r<=R) return t[o];
	if(lz[o]) pushdown(o,l,r);
	int mid=(l+r)>>1;ll sum=0;
	if(L<=mid) sum+=query(o<<1,l,mid,L,R);
	if(mid<R) sum+=query(o<<1|1,mid+1,r,L,R);
	return sum;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
	//freopen("1.out","w",stdout);
#endif
	int cse=1;
	while(cse--){
		cin>>n>>k;ll ans=0;
		rep(i,1,n) cin>>b[i];
		rpe(i,n,1){
			ll now=query(1,1,n,1,i);
			if(b[i] > now){
				ll tmp,tep=min(k,i);
				tmp=b[i]-now;
				now=tmp/tep + ((tmp%tep)>0);
				ans+=now;
				update(1,1,n,max(i-k+1,1),i,now);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
