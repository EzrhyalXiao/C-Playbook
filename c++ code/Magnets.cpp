// https://codeforces.com/contest/1491/problem/F
#include<iostream>
#include<cstdio>
#include<queue>
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
typedef long long ll;
typedef unsigned long long ull;
const int inf=0x7f7f7f7f;
const ll linf=1e18;
const int maxn=2e5+9;
const int maxm=2e6+9;
const int N=8e6;
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
vector<int>ans;

int ask(int pos,int l,int r){
    printf("? 1 %d\n",r-l+1);
    print(pos);pts;
    rep(i,l,r) print(i),ptc;
    pts;
    fflush(stdout);
    return read();
}

int main(){  
    T=read();
    while(T--){
        ans.clear();
        n=read();
        rep(i,2,n){
            if(ask(i,1,i-1)){
                rep(j,i+1,n){
                    if(!ask(i,j,j)) ans.pb(j);
                }
            
                int l=1,r=i-1,pos=-1;
                while(l<=r){
                    int mid=(l+r)>>1;
                    if(!ask(i,1,mid)) l=mid+1;
                    else r=mid-1,pos=mid;
                }
                rep(j,1,i-1) if(j!=pos) ans.pb(j);
                break;
            }
        }
        int k=ans.size();
        printf("! %d ",k);
        rep(i,0,k-1) print(ans[i]),ptc;
        pts;
        fflush(stdout);
    }
    return 0;
}