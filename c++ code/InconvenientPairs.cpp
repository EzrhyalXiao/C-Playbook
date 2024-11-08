// https://codeforces.com/contest/1569/problem/D
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
const int maxm=1e6+9;
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

int n,m,k;
const int N=1e6+1;
int x[maxn],y[maxn];

int t[maxm];
inline int low(int x){return (x&(-x));}
int sum(int x){int s=0;
    for(int i=x;i;i-=low(i)) s+=t[i];;
    return s;
}
void update(int x,int val){
    for(int i=x;i<=N;i+=low(i)) t[i]+=val;
}

struct Point{
	int x,y;
}po[maxn];
vector<int>A[maxn],B[maxn];
set<int>AA,BB;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
#endif
    int cse;cse=read();
    
    while(cse--){
        n=read(),m=read(),k=read();
        rep(i,1,n) x[i]=read()+1;
        rep(j,1,m) y[j]=read()+1;
		int idx,idy;
        rep(i,1,k){
			po[i].x=read()+1,po[i].y=read()+1;
			idx=lower_bound(x+1,x+1+n,po[i].x)-x;
			idy=lower_bound(y+1,y+1+m,po[i].y)-y;
			if(x[idx]==po[i].x){
				if(y[idy]!=po[i].y) B[idy-1].pb(i),BB.insert(idy-1);
			}
			else{
				A[idx-1].pb(i),AA.insert(idx-1);
			}
		}
		ll ans=0;
		for(auto now:AA){
			for(auto tmp:A[now]){
				update(po[tmp].y,1);
			}
			for(auto tmp:A[now]){
				ans+=sum(N) - sum(po[tmp].y);
			}
			for(auto tmp:A[now]){
				update(po[tmp].y,-1);
			}
		}
		for(auto now:BB){
			for(auto tmp:B[now]){
				update(po[tmp].x,1);
			}
			for(auto tmp:B[now]){
				ans+=sum(N) - sum(po[tmp].x);
			}
			for(auto tmp:B[now]){
				update(po[tmp].x,-1);
			}
		}
		for(auto now:AA) A[now].clear();
		for(auto now:BB) B[now].clear();
		print(ans);pts;
		AA.clear();BB.clear();
    }
    return 0;
}