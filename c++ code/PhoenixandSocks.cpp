// https://codeforces.com/contest/1515/problem/D
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rpe(i,a,b) for(int i=a;i>=b;--i)
#define pts putchar('\n')
#define ptc putchar(' ')
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
const int inf=0x7f7f7f7f;
const int maxn=2e5+9;
const int maxm=2e2+9;
const double PI=3.1415926;
const double eps=1e-7;
const int mod=1e9+7;
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

int T;
int n,l,r;
int s[maxn];
int t[maxn];
int main(){
#ifndef ONLINE_JUDGE
    freopen("in0.txt","r",stdin);
	//freopen("2.out","w",stdout);
#endif
	T=read();
	while(T--){
		n=read();l=read();r=read();
		int num=abs(r-l)/2;
		bool flag=(l>r);
		rep(i,1,l) s[read()]++;
		rep(i,1,r) {
			int x=read();
			if(s[x]) s[x]--;
			else t[x]++;
		}
		int L=0,R=0,ans=0;
		rep(i,1,n){
			if(s[i]) {
				if(flag==1&&num>0){
					if(s[i]/2>=num) ans+=num,s[i]-=num*2,num=0;
					else num-=s[i]/2,ans+=s[i]/2,s[i]=s[i]&1;
				}
				L+=s[i];
			}
			else{
				if(flag==0&&num>0){
					if(t[i]/2>=num) ans+=num,t[i]-=num*2,num=0;
					else num-=t[i]/2,ans+=t[i]/2,t[i]=t[i]&1;
				}
				R+=t[i];
			}
			s[i]=t[i]=0;
		}
		ans+=max(L,R);
		print(ans);pts;
	}
    return 0;
}