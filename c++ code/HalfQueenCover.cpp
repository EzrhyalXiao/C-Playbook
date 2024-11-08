// https://codeforces.com/contest/1668/problem/E
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rpe(i,a,b) for(int i=a;i>=b;--i)
#define pts putchar('\n')
#define py putchar(' ')
#define pb push_back 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const ll N=5e5;
const int maxn=N+9;
const int inf=0x7f7f7f7f;
const ll linf=1e18;
const int maxm=4*N+9;
const int mod=2;
const int base=31;
const double eps=1e-4;

int n;
int num=0;bool flag=0;
void Out(){
	int k=n/3;
	if(num==0) return;
	rep(x,1,k){
		cout<<x<<" "<<1+k-x<<endl;
		num--;
		if(num==0) return;
	}
	rep(y,2*k+2,n){
		if(flag==1){
			int xx=2*k+n+2-y,yy=y;
			xx--,yy--;
			cout<<yy<<" "<<xx<<endl;
		}
		else cout<<y<<" "<<2*k+n+2-y<<endl;
		num--;
		if(num==0) return;
	}
	cout<<2*k+1<<" "<<(k<<1|1)<<endl;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
	//freopen("1.out","w",stdout);
#endif
	cin>>n;
	num = 2*(n/3) + (n%3!=0);
	cout<<num<<endl;
	if(n%3==0) Out();
	else if(n%3==1){
		cout<<n<<" "<<n<<endl;num--;
		n--;Out();
	}
	else{
		n++;flag=1;
		Out();
	}
	return 0;
}