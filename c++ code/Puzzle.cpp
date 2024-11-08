// https://codeforces.com/contest/1700/problem/F
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
 
int n;
int a[5][maxn];
ll b[5];
void solve(){
	cin>>n;
	rep(i,1,4)
		rep(j,1,n) cin>>a[i][j];
	ll res=0;
	rep(i,1,n){
		rep(j,1,4){
			res+=b[j];
			if(a[j][i]) b[j]++;
		}
		rep(j,1,2){
			if(b[j]&&b[j+2]) b[j]--,b[j+2]--; 
		}
		rep(j,1,2){
			if(b[j]&&b[5-j]) res++,b[j]--,b[5-j]--;
		}
	}
	rep(i,1,4) if(b[i]) {puts("-1");return;}
	cout<<res;
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
