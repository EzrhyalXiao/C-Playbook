// https://codeforces.com/contest/1399/problem/E2
#include<bits/stdc++.h>
#define pts putchar('\n')
#define ptc putchar(' ')
#define rep(i,a,b) for(register int i=a;i<=b;++i)
#define rpe(i,a,b) for(register int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=2e5+9;
const int maxm=1e5+9;
const ll inf=1e18;
const int mod=1e9+7;
int T,n;
ll S,sum;ll ans;
ll G1[maxn*10],G2[maxn*10],g1,g2;

struct Edge{
	int to,from,coin;ll cost;
}edge[maxn];
int last[maxm],cnt=0,ru[maxm];
struct Point{
	ll sze,val;bool sign;
}dot[maxm],tmp;
priority_queue<Point>q1,q2;
ll AK(Point a){return a.sze*(a.val-a.val/2);}
bool operator < (Point x,Point y){return AK(x)<AK(y);}
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

void add(int a,int b,ll c,int d){ru[b]++;
	edge[++cnt].to=b;edge[cnt].cost=c;edge[cnt].coin=d;
	edge[cnt].from=last[a];last[a]=cnt;
}
void dfs(int now,int fa){
	if(ru[now]==1) dot[now].sze=1; 
	for(int i=last[now];i;i=edge[i].from){
		int to=edge[i].to,cost=edge[i].cost;
		if(to==fa) continue;
		if(edge[i].coin==2) dot[to].sign=1;
		dot[to].val=cost;
		dfs(to,now);
		dot[now].sze+=dot[to].sze;
	}
}
void clear(){
	sum=cnt=0;g2=g1=0;ans=inf;
	rep(i,1,n) ru[i]=last[i]=dot[i].sze=dot[i].val=dot[i].sign=0;
	while(!q1.empty())q1.pop();	while(!q2.empty())q2.pop();
}
ll check(ll num){
	int l=0,r=g2,mid;ll retu=inf;
	while(l<=r){
		mid=(l+r)>>1;
		if(G2[mid]>=num) r=mid-1,retu=mid;
		else l=mid+1;
	}
	return retu;
}
int main (){int a,b,d,pos;ll c;
#ifndef ONLINE_JUDGE
	freopen("in1.txt","r",stdin);
	
#endif
	T=read();
	while(T--){		
		n=read();S=read();
		clear();
		rep(i,1,n){
			ru[i]=last[i]=0;
			dot[i].sze=dot[i].val=0;
		}
		rep(i,1,n-1){
			a=read(),b=read(),c=read(),d=read();
			add(a,b,c,d);add(b,a,c,d);
		}		
		dot[1].val=0;
		dfs(1,0);
		rep(i,2,n) {
			sum+=1LL*dot[i].sze*dot[i].val;
			if(!dot[i].sign) q1.push(dot[i]);
			else q2.push(dot[i]);
		}
		if(sum<=S){puts("0");continue;}
		while(!q1.empty()){
			tmp=q1.top();q1.pop();
			g1++;
			G1[g1]=AK(tmp);
			G1[g1]+=G1[g1-1];
			tmp.val/=2;
			if(tmp.val) q1.push(tmp);
		}
		while(!q2.empty()){
			tmp=q2.top();q2.pop();
			g2++;
			G2[g2]=AK(tmp);
			G2[g2]+=G2[g2-1];
			tmp.val/=2;
			if(tmp.val) q2.push(tmp);
		}
		rep(i,0,g1){
			pos=check(sum-S-G1[i]);
			ans=min(ans,(ll)i+pos*2);
		}
		print(ans);pts;
	}
	return 0;	
} 

 