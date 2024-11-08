// https://codeforces.com/contest/1406/problem/E
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
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rpe(i,a,b) for(int i=a;i>=b;--i)
#define pts putchar('\n')
#define ptc putchar(' ')
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
const int inf=0x7f7f7f7f;
const int maxn=1e5+9;
const int maxm=2e7+9;
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

int n;
int p[maxn],cnt;
bitset<maxn>vis;

void pre(int N){
    cnt=0;
    rep(i,2,N){
        if(!vis[i])  p[++cnt]=i;
        rep(j,1,cnt){
            if(i*p[j]>N) break;
            vis[i*p[j]]=1;
            if(i%p[j]==0) break; 
        }
    }
}

int ask(char c,int x){
    putchar(c);ptc;print(x);pts;
    fflush(stdout);
    int y;
    y=read();
    return y;
}


int main(){
#ifndef ONLINE_JUDGE
   // freopen("in1.txt","r",stdin);
   // freopen("2.out","w",stdout);
#endif  
    n=read();
    pre(n);
    int ans=1;
    int pos=0;
    rep(i,1,cnt) if(p[i]<=sqrt(n)) pos=i;
    int B=98;
    int sum=n,l,r;
    rep(i,1,B){
        l=(i-1)*B+1;r=min(i*B,cnt);
        rep(j,l,r){
            if(j<=pos) continue;
            sum-=ask('B',p[j]);
        }
        int tmp=ask('A',1);
        if(tmp!=sum){
            rep(j,l,r){
                if(j<=pos) continue;
                tmp=ask('A',p[j]);
                if(tmp) {ans=p[j];break;}
            }
            break;
        }
        if(r==cnt) break;
    }

    rep(i,1,pos){
        if(ans*p[i]>n) break;
        int x=ask('B',p[i]);
        int num=0;
        int y=ask('A',p[i]);
        if(y!=0){
            ans*=p[i];
            for(int j=p[i]*p[i];j<=n;j*=p[i]){
               if(ask('A',j)) ans*=p[i];
               else break;
            }   
        }
    }
    printf("C %d",ans);
    fflush(stdout);
    return 0;
}