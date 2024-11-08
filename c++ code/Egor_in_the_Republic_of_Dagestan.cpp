// https://codeforces.com/contest/1407/problem/E
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
const int maxn=5e5+9;
const int maxm=5e5+9;
const double PI=3.1415926;
const double eps=1e-7;
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

int n,m;
int last[maxn],cnt=0;
struct Edge{int from,to,w;}edge[maxm];

void add(int x,int y,int z){
    edge[++cnt].from=last[x];
    edge[cnt].to=y;edge[cnt].w=z;
    last[x]=cnt;
}

int d[maxn],col[maxn],v[maxn];
queue<int>q;

int main(){
#ifndef ONLINE_JUDGE
    freopen("in1.txt","r",stdin);
#endif
    n=read(),m=read();
    if(n==1){
        print(0);pts;print(0);
        return 0;
    }
    int x,y,z;
    rep(i,1,m){
        x=read(),y=read(),z=read();
        add(y,x,z);
    }
    rep(i,1,n) col[i]=-1,d[i]=inf,v[i]=0;
    q.push(n);d[n]=0;
    while(!q.empty()){
        int now=q.front();q.pop();
        if(now==1) break;
        for(int i=last[now];i;i=edge[i].from){
            int to=edge[i].to,w=edge[i].w;
            if(col[to]==-1){
                col[to]=1-w;
            }
            else{
                if(col[to]==w){
                    d[to]=min(d[to],d[now]+1);
                    if(!v[to]) v[to]=1,q.push(to);
                }
            }
        }   
    }
    print(d[1]==inf? -1:d[1]);pts;
    rep(i,1,n){
        if(col[i]==-1) putchar('0');
        else print(col[i]);
    }
    return 0;
}