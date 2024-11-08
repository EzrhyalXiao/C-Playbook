// https://codeforces.com/contest/1709/problem/D
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
const ll N=2e5;
const int maxn=N+9;
const int inf=0x7f7f7f7f;
const ll linf=1e18;
const int maxm=4*N+9;
const int mod=1e9+7;
const int base=31;
const double eps=1e-4;
 
int n,m;
int st[20][maxn];
 
int check(int l,int r){
	if(l>r) swap(l,r);
	int len=log2(r-l+1);
	return min(st[len][l],st[len][r-(1<<len)+1]);
}
 
bool check(){
	int a,b,c,d,e;
	scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
	a=n-a+1;c=n-c+1;
	if(a%e!=c%e) return 0;
	if(b%e!=d%e) return 0;
	int minn=check(b,d);
	int tmp=a%e;
	if(tmp==0) tmp=e;
	if(minn<tmp) return 0;
	return 1;
}
void solve(){
	cin>>n>>m;int tmp;
	rep(i,1,m) {
		cin>>tmp;
		st[0][i]=n-tmp;
	}
	rep(j,1,17){
		rep(i,1,m){
			st[j][i]=min(st[j-1][i],st[j-1][i+(1<<(j-1))]);
		}
	}
	int q;cin>>q;
	while(q--){
		if(check()) puts("YES");
		else puts("NO");
	}
}
 
int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
//	freopen("1.out","w",stdout);
#endif
	int T=1;
	//cin>>T;
	while(T--){
		solve();
	}
	return 0;
}