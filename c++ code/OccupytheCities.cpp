// https://codeforces.com/gym/103409/problem/G
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rpe(i,a,b) for(int i=a;i>=b;--i)
#define pts putchar('\n')
#define ptc putchar(' ')
#define pb push_back 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int N=1e6;
const int maxn=N+9;
const int inf=0x7f7f7f7f;
const ll linf=1e18;
const int maxm=N*2+9;
const int mod=998244353;
const int base=131;

int n;
char s[maxn];

bool check(int x){
	int len=0;
	rep(i,1,n){
		if(s[i]=='0') len++;
		else{
			if(len<x) len=-x;
			else if(len==x) len=-x+1;
			else return 0;
		}
	}
	if(len>0) return 0;
	return 1;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
#endif
	int cse=1;cin>>cse;
	while(cse--){
		cin>>n;
		cin>>s+1;
		int flag=1;
		rep(i,1,n) flag&=(s[i]-'0');
		if(flag==1) {puts("0");continue;}
		int l=1,r=n,ans=n;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid)) ans=mid,r=mid-1;
			else l=mid+1; 
		}
		cout<<ans<<endl;
	}
	return 0;
}