// https://codeforces.com/contest/1659/problem/D
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
const int N=2e5;
const int maxn=2*N+9;
const int inf=0x7f7f7f7f;
const ll linf=1e18;
const int maxm=4*N+9;
const int mod=1e9+7;
const int base=31;
const double eps=1e-4;

int n;
int c[maxn];
int a[maxn];

int t[maxn];
inline int low(int x){return x&(-x);}
void add(int x,int val){
	for(int i=x;i<=n+1;i+=low(i)) t[i]+=val; 
}
int query(int x){
	int sum=0;
	for(int i=x;i;i-=low(i)) sum+=t[i];
	return sum;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
//	freopen("1.out","w",stdout);
#endif
	int cse;cin>>cse;
	while(cse--){
		int r=0;ll sum=0;
		cin>>n;
		rep(i,1,n) cin>>c[i],sum+=c[i];
		sum/=n;r=(sum>=0);
		add(n-sum+1,1);
		rpe(i,n,2){
			int tmp=query(i);
			if(c[i]>=i-1+tmp){
				a[i]=1;
				sum--;
			}
			add(i-sum,1);
		}
		a[1]=c[1]>0;
		rep(i,1,n) cout<<a[i]<<" ",a[i]=0,t[i]=0;
		t[n+1]=0;
		pts;
	}
	return 0;
}