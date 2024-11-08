// https://codeforces.com/contest/1512/problem/F
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
const int maxn=2e5+9;
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
int n,c;
int a[maxn],b[maxn];
signed main(){
#ifndef ONLINE_JUDGE
    freopen("in0.txt","r",stdin);
#endif
    T=read();
    while(T--){
        n=read(),c=read();
        rep(i,1,n) a[i]=read();
        rep(i,1,n-1) b[i]=read();
        int ans=inf,tmpans=0,now=0,x;
        rep(p,1,n-1){
            x=(c-now)/a[p];
            if((c-now)%a[p]) x++;
            ans=min(ans,max(0ll,x)+tmpans);
            if(now>=b[p]){
                now-=b[p];
                tmpans++;
            }
            else{
                x=(b[p]-now)/a[p];
                if((b[p]-now)%a[p]==0) now=0;
                else x++,now=a[p]-(b[p]-now)%a[p];
                tmpans+=x+1;
            }        
        }
        x=(c-now)/a[n];
        if((c-now)%a[n]!=0) x++;
        ans=min(ans,tmpans+x);
        print(ans);pts;
    }
    return 0;
}