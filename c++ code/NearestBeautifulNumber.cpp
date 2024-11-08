// https://codeforces.com/contest/1560/problem/F2
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

char n[20];
int m,k;

set<char>s;

void solve(){
    while(1){
        s.clear();
        rep(i,1,m) s.insert(n[i]);
        if(s.size()<=k) return; 
        s.clear();
        int now=1;
        while(1){
            s.insert(n[now]);
            if(s.size()>k){
                while(n[now]=='9') now--;
                n[now]++;
                rep(i,now+1,m) n[i]='0';
                break;
            }
            now++;
        }
    }
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
#endif
    int cse;cin>>cse;
    while(cse--){
        scanf("%s",n+1);m=strlen(n+1);
        cin>>k;s.clear();
        bool flag=0;
        solve();
        rep(i,1,m) putchar(n[i]);
        pts;
    }
    return 0;
}