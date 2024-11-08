// https://codeforces.com/contest/1700/problem/D
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rpe(i,a,b) for(int i=a;i>=b;--i)
#define pts putchar('\n')
#define ptc putchar(' ')
#define pb push_back 
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int N=2e5;
const int maxn=N+9;
const int inf=0x7f7f7f7f;
const ll linf = 1e18;
const int maxm=20*N+9;

int n;
int a[maxn];
int main(){    
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
   // freopen("5.out","w",stdout);
#endif
    int T=1;//cin>>T;
    while(T--){
        cin>>n;
        rep(i,1,n) cin>>a[i];
        ll lim=-1,sum=0;
        rep(i,1,n){
            sum+=a[i];
            lim = max(lim,(sum+i-1)/i);
        }
        int q;cin>>q;
        while(q--){
            ll x;scanf("%lld",&x);
            if(x<lim) puts("-1");
            else{
                ll l=1,r=1e9,ans=r;
                while(l<=r){
                    ll mid=(l+r)>>1;
                    if(mid * x >= sum) ans=mid,r=mid-1;
                    else l=mid+1;
                }
                printf("%lld\n",ans);
            }
        }
    }
    return 0; 
}