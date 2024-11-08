// https://codeforces.com/contest/1695/problem/E
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rpe(i,a,b) for(int i=a;i>=b;--i)
#define pts putchar('\n')
#define ptc putchar(' ')
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int N=6e5;
const int maxn=N+9;
const int inf=0x7f7f7f7f;
const int maxm=20*N+9;
const int mod=1e9+7;

int n;
vector<P>G[maxn];
int vis[maxn];
int col[maxn];
vector<int>node;


void dfs(int now){
    node.pb(now);
    if(col[now]) return;
    col[now]=1;
    for(auto x:G[now]){
        if(!vis[x.second]){
            vis[x.second]=1;
            dfs(x.first);
            node.pb(now);
        }
    }
}
char a[maxn],b[maxn],c[maxn],d[maxn];
int ans[2][maxn],k=0;
int main(){    
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
#endif
    cin>>n;
    rep(i,1,n){
        int x,y;
        cin>>x>>y;
        G[x].pb({y,i});
        G[y].pb({x,i});
    }   
    rep(i,1,n<<1){
        if(!col[i]){
            node.clear();
            dfs(i);
            int len=node.size();
            if(len==3){
                puts("-1");return 0;
            }
            if(len<3) continue;
            len--;
            auto it=node.begin();
            rep(i,0,len/2-1) ans[0][k+i] = *it++;
            rpe(i,len/2-1,0) ans[1][k+i] =*it++;
            if(len%4==0){
                rep(i,0,len/2-1){
                    if(i&1) b[k+i]=a[k+i]='R',c[k+i]=d[k+i]='L';
                    else b[k+i]=a[k+i]='L',c[k+i]=d[k+i]='R';
                }
                c[k]=c[k+len/2-1]='U';
                d[k]=d[k+len/2-1]='D';
            }   
            else{
                rep(i,0,len/2-1){
                    if(i&1) b[k+i]=a[k+i]='R',c[k+i]=d[k+i]='L';
                    else b[k+i]=a[k+i]='L',c[k+i]=d[k+i]='R';
                }
                a[k+len/2-1]='U';b[k+len/2-1]='D';
                c[k]='U';d[k]='D';
            }
            k+=len/2;
        }
    }
    printf("2 %d\n",n);
    rep(i,0,1){
        rep(j,0,n-1) 
            printf("%d ",ans[i][j]);
        pts;
    }
    cout<<a<<"\n"<<b<<"\n";
    cout<<c<<endl<<d<<endl;
    return 0;
}