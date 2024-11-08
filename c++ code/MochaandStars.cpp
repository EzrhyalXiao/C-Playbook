// https://codeforces.com/contest/1559/problem/E
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<vector>
#include<set>
#include<cmath>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rpe(i,a,b) for(int i=a;i>=b;--i)
#define pts putchar('\n')
#define ptc putchar(' ')
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>P;
const int inf=0x7f7f7f7f;
const ll linf=1e18;
const int maxn=1e5+9;
const int maxm=1e7+9;
const double PI=3.1415926;
const double eps=1e-5;
const ll mod=998244353;
const int base=131;
const int N=1e6;

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

int n,m;
int l[70],r[70];
int p[maxn],mu[maxn],cnt=0;
bool vis[maxn];
void pre(){n=1e5;
    mu[1]=1;
    rep(i,2,n){
        if(!vis[i]) p[++cnt]=i,mu[i]=-1;
        rep(j,1,cnt){
            if(1LL*i*p[j]>n) break;
            vis[i*p[j]]=1;
            if(i%p[j]==0) break;
            mu[i*p[j]]=-mu[i];
        }
    }
}

int s[maxn],f[maxn];

int solve(int d){
    rep(i,0,m/d) f[i]=0;
    f[0]=1;
    rep(i,1,n){
        int L = (l[i] + d -1)/d, R = r[i]/d;
        if(L>R) return 0;
        s[0]=f[0];
        rep(j,1,m/d) s[j]=(s[j-1] + f[j])%mod;
        rep(j,0,m/d){
            f[j] = ( ((j-L>=0)?  s[j-L]:0) - ((j>=R+1)? s[j-R-1]:0 )+mod)%mod;
        }
    }
    ll sum=0;
    rep(i,1,m/d) sum=(sum+f[i])%mod;
    return sum;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
#endif
    pre();
    n=read(),m=read();
    rep(i,1,n) {
        l[i]=read(),r[i]=read();
    }    
    ll ans=0;
    rep(i,1,m){
        ans=(ans+ 1LL*mu[i]*solve(i)+mod)%mod;
    }
    print(ans%mod);
    return 0;
} 