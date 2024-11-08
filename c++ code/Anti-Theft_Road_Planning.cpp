// https://codeforces.com/contest/1673/problem/F
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
const int N=4e4;
const int maxn=2*N+9;
const int inf=0x7f7f7f7f;
const ll linf=1e18;
const int maxm=4*N+9;
const int mod=1e9+7;
const int base=31;
const double eps=1e-4;

int n,k;
int a[40][40];
int b[40][40];
void Out(){
	rep(i,1,n){
		rep(j,1,n-1) cout<<a[i][j]<<" ",fflush(stdout);
		cout<<endl;fflush(stdout);
	}
	rep(i,1,n-1){
		rep(j,1,n) cout<<b[i][j]<<" ",fflush(stdout);
		cout<<endl;fflush(stdout);
	}
}
void dfs(int x,int y,int xx,int yy,int num){
	if(x==1&&y==1) {
		return;
	}
	rep(i,1,y) b[x/2+xx][i+yy] = num;
	num>>=1;
	rep(i,1,x) a[i+xx][y/2+yy] = num;
	num>>=1;
	dfs(x/2,y/2,xx,yy,num);
	//Out();
	dfs(x/2,y/2,xx+x/2,yy,num);
	//Out();
	dfs(x/2,y/2,x/2+xx,y/2+yy,num);
	//Out();
	dfs(x/2,y/2,xx,y/2+yy,num);
	//Out();
}

int val[40][40];
map<int,P>mp;

int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
//	freopen("1.out","w",stdout);
#endif
	cin>>n>>k;
	fflush(stdout);
	dfs(32,32,0,0,512);
	rep(i,2,n) val[i][1] = val[i-1][1]^b[i-1][1];
	rep(i,1,n){
		rep(j,2,n) val[i][j] = val[i][j-1]^a[i][j-1];
	} 
	rep(i,1,n){
		rep(j,1,n){
			mp[val[i][j]]=P(i,j);
		}
	}
	Out();int x,y=0;
	while(k--){
		fflush(stdout);
		cin>>x;
		fflush(stdout);
		bool flag=0;
		rep(i,1,n){
			rep(j,1,n){
				int tmp=val[i][j];
				tmp = tmp^y;
				if(tmp==x) {
					flag=1;
					printf("%d %d\n",i,j);
					y=val[i][j];
					break;
				}
			}
			if(flag==1) break;
		}
		fflush(stdout);
	}
	return 0;
}