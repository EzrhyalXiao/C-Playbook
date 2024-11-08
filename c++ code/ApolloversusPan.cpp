// https://codeforces.com/contest/1466/submission/102944263
#include<bits/stdc++.h>
#define pts putchar('\n');
#define ptc putchar(' ');
#define rep(i,a,b) for(register int i=a;i<=b;++i)
#define rpe(i,a,b) for(register int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
const int maxn=5e5+9;
const int maxm=4e3+9;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;

ll read(){
    ll a=1,b=0;char c=getchar();
    while(c>'9'||c<'0'){if(c=='-') a=-1;c=getchar();}
    while(c>='0'&&c<='9'){b=(b<<1)+(b<<3)+(c^'0');c=getchar();}
    return a*b;
}
void print(ll x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) print(x/10);
    putchar(x%10+'0');
} 
int T;
int n;
ll a[maxn],ans_or,ans_and,cnt[70],ans;
int main(){ll tmp,num=0;
	T=read();
	while(T--){
		n=read();
		rep(i,0,60) cnt[i]=0;
		rep(i,1,n){
			a[i]=read();
			tmp=a[i];num=0;
			while(tmp){
				if(tmp&1) cnt[num]++;
				tmp>>=1;num++;
			}
		}
		ans=0;
		rep(j,1,n){
			ans_or=ans_and=0;
			rep(i,0,60){
				if((a[j]>>i)&1){
					ans_and=(ans_and+(1LL<<i)%mod*cnt[i]%mod)%mod;
					ans_or=(ans_or+(1LL<<i)%mod*n%mod)%mod;
				}
				else {
					ans_or=(ans_or+(1LL<<i)%mod*cnt[i]%mod)%mod;
				}
			}
			ans=(ans+ans_or*ans_and%mod)%mod;
		}
		print(ans);pts;
	}
	return 0;
}