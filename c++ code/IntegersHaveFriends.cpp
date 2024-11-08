// https://codeforces.com/contest/1549/problem/D
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
const int maxn=2e5+9;
const int maxm=3e5+9;
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

int n;
ll a[maxn];
ll st[maxn][20];
ll gcd(ll a,ll b){
    return b==0? a:gcd(b,a%b);
}
ll Get(int l,int r){
    int x=log(r-l+1)/log(2);
    return gcd(st[l][x],st[r-(1<<x)+1][x]);
}

ll Abs(ll x){return x<0? -x:x;}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
   // freopen("3.out","w",stdout);
#endif
	int cse=read();
    while(cse--){
        n=read();
        rep(i,1,n) a[i]=read();
        rep(i,1,n-1){
            st[i][0]=Abs(a[i]-a[i+1]);
        }
        rep(i,1,18){
            rep(j,1,n-1){
                if(j+(1<<i)-1 > n-1) break; 
                st[j][i]=gcd(st[j][i-1],st[j+(1<<(i-1))][i-1]);
            }
        }
        int ans=0;
        rep(i,1,n-1){
            int l=i,r=n-1,pos=i;
            while(l<=r){
                int mid=(l+r)>>1;
                if(Get(i,mid)==1) r=mid-1;
                else l=mid+1,pos=mid;
            }
            if(Get(i,pos)!=1)ans=max(ans,pos-i +1);
        }
        print(ans+1);pts;
    }
    return 0;
}