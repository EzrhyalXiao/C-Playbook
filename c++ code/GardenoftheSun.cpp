// https://codeforces.com/contest/1496/problem/E
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
const int maxn=5e2+9;
const int maxm=2e5+9;
const double PI=3.1415926;
const double eps=1e-7;
const int mod=1e9+7;

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
int n,m;
char s[maxn][maxn];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in1.txt","r",stdin);
   // freopen("2.out","w",stdout);
#endif  
    T=read();
    while(T--){
        n=read(),m=read();
        rep(i,1,n) scanf("%s",s[i]+1);
        for(int j=1+(m%3==0);j<=m;j+=3){
            rep(i,1,n) s[i][j]='X';
            if(j+3>m) break;
            int pos;
            if(n==1||(s[2][j+1]!='X'&&s[2][j+2]!='X')) pos=1;
            else pos=2;
            //cout<<s[1][j+1]<<s[1][j+2]<<"asda"<<endl;
            s[pos][j+1]=s[pos][j+2]='X';
        }
        rep(i,1,n) {rep(j,1,m) putchar(s[i][j]);pts;}
    }
    return 0;
}