//https://codeforces.com/contest/1557/problem/D
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include <unordered_map>
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
const int maxn=3e5+9;
const int maxm=5e6+9;
const double PI=3.1415926;
const double eps=1e-5;
const ll mod=1e9+7;
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
vector<P>G[maxn];

int ls[maxm],rs[maxm];
int root=0,cnt=0;
P t[maxm],lz[maxm];
int last[maxn],vis[maxn];
int val[maxn<<1];
void pushdown(int o){
    if(!ls[o]) ls[o] =++cnt,t[rs[o]]=lz[rs[o]]=P(0,0);
    t[ls[o]] = max(t[ls[o]],lz[o]);
    lz[ls[o]] = max(lz[ls[o]],lz[o]);
    
    if(!rs[o]) rs[o] =++cnt,t[rs[o]]=lz[rs[o]]=P(0,0);
    t[rs[o]] = max(t[rs[o]],lz[o]);
    lz[rs[o]] = max(t[rs[o]],lz[o]);
    lz[o]= P(0,0);
}
void update(int &o,int l,int r,int L,int R,P now){
    if(!o){o=++cnt;lz[o]=t[o]=P(0,0);}
    if(L<=l&&r<=R){
        t[o] = max(t[o],now);
        lz[o] = max(lz[o],now);
        return;
    }
    if(lz[o]!=P(0,0)) pushdown(o);
    int mid=(l+r)>>1;
    if(L<=mid) update(ls[o],l,mid,L,R,now);
    if(mid<R) update(rs[o],mid+1,r,L,R,now);
    if(ls[o]) t[o]=max(t[o],t[ls[o]]);
    if(rs[o]) t[o]=max(t[o],t[rs[o]]);
}
P query(int o,int l,int r,int L,int R){
    if(L<=l&&r<=R) return t[o];
    int mid=(l+r)>>1;P tmp=P(0,0);
    if(lz[o]!=P(0,0)) pushdown(o);
    if(L<=mid&&ls[o]) tmp=max(tmp,query(ls[o],l,mid,L,R));
    if(mid<R&&rs[o]) tmp=max(tmp,query(rs[o],mid+1,r,L,R));
    return tmp;
}


int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
   // freopen("5.out","w",stdout);
#endif
    n=read(),m=read();
    int x,y,z;
    rep(i,1,m){
        x=read(),y=read(),z=read();
        G[x].pb(P(y,z));
        val[2*i-1] = y;
        val[2*i] = z;
    }
    sort(val+1,val+1+2*m);
    int tot=unique(val+1,val+1+2*m)-val-1;
    rep(i,1,n) {
        sort(G[i].begin(),G[i].end());
        for(auto &p:G[i]){
            p.first = lower_bound(val+1,val+1+tot,p.first)-val;
            p.second =lower_bound(val+1,val+1+tot,p.second) -val;
        }
    }
    P ans = P(0,0);
    rep(i,1,n){
        ans= P(0,0);
        for(auto p : G[i]){
            ans=max(ans,query(root,1,tot,p.first,p.second));
        }
        last[i] = ans.second;
        ans.first++; ans.second=i;
        for(auto p :G[i]){
            update(root,1,tot,p.first,p.second,ans);
        } 
    }
    ans=query(root,1,1e9,1,1e9);
    print(n-ans.first);pts;
    int now=ans.second;
    while(now){
        vis[now]=1;
        now=last[now];
    }
    rep(i,1,n){
        if(!vis[i]) print(i),ptc;
    }
    return 0;
} 