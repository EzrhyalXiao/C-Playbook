// https://codeforces.com/contest/1701/problem/D
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rpe(i,a,b) for(int i=a;i>=b;--i)
#define pts putchar('\n')
#define ptc putchar(' ')
#define pb push_back 
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int N=5e5;
const int maxn=N+9;
const int inf=0x7f7f7f7f;
const ll linf = 1e18;
const int maxm=20*N+9;

int n;
int a[maxn];
int l[maxn],r[maxn];

int ans[maxn];

set<P>s;
vector<int>G[maxn];

int main(){    
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
#endif  
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        rep(i,1,n){
            int x;scanf("%d",&x);
            if(x==0) r[i]=n;
            else r[i]=i/x;
            l[i] = i/(x+1)+1;
            G[l[i]].pb(i);
        }
        rep(i,1,n){
            for(auto x:G[i]) s.insert({r[x],x});
            ans[(*s.begin()).second]=i;
            s.erase(s.begin());
        }
        rep(i,1,n) printf("%d ",ans[i]);pts;
        rep(i,1,n) G[i].clear();
        s.clear(); 
    }
    return 0; 
}