// https://codeforces.com/contest/1567/problem/F
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

int n,m;
char s[600][600];
int ans[600][600];
vector<int>G[maxn];
const int mov[4][2]={-1,0,1,0, 0,-1,0,1};
int col[maxn];

int id(P x){return (x.first-1)*m+x.second;}

void End(){
    puts("NO");exit(0);
}

void dfs(int now){
    for(auto x:G[now]){
        if(!col[x]) col[x]=5-col[now],dfs(x);
        if(col[x]!=5-col[now]) End();
    }
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
#endif
    n=read(),m=read();
    rep(i,1,n) scanf("%s",s[i]+1);
    vector<P>tmp;
    rep(i,1,n){
        rep(j,1,m){
            if(s[i][j]=='X'){
                tmp.clear();
                rep(k,0,3){
                    int nx=i+mov[k][0],ny=mov[k][1]+j;
                    if(s[nx][ny]=='.') tmp.pb(P(nx,ny));
                }
                if(tmp.size()&1) {End();}
                if(tmp.size()==2){
                    G[id(tmp[0])].pb(id(tmp[1]));
                    G[id(tmp[1])].pb(id(tmp[0]));
                }
                else if(tmp.size()==4){
                    G[id(tmp[0])].pb(id(tmp[2]));
                    G[id(tmp[2])].pb(id(tmp[0]));
                  //  G[id(tmp[2])].pb(id(tmp[0]));
                 //   G[id(tmp[3])].pb(id(tmp[3]));
                    G[id(tmp[3])].pb(id(tmp[1]));
                    G[id(tmp[1])].pb(id(tmp[3]));
                }
            }
        }
    }

    rep(i,1,n){
        rep(j,1,m){
            if(s[i][j]=='.'){
                if(!col[id(P(i,j))]){
                    col[id(P(i,j))]=1;
                    dfs(id(P(i,j)));
                }
            }   
        }
    }

    rep(i,1,n){
        rep(j,1,m){
            if(s[i][j]=='.'){
                ans[i][j]=col[id(P(i,j))];
            }
        }
    }
    rep(i,1,n){
        rep(j,1,m){
            if(s[i][j]=='X'){
                int sum=0;
                rep(k,0,3){
                    int nx=i+mov[k][0],ny=j+mov[k][1];
                    if(s[nx][ny]=='.') sum+=col[id(P(nx,ny))];
                }
                ans[i][j]=sum;
            }
        }
    }
    puts("YES");
    rep(i,1,n) {
        rep(j,1,m){
            print(ans[i][j]);ptc;
        }
        pts;
    }
    return 0;
}