// https://codeforces.com/contest/1475/problem/G
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<bitset>
#include<vector>
#include<string>
#include<set>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rpe(i,a,b) for(int i=a;i>=b;--i)
#define pts putchar('\n')
#define ptc putchar(' ')
#define pb push_back
#define pp pair<int,int>
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
const int inf=0x3f3f3f3f;
const int maxn=2e5+9;
const int maxm=2e6+9;
const int mod=1e9+7;
const double PI=3.1415926;
const double eps=1e-7;

namespace IO{
    ll read(){    
        ll a=1,b=0;char c=getchar();
        while(c>'9'||c<'0'){if(c=='-')a=-1;c=getchar();} 
        while(c>='0'&&c<='9'){b=(b<<3)+(b<<1)+c-'0';c=getchar();}
        return a*b ;
    }
    void print (ll x){
        if(x<0) putchar('-'),x=-x;
        if(x>9) print(x/10);
        putchar(x%10+'0');
    } 
}
using namespace IO;
inline void cmin(int &x,int y){x=min(x,y);}
inline void cmax(int &x,int y){x=max(x,y);}

int T;
int n;
int a[maxn],dp[maxn],pos[maxn];
void solve(){
    int maxx=-1;
    n=read();
    rep(i,1,n) a[i]=read(),maxx=max(a[i],maxx),dp[i]=inf;
    sort(a+1,a+1+n);
    rep(i,1,maxx) pos[i]=0;
    rep(i,1,n){
        dp[i]=i-1;
        for(int j=1;j*j<=a[i];++j){ 
            if(a[i]%j==0){
                if(pos[j]) cmin(dp[i],dp[pos[j]]+(i-pos[j]-1));
                if(pos[a[i]/j]) cmin(dp[i],dp[pos[a[i]/j]]+(i-pos[a[i]/j]-1));
            }
        }
        pos[a[i]]=i;
    }
    int ans=inf;
    rep(i,1,n) cmin(ans,dp[i]+n-i);
    print(ans);pts;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in0.txt","r",stdin);
#endif
    T=read();
    while(T--){
        solve();
    }
    return 0;
}