// https://codeforces.com/contest/1560/problem/E
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rpe(i,a,b) for(int i=a;i>=b;--i)
#define pts putchar('\n')
#define ptc putchar(' ')
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>P;
const int inf=0x7f7f7f7f;
const ll linf=1e18;
const int maxn=5e5+9;
const int maxm=1e7+9;
const double PI=acos(-1);
const double eps=1e-5;
const ll mod=998244353;
const int base=131;

char s[maxn];
ll n;
int vis[30],num[30];
vector<char>ans;

int suf[maxn],pre[maxn];

bool check(int pos){
    rep(i,1,pos) suf[i]=i+1,pre[i]=i-1;
    suf[0]=1;pre[1]=0;
    int t=1,tep=0,now=pos+1;
    for(auto x:ans){
        t++;
        int l=now,r=now + pos - tep - num[x-'a'+1]-1;
        rep(i,1,pos) {
            if(s[i]==x){
                suf[pre[i]]=suf[i];
                pre[suf[i]]=pre[i];
            }
        }
        int Now=suf[0];
        rep(i,l,r){
            if(s[i]!=s[Now]) return 1;
            Now=suf[Now]; 
        }
        tep+=num[x-'a'+1];
        now=r+1;
    }
    return 0;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
#endif
    int cse;cin>>cse;
    while(cse--){
        ans.clear();
        memset(vis,0,sizeof(vis));
        memset(num,0,sizeof(num));
        scanf("%s",s+1);n=strlen(s+1);
        rpe(i,n,1){
            if(!vis[s[i]-'a'+1]) {
                vis[s[i]-'a'+1]=1;
                ans.pb(s[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        bool flag=0;
        rep(i,1,n){
            num[s[i]-'a'+1]++;
            ll tmp=i,tep=0;
            for(auto x:ans){tmp+=i-tep-num[x-'a'+1];tep+=num[x-'a'+1];}
            if(tmp==n){
                if(check(i)) break;
                rep(j,1,i) putchar(s[j]);
                ptc;
                for(auto x:ans){putchar(x);}
                pts;
                flag=1;
                break;
            }
        }    
        if(flag==0) puts("-1");   
    }
    return 0;
}