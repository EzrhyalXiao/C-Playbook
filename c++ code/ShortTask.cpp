// https://codeforces.com/contest/1512/problem/G
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rpe(i,a,b) for(int i=a;i>=b;--i)
#define pts putchar('\n')
#define ptc putchar(' ')
#define pb push_back
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int inf=0x7f7f7f7f;
const int maxn=1e7+9;
const int maxm=2e5+9;
const double PI=3.1415926;
const double eps=1e-7;
const int mod=1e9+7;

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

int T;
int n;
ll sum[maxn],ans[maxn];
signed main(){
#ifndef ONLINE_JUDGE
    freopen("in0.txt","r",stdin);
#endif
    T=read();
    n=(int)1e7;
    rep(i,1,n){
        for(int j=i;j<=n;j+=i){
           sum[j]+=i; 
        }
    }
    rep(i,1,n){
        if(sum[i]<=n&&!ans[sum[i]]) ans[sum[i]]=i;
    }
    while(T--){
        n=read();
        if(ans[n]) print(ans[n]),pts;
        else puts("-1");
    }
    return 0;
}