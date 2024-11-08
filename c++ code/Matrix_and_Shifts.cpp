// https://codeforces.com/contest/1660/problem/E
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
const int N=2e3;
const int maxn=N+9;
const int inf=0x7f7f7f7f;
const ll linf=1e18;
const int maxm=4*N+9;
const int mod=998244353;
const int base=31;
const double eps=1e-4;

int n;
int a[maxn][maxn<<1];
char s[maxn];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
	//freopen("1.out","w",stdout);
#endif
	int cse=1;cin>>cse;
	while(cse--){
		getchar();
		cin>>n;
		rep(i,1,n) {
			cin>>s+1;
			rep(j,1,n){
				a[i][j]=a[i][j+n] = s[j] - '0';;
			}
		}
		int ans=0,pos;
		rep(i,0,n-1){
			int sum=0;
			rep(j,1,n){
				sum+=a[j][i+j];
			}
			if(ans<sum) ans=sum,pos=i;
		}
		ans=n-ans;
		rep(i,0,n-1){
			if(i==pos) continue;
			rep(j,1,n) ans+=(a[j][i+j]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
