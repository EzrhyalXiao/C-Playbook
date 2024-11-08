// https://codeforces.com/contest/1490/problem/F
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
#define rep(i,a,b) for(register int i=a;i<=b;++i)
#define rpe(i,a,b) for(register int i=a;i>=b;--i)
#define pts putchar('\n')
#define ptc putchar(' ')
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
const int inf=0x7f7f7f7f;
const ll linf=1e18;
const int maxn=2e5+9;
const int maxm=2e6+9;
const int mod=20101009;
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


int T;
int n;
int a[maxn];
int m;
int b[maxn],c[maxn];
int main(){
#ifndef ONLINE_JUDGE
    freopen("in0.txt","r",stdin);
   // freopen("2.out","w",stdout);
#endif  
    T=read();
    while(T--){
        n=read();
        rep(i,1,n) a[i]=read();
        sort(a+1,a+1+n);
        m=0;
        
        rep(i,1,n){
            if(a[i]!=a[i-1]){
                b[++m]=a[i];
                c[m]=1;
            }
            else c[m]++;
        }
        sort(c+1,c+1+m);
        int ans=inf;
        rep(i,1,m){
            ans=min(ans,n-(m-i+1)*c[i]);
        }
        print(ans);pts;
    }
    return 0;
}