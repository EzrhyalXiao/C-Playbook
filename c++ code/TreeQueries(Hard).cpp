// https://codeforces.com/contest/1695/problem/D2
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

int n;
vector<int>G[maxn];

int dfs(int now,int fa){
    int sum=0,z=0;
    for(auto x:G[now]){
        if(x==fa) continue;
        int tmp=dfs(x,now);
        sum+=tmp;
        if(tmp==0) z++;
    }
    return sum+max(0,z-1);
}

int main(){    
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
   // freopen("5.out","w",stdout);
#endif
int T;
    cin>>T;
    while(T--){
        cin>>n;
        rep(i,1,n) G[i].clear();
        rep(i,1,n-1){
            int x,y;
            cin>>x>>y;
            G[x].pb(y);G[y].pb(x);
        }
        int maxx=0;
        rep(i,1,n) maxx=max(maxx,(int)G[i].size());
        if(maxx==0) puts("0");
        else if(maxx<3) puts("1");
        else{
            rep(i,1,n){
                if((int)G[i].size()>=3){
                    cout<<dfs(i,i)<<endl;
                    break;
                }
            }
        }
    }
    return 0; 
}