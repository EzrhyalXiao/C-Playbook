// https://codeforces.com/contest/1567/problem/D
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

int s,n;
int a[maxn];
vector<int>ans;


int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
#endif
    int cse;cin>>cse;
    a[0]=1;
    rep(i,1,9) a[i]=a[i-1]*10;
    while(cse--){
        ans.clear();
        s=read();n=read()-1;
        rpe(i,9,0){
            while(n&&s-a[i]>=n){
                s-=a[i];
                n--;
                ans.pb(a[i]);
            }
        }
        ans.pb(s);
        for(auto x:ans) print(x),ptc;
        pts;
    }
    return 0;
}