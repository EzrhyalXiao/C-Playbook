// https://codeforces.com/gym/103428/problem/D
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define pts putchar('\n')
#define ptc putchar(' ')
#define pb push_back 
#define pty puts("YES")
#define ptn puts("NO")
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int N=1e6;
const int maxn=N+9;
const int inf=0x7f7f7f7f;
const ll linf=1e18;
const int maxm=1e6+9;
const ll mod=998244353;
const ll Mod=263882790666241;
const double eps=1e-4;
const double PI=acos(-1);
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
 
ull h[maxn],p[maxn];
string s;int n;
 
ull geth(int l,int r){
    return h[r]-h[l-1]*p[r-l+1];
}
int vis[maxn];
void Solve(){
    cin>>s;n=s.size();s=" "+s;p[0]=1;
    rep(i,1,n) h[i]=h[i-1]*base+s[i],p[i]=p[i-1]*base;
    int ans=0;
    rep(len,1,n-1){
        bool flag=0;int j;
        for(j=1;j<=n;j+=len){
            if(j+2*len-1>n) break;
            if(geth(j,j+len-1)!=geth(j+len,j+2*len-1)) flag=1;
        }
        if(j<n){
            int tmp=n-j-len+1;
            if(geth(j+len,n)!=geth(j,j+tmp-1)) flag=1; 
        }
        if(flag) continue;
        ans++;
        vis[1]++;
        if(len>n/2) {
            vis[n-len+1]--;
            vis[len+1]++;
        }
    }
    rep(i,1,n) vis[i]+=vis[i-1];
    int q=read();
    while(q--){
        int x=read();
        print(ans-vis[x]);pts;
    }
}
 
int main (){
#ifndef ONLINE_JUDGE
  freopen("in0.txt","r",stdin);
//	freopen("4.out","w",stdout);
    clock_t start_time, end_time;
    start_time = clock();   //获取开始执行时间
#endif  
    int T=1;
    //cin>>T;
    rep(cse,1,T){
        Solve();
    }
#ifndef ONLINE_JUDGE
    end_time = clock();     //获取结束时间
    double Times = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("%f seconds\n", Times);
#endif
	return 0;	
} 