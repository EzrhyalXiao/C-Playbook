// https://codeforces.com/contest/1684/problem/D
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

int n,k;
int a[maxn];
P b[maxn];
int vis[maxn];

int main(){
#ifndef ONLINE_JUDGE    
	freopen("in0.txt","r",stdin);
//	freopen("1.out","w",stdout);
#endif
	int cse;cin>>cse;
    while(cse--){
        cin>>n>>k;
        /*int dp[maxn][maxn];
        rep(i,1,n) scanf("%d",&a[i]);
        rep(i,1,n) rep(j,1,k) dp[i][j]=inf;
        dp[0][0]=0;
        rep(i,1,n){
            dp[i][0]=dp[i-1][0]+a[i];
            rep(j,1,min(i,k)){
                dp[i][j] =min(dp[i-1][j-1],dp[i-1][j]+a[i]+j);
            }
        }
        cout<<dp[n][k]<<endl;*/
        rep(i,1,n) cin>>a[i],b[i]={a[i]+i,i};
        sort(b+1,b+1+n);
        ll ans=0;
        rep(i,n-k+1,n) vis[b[i].second]=1;
        int tmp=0;
        rep(i,1,n){
            if(vis[i]==1) tmp++;
            else ans+=a[i]+tmp;
        }
        cout<<ans<<endl;
        rep(i,1,n) vis[i]=0;
    }
	return 0;
}
