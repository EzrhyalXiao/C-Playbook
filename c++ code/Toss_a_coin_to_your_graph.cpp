// https://codeforces.com/contest/1679/problem/D
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
const ll N=2e5;
const int maxn=N+9;
const int inf=0x7f7f7f7f;
const ll linf=1e18;
const int maxm=4*N+9;
const int mod=1e9+7;
const int base=31;
const double eps=1e-4;

int n,m;
ll k;
int val[maxn];
int a[maxn],b[maxn];
vector<int>G[maxn];

int de[maxn],dis[maxn],vis[maxn];
queue<int>q;

bool check(int x){
    rep(i,1,n) G[i].clear(),de[i]=vis[i]=0,dis[i]=-1;
    rep(i,1,m){
        int u=a[i],v=b[i];
        if(val[u]<=x&&val[v]<=x) G[u].pb(v),de[v]++;
    }
    while(!q.empty())q.pop();
    rep(i,1,n) if(!de[i] &&val[i]<=x) q.push(i),dis[i]=1;
    int tmp=-1;
    while(!q.empty()){
        int now=q.front();q.pop();tmp=max(tmp,dis[now]);
        vis[now]=1;
        for(auto y:G[now]){
            de[y]--;dis[y]=max(dis[now]+1,dis[y]);
            if(de[y]==0) q.push(y);
        }
    }
    if(tmp>=k) return 1;
    rep(i,1,n){
        if(val[i]<=x&&!vis[i]) return 1;
    }
    return 0;
}

int main(){
#ifndef ONLINE_JUDGE    
	freopen("in0.txt","r",stdin);
//	freopen("1.out","w",stdout);
#endif
	cin>>n>>m>>k;
	rep(i,1,n) scanf("%d",&val[i]);
	rep(i,1,m){
		scanf("%d %d",&a[i],&b[i]);
	}
    int l=1,r=1e9,ans=-1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)) ans=mid,r=mid-1;
        else l=mid+1;
    }
    cout<<ans;
	return 0;
}
