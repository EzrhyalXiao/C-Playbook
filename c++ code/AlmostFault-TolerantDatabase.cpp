// https://codeforces.com/contest/1492/problem/E
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
const int maxn=25e4+9;
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


int n,m;
vector<int>G[maxn],ans,pos,pos1;
int id1,id2;

bool check(){
    int num;
    rep(i,2,n){
        num=0;
        rep(j,1,m) num+=(G[i][j]!=ans[j]);
        if(num>2) return 0;
    }
    return 1;
}

void print_ans(){
    puts("Yes");
    rep(i,1,m) print(ans[i]),ptc;
    exit(0);
}


int main(){
#ifndef ONLINE_JUDGE
    freopen("in2.txt","r",stdin);
   // freopen("2.out","w",stdout);
#endif  
    n=read();m=read();
    rep(i,1,n){
        G[i].resize(m+1);
        rep(j,1,m) G[i][j]=read();
    }
    ans=G[1];
    if(m<=2) print_ans();
    rep(i,2,n){
        pos.clear();
        rep(j,1,m) if(ans[j]!=G[i][j]) pos.pb(j);
        if(pos.size()>=3) {id1=i;break;}
    }
    if(pos.size()<3) print_ans();
    if(pos.size()>4) {puts("No");exit(0);}
    for(int x :pos){
        ans[x]=G[id1][x];
        rep(i,2,n){
            pos1.clear();
            rep(j,1,m){
                if(ans[j]!=G[i][j]) pos1.pb(j);
            }
            if(pos1.size()>=3){
                id2=i;
                break;
            }       
        }
        if(pos1.size()<3) print_ans();
        else if(pos1.size()==3){
                for(int y : pos1){
                    int tmp=ans[y];
                    ans[y]=G[id2][y];
                    if(check()) print_ans();
                    ans[y]=tmp;
                }
            }
        ans[x]=G[1][x];
    }
    puts("No");
}