// https://codeforces.com/contest/1484/problem/E
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rpe(i,a,b) for(int i=a;i>=b;--i)
#define pts putchar('\n')
#define ptc putchar(' ')
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
const int inf=0x7f7f7f7f;
const int maxn=3e5+9;
const int maxm=12e5+9;
const double PI=3.1415926;
const double eps=1e-8;
const int mod=1e9+7;
const int base=131;

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

int n;
int h[maxn];
ll b[maxn];

ll t[maxm],tag[maxm];
void pushup(int o){t[o]=max(t[o<<1],t[o<<1|1]);}
void build(int o,int l,int r){
    t[o]=-inf;tag[o]=0;
    if(l==r) return;
    int mid=(l+r)>>1;
    build(o<<1,l,mid);build(o<<1|1,mid+1,r);
    pushup(o);
}
void pushdown(int o,int l,int r){
    t[o<<1]+=tag[o];t[o<<1|1]+=tag[o];
    tag[o<<1]+=tag[o];tag[o<<1|1]+=tag[o];
    tag[o]=0;
}
void change(int o,int l,int r,int pos,ll val){
    if(l==r){t[o]=val;return;}
    if(tag[o]) pushdown(o,l,r);
    int mid=(l+r)>>1;
    if(mid>=pos) change(o<<1,l,mid,pos,val);
    else change(o<<1|1,mid+1,r,pos,val);
    pushup(o);
}
void update(int o,int l,int r,int L,int R,ll val){
    if(L>R) return;
    if(l>=L&&r<=R) {t[o]+=val;tag[o]+=val;return;}
    if(tag[o]) pushdown(o,l,r);
    int mid=(l+r)>>1;
    if(mid>=L)update(o<<1,l,mid,L,R,val);
    if(mid<R) update(o<<1|1,mid+1,r,L,R,val);
    pushup(o);
}
ll query(int o,int l,int r,int L,int R){
    if(L>R) return 0;
    if(l>=L&&r<=R){return t[o];}
    if(tag[o]) pushdown(o,l,r);
    int mid=(l+r)>>1;ll sum=-inf;
    if(mid>=L) sum=max(query(o<<1,l,mid,L,R),sum);
    if(mid<R) sum=max(query(o<<1|1,mid+1,r,L,R),sum);
    return sum;
}

int stck[maxn],top=0;
ll dp[maxn];
int main(){
#ifndef ONLINE_JUDGE
    freopen("in0.txt","r",stdin);
#endif
    n=read();
    build(1,0,n);
    rep(i,1,n) h[i]=read(),dp[i]=-1e18;
    rep(i,1,n) b[i]=read();
    change(1,0,n,0,0);
    stck[0]=0;dp[0]=0;top=0;
    rep(i,1,n){
        while(top&&h[i]<h[stck[top]]){
            update(1,0,n,stck[top-1],stck[top]-1,-b[stck[top]]);
            top--;
        }
        update(1,0,n,stck[top],i-1,b[i]);
        stck[++top]=i;
        dp[i]=query(1,0,n,0,i-1);
        change(1,0,n,i,dp[i]);
    }
    print(dp[n]);
    return 0;
}