// https://codeforces.com/contest/1567/problem/E
#include<bits/stdc++.h>
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
const int maxn=3e5+9;
const int maxm=1e7+9;
const double PI=acos(-1);
const double eps=1e-5;
const ll mod=998244353;

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

int n,q;
struct node{
    int ls,rs;
    int l,r;
    ll cnt;
    bool operator == (node y){
        return (ls==y.ls)&&(rs==y.rs)&&(y.l==l)&&(y.r==r)&&(y.cnt==cnt);
    }
}O;

node t[maxn<<2];
int val[maxn];

node Merge(node a,node b){
    node c;
    if(val[a.r]<=val[b.l]) c.cnt=1LL*a.rs*b.ls;
    else c.cnt=0;
    c.cnt+=a.cnt+b.cnt;
    c.l=a.l;c.r=b.r;
    if(a.ls==a.r-a.l+1&&val[a.r]<=val[b.l]) c.ls=a.ls+b.ls;
    else c.ls=a.ls;
    if(b.rs==b.r-b.l+1&&val[a.r]<=val[b.l]) c.rs=b.rs+a.rs;
    else c.rs=b.rs;
    return c;
}

void build(int o,int l,int r){
    if(l==r){
        t[o].l=l,t[o].r=r;
        val[l]=read();
        t[o].ls=t[o].rs=t[o].cnt=1;
        return;
    }
    int mid=(l+r)>>1;
    build(o<<1,l,mid);build(o<<1|1,mid+1,r);
    t[o]=Merge(t[o<<1],t[o<<1|1]);
}

void update(int o,int pos,int v){
    if(t[o].l==t[o].r){
        val[pos]=v;return;
    }
    int mid=(t[o].l+t[o].r)>>1;
    if(pos<=mid) update(o<<1,pos,v);
    else update(o<<1|1,pos,v);
    t[o]=Merge(t[o<<1],t[o<<1|1]);
}

node query(int o,int L,int R){
    if(L<=t[o].l&&t[o].r<=R) return t[o];
    int mid=(t[o].l+t[o].r)>>1;
    node tmp=O;
    if(L<=mid) tmp=query(o<<1,L,R);
    if(mid<R) {
        if(tmp==O) tmp=query(o<<1|1,L,R);
        else tmp=Merge(tmp,query(o<<1|1,L,R));
    }
    return tmp;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
#endif
    O=(node){0,0,0,0,0};
    n=read(),q=read();
    build(1,1,n);
    int op,l,r;
    while(q--){
        op=read();l=read(),r=read();
        if(op&1){
            update(1,l,r);
        }else{
            print(query(1,l,r).cnt);pts;
        }
    }
    return 0;
}