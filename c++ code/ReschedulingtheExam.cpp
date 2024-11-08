// https://codeforces.com/contest/1650/problem/E
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rpe(i,a,b) for(int i=a;i>=b;--i)
#define pts putchar('\n')
#define ptc putchar(' ')
#define pb push_back 
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int N=2e5;
const int maxn=N+9;
const int inf=0x7f7f7f7f;
const int maxm=20*N+9;
const int mod=998244353;

int n,d;
int a[maxn];
int minn;
int solve(int pos){
	if(pos<1||pos>n) return 0;
	int maxx=0,npos=pos;
	rep(i,0,n-1){
		if(a[i+1]==a[i]+1) continue;
		int x = (a[i+1]-a[i]-2)/2;
		if(x>maxx) maxx=x,npos=a[i] +x+1;
	}
	int x=(a[pos+1] - a[pos-1]-2)/2;
	if(x>maxx) maxx=x,npos=a[pos-1] +x+1;
	if(pos==n) x = (d - a[n-1] -1 );
	else x = (d-a[n]-1);
	if(x>maxx) maxx=x,npos=d;

	if(maxx<=minn){return minn;}
	int tminn=inf;
	int last=a[pos];
	a[pos]=npos;
	sort(a+1,a+1+n);
	rep(i,1,n){
		x=a[i]-a[i-1]-1;
		if(x<tminn) tminn=x;
	}
	rep(i,1,n) if(a[i]==npos){a[i]=last;break;}
	sort(a+1,a+1+n);
	return tminn;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
	//freopen("2.out","w",stdout);
#endif
	int cse;cin>>cse;
	while(cse--){
		getchar();
		cin>>n>>d;a[n+1]=d;
		rep(i,1,n){cin>>a[i];}
		int pos;minn=inf;
		rep(i,1,n){
			int x=a[i]-a[i-1]-1;
			if(x<minn) minn=x,pos=i;
		}
		cout<<max(solve(pos),solve(pos-1))<<"\n";
	}
	return 0;
}