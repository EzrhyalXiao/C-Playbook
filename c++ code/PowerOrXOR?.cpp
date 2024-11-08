// https://codeforces.com/contest/1673/problem/E
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rpe(i,a,b) for(int i=a;i>=b;--i)
#define pts putchar('\n')
#define py putchar(' ')
#define pb push_back 
#define pty puts("YES")
#define ptn puts("NO")
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const ll N=(1LL<<20);
const int maxn=N+9;
const int inf=0x7f7f7f7f;
const ll linf=1e18;
const int maxm=4*N+9;
const int mod=2;
const int base=31;
const double eps=1e-4;

int n,k;
int a[maxn],b[maxn];

int C[30][maxn];
int qpow(int a,int b){int sum=1;
	while(b){
		if(b&1) sum=sum*a%mod;
		a=a*a%mod;b>>=1;
	}
	return sum;
}
int fac[maxn],inv[maxn];

void pre(){fac[0]=1;
	rep(i,1,n) fac[i]=fac[i-1]*i%mod;
	inv[n]=qpow(fac[n],mod-2);
	rpe(i,n-1,0) inv[n] = inv[n+1] * (n+1)%mod;
	rep(i,max(0,n-22),n){
		int tmp=n-i;
		C[tmp][0]=1;
		rep(j,1,i){
			C[tmp][j] = (C[tmp][j-1] + fac[i] * inv[j]*inv[i-j])%mod;
		}
	}
}

bool check(int x,int y){
	if(x==0) return 1;
	if(y<0) return 0;
	x=n-x;
	return C[x][y];
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
	freopen("1.out","w",stdout);
#endif
	cin>>n>>k;pre();
	rep(i,1,n) cin>>b[i];
	rep(l,1,n){
		ll now=1;bool flag=0;
		rep(r,l,n){
			if(b[r] >= 20 &&flag) break;
			if(flag==0) now=b[r],flag=1;
			else now*=(1LL<<b[r]);
			if(now>=N) break;
			int x = n-1 - (r - l) - 2;//剩余x个符号
			int y = k-2; //还需要y个异或符号
			if(l==1) y++,x++;
			if(r==n) y++,x++;
		/*	if(x>=y&&check(x,y-1)) 
				a[now]^=1;*/
			if(x>=y && (x==0 || (y>0 && ((x-1)|(y-1))==(x-1))))
            	a[now]^=1;
		}
	}
	int tail=N;
	while(a[tail]==0&&tail) tail--;
	rpe(i,tail,0) putchar(a[i]+'0');
	return 0;
}
