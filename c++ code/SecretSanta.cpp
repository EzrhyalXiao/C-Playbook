// https://codeforces.com/contest/1530/problem/D
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<vector>
#include<cmath>
#include<bitset>
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
const ll linf=1e18;
const int maxn=2e5+9;
const int maxm=2e6+9;
const double PI=3.1415926;
const double eps=1e-7;
const ll mod=998244353;
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

int T;
int n;
int a[maxn],b[maxn];
bitset<maxn>s;
set<int>g;
vector<int>f;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
   // freopen("3.out","w",stdout);
#endif
    T=read();
    while(T--){
        n=read();s.reset();g.clear();f.clear();
        rep(i,1,n) a[i]=read(),b[i]=0;
        int ans=0;
        rep(i,1,n){
            if(!s[a[i]]){
                b[i]=a[i];
                s[a[i]]=1;
                ans++;
            }
        }
        rep(i,1,n) if(!s[i]) g.insert(i);
        rep(i,1,n){
            if(!b[i]){
                if(g.find(i)!=g.end()) f.pb(i);
            }
        }
        if(f.size()>1){
            int x=f.size();
            rep(i,0,x-2){
                g.erase(f[i]);
                b[f[i]]=f[i+1];
            }
            b[f[x-1]]=f[0];g.erase(f[x-1]);
        }
        else if(f.size()==1){
            bool flag=0;
            rep(i,1,n){
                if(a[i]==a[f[0]]){
                    b[f[0]]=b[i];
                    b[i]=f[0];
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                rep(i,1,n){
                    if(b[i]){
                        b[f[0]]=b[i];
                        b[i]=f[0];
                        ans--;
                        break;
                    }
                }
            }
            g.erase(f[0]);
        }
        int i=1;
            for(auto x:g){
                for(;i<=n;++i){
                    if(!b[i]){
                        b[i]=x;break;
                    }
                }
            }
        print(ans);pts;
        rep(i,1,n) print(b[i]),ptc;
        pts;
    } 
    return 0;
}

