// https://codeforces.com/gym/372394/problem/D
#include<cstdio>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
const int mx=70005,maxn=205;
int d,kd;
int a[maxn],er[maxn];
int hf[mx],mbs[maxn],tb[2005];
ll bs[maxn];
ll dp[mx][maxn];
struct node{
	int zt,w;
	bool operator<(const node &p)
	const{
		return w<p.w;
	}
}tm[mx];
int main(){
	scanf("%d%d",&d,&kd);
	for(int i=1;i<=d;++i) scanf("%d",&a[i]);
	sort(a+1,a+1+d);
	er[0]=1;bs[0]=1;hf[1]=0;mbs[0]=1%kd;
	for(int i=1;i<=d;++i){
		er[i]=er[i-1]<<1;hf[er[i]]=i;
		bs[i]=bs[i-1]*10;mbs[i]=bs[i]%kd;
//		printf("k=%d  bs=%lld  mbs=%d\n",i,bs[i],mbs[i]);
	}
	int hd=kd*9;
	for(int i=0;i<=hd;++i) tb[i]=i%kd;
	int tot=er[d];
	tm[0].zt=0;tm[0].w=0;
	for(int i=1;i<tot;++i){
		tm[i].zt=i;tm[i].w=tm[i-(i&(-i))].w+1;
	}
	sort(tm,tm+tot);
	int st=0;
	for(int i=d;i>=1;--i){
		int ad=d-i;
		while(st<tot&&tm[st].w==ad){
			int j=tm[st].zt;++st;
			int pj=~j;pj&=(tot-1);
			while(pj){
				int lb=pj&(-pj);
				pj-=lb;
				int k=hf[lb];
				for(int p=0;p<kd;++p){
					if(dp[j][p]==0&&j!=0) continue;
					if(p!=0&&j==0) break;
					ll nt=dp[j][p];int nad=mbs[k]*a[i];
					int zt=j|er[k],pt;
//					printf("k=%d  p=%d  nad=%d\n",k,p,nad);
					nt+=(bs[k]*a[i]);pt=p+tb[nad];if(pt>=kd) pt-=kd;  
					if(dp[zt][pt]<nt) dp[zt][pt]=nt;
				}
			}
		}
	}
	
//	for(int i=0;i<=tot;++i) for(int j=0;j<kd;++j) if(dp[i][j]) printf("dp[%d][%d]=%lld\n",i,j,dp[i][j]);
	
	--tot;
	for(int i=kd-1;i>=0;--i) if(dp[tot][i]){
		printf("%lld",dp[tot][i]);break;
	}
	return 0;
} 