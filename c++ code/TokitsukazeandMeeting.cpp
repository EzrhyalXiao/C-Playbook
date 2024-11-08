// https://codeforces.com/contest/1678/problem/D
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rpe(i,a,b) for(int i=a;i>=b;--i)
#define pts putchar('\n')
#define ptc putchar(' ')
#define pb push_back 
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int N=5e3;
const int maxn=N+9;
const int inf=0x7f7f7f7f;
const int maxm=1e6+9;
const int mod=998244353;

int n,m;
char s[maxm];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
	//freopen("2.out","w",stdout);
#endif
	int cse;cin>>cse;
	while(cse--){
		cin>>n>>m;
		vector<int>Ans(n*m+1),sum(n*m+1);
		vector<int>b(m+1);
		scanf("%s",s+1);
		rep(i,1,n*m) sum[i]=sum[i-1]+s[i]-'0';
		rep(i,1,n*m){
			int tmp = sum[i] - sum[max(0,i-m)];
			if(i>m) Ans[i]=Ans[i-m];
			Ans[i]+=(tmp>0);
		}
		int ans=0;
		rep(i,1,n){
			int flag=0;
			rep(j,1,m){
				int id = (i-1)*m+j;
				if(s[id]=='1') {
					if(b[j]==0) ans++;
					b[j]=1;
				}
				Ans[id] += ans;
			}
		}
		rep(i,1,n*m) printf("%d ",Ans[i]);
		pts;
	}
	return 0;
}