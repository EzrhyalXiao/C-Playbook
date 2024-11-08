// https://codeforces.com/contest/1660/problem/F2
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rpe(i,a,b) for(int i=a;i>=b;--i)
#define pts putchar('\n')
#define py putchar(' ')
#define pb push_back 
#define pty puts("YES")
#define ptn puts("NO")
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int N=4e5;
const int maxn=N+9;
const int inf=0x7f7f7f7f;
const ll linf=1e18;
const int maxm=4*N+9;
const int mod=998244353;
const int base=31;
const double eps=1e-4;

int n,m;
char s[maxn];

struct BIT{
	ll t[maxn];
	inline int low(int x){return x&(-x);}
	void update(int x,int val){for(int i=x;i<=m;i+=low(i))t[i]+=val;}
	ll sum(int x){ll s=0;
		for(int i=x;i;i-=low(i)) s+=t[i];
		return s;
	}
}T[3];


int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
	//freopen("1.out","w",stdout);
#endif
	int cse=1;cin>>cse;
	while(cse--){
		cin>>n;cin>>s+1;
		int val=n+1;
		ll ans=0;
		m=n<<1|1;
		T[val%3].update(n+1,1);
		rep(i,1,n){
			if(s[i]=='-') val--;
			else val++;
			ans+=T[val%3].sum(m) -T[val%3].sum(val-1);
			T[val%3].update(val,1);
		} 
		cout<<ans<<endl;
		rep(i,0,2) rep(j,1,m) T[i].t[j]=0;
	}
	return 0;
}
