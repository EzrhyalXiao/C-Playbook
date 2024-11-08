// https://codeforces.com/contest/1701/problem/F
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rpe(i,a,b) for(int i=a;i>=b;--i)
#define pts putchar('\n')
#define ptc putchar(' ')
#define pb push_back 
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int N=2e5;
const int maxn=N+9;
const int inf=0x7f7f7f7f;
const ll linf = 1e18;
const int maxm=20*N+9;

int q,d;
int vis[maxn];

int bit[maxn];
inline int low(int x){return (x&(-x));}
void add(int x,int val){for(int i=x;i<=N;i+=low(i))bit[i]+=val;}
int query(int x){
    int sum=0;
    for(int i=x;i>0;i-=low(i)) sum+=bit[i];
    return sum;
}

ll seg[maxn<<2],lz[maxn<<2],num[maxn<<2];
void up(int o){
    seg[o]=seg[o<<1]+seg[o<<1|1];
    num[o]=num[o<<1]+num[o<<1|1];
}
void down(int o,int l,int r){
    ll tmp=lz[o];lz[o]=0;
    lz[o<<1]+=tmp;lz[o<<1|1]+=tmp;
    int mid=(l+r)>>1;
    seg[o<<1]+=tmp*num[o<<1];
    seg[o<<1|1]+=tmp*num[o<<1|1];
}
void Set(int o,int l,int r,int pos,int flag,int val){
    if(l==r) {seg[o]=val;num[o]=flag;return;}
    if(lz[o]) down(o,l,r);
    int mid=(l+r)>>1;
    if(pos<=mid) Set(o<<1,l,mid,pos,flag,val);
    else Set(o<<1|1,mid+1,r,pos,flag,val);
    up(o);
}
void update(int o,int l,int r,int L,int R,int x){
    if(R<L) return;
    if(L<=l&&r<=R) {seg[o]+=x*num[o];lz[o]+=x;return;}
    if(lz[o])down(o,l,r);
    int mid=(l+r)>>1;
    if(L<=mid) update(o<<1,l,mid,L,R,x);
    if(mid<R) update(o<<1|1,mid+1,r,L,R,x);
    up(o); 
}
ll Query(int o,int l,int r,int L,int R){
    if(R<L) return 0;
    if(L<=l&&r<=R) return seg[o];
    if(lz[o])down(o,l,r);
    int mid=(l+r)>>1;
    ll sum=0;
    if(L<=mid) sum+=Query(o<<1,l,mid,L,R);
    if(mid<R) sum+=Query(o<<1|1,mid+1,r,L,R);
    return sum; 
}

int main(){    
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
   // freopen("4.out","w",stdout);
#endif  
    int T=1;
   // cin>>T;
    while(T--){
//用树状数组统计cnt
//线段树维护cnt的和
        cin>>q>>d;
        ll ans=0;
        while(q--){
            int x;scanf("%d",&x);
            if(!vis[x]){
                int y=query(min(x+d,N)) - query(x);
                ans+=1LL*y*(y-1)/2;
                y=query(x-1) - query(max(0,x-d-1));
                ans+=1LL*y*(y-1)/2;
                ans+= (Query(1,1,N,max(x-d+1,1),x-1)) - 
                    1LL*query(x)*(query(x-1)-query(x-d));
             //   printf("Query(1,1,N,max(x-d,1),x-1):%lld\n",Query(1,1,N,max(x-d,1),x-1));
       
                update(1,1,N,max(x-d,1),N,1);
          //      rep(i,1,8) printf("query(%d)=%d\n",i,Query(1,1,N,i,i));
                Set(1,1,N,x,1,query(min(x+d,N))+1); 
        //        rep(i,1,8) printf("query(%d)=%d\n",i,Query(1,1,N,i,i));
                add(x,1);           
                vis[x]=1;
            }
            else{
                
                vis[x]=0;
                int y=query(min(x+d,N)) - query(x);
                ans-=1LL*y*(y-1)/2;
                y=query(x-1) - query(max(0,x-d-1));
                ans-=1LL*y*(y-1)/2;
                ans-= Query(1,1,N,max(x-d+1,1),x-1) - 
                    1LL*query(x)*(query(x-1)-query(x-d));      
                add(x,-1);
                update(1,1,N,max(x-d,1),N,-1);
                Set(1,1,N,x,0,0);
                    
            }
            printf("%lld\n",ans);
        }    

    }
    return 0; 
}