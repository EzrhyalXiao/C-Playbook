// https://codeforces.com/contest/1604/problem/D
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
const int maxn=1e5+9;
const int maxm=4e5+9;
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

ll x,y;
ll n;

int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
   // freopen("5.out","w",stdout);
#endif
    int cse=read();
    while(cse--){
        ll X,Y;
        x=read(),y=read();
        X=x;Y=y;
        if(y<x) n=x+y;
        else if(x==y||y%x==0) n=x;
        else{
            y-= y/x * x;
            ll b=y/2;
            n = Y-b;
        }
        print(n);
       // if(n%X==Y%n) printf("   dui");
        pts;
    }
    return 0;
} 