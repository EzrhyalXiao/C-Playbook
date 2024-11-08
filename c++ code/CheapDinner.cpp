// https://codeforces.com/contest/1487/problem/E
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
typedef double db;
const int inf=0x7f7f7f7f;
const ll linf=1e18;
const int maxn=1e5+5e4+9;
const int maxm=2e5+9;
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

int n[5];
ll a[5][maxn];
multiset<int>s[4][maxn];
pair<ll,int>p[maxn],q[maxn];
void solve(){
    rep(i,1,4) n[i]=read();
    rep(i,1,4){
        rep(j,1,n[i]){
            a[i][j]=read();
        }
    }
    rep(i,1,3){
        int m=read(),x,y;
        rep(j,1,m){
            x=read(),y=read();
            s[i][y].insert(x);
        }
        rep(j,1,n[i]) p[j]=make_pair(a[i][j],j);
        rep(j,1,n[i+1]) q[j]=make_pair(a[i+1][j],j);
        sort(p+1,p+1+n[i]);
        sort(q+1,q+1+n[i+1]);
        rep(j,1,n[i+1]){
            bool f=0;
            rep(k,1,n[i]){
                if(!s[i][q[j].second].count(p[k].second)){
                    a[i+1][q[j].second]+=p[k].first;
                    f=1;
                    break;
                }
            }
            if(!f) a[i+1][q[j].second]=inf;
        }
    }
    ll ans=inf;
    rep(i,1,n[4]){
        ans=min(ans,a[4][i]);
    }
    if(ans>=inf) print(-1);
    else print(ans);
    pts;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in0.txt","r",stdin);
    //freopen("in0.txt","w",stdout);
#endif
    solve();
    return 0;
}