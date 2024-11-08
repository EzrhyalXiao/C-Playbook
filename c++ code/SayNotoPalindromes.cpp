// https://codeforces.com/contest/1555/problem/D
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rpe(i,a,b) for(int i=a;i>=b;--i)
#define pts putchar('\n')
#define ptc putchar(' ')
#define pb push_back
typedef long long ll;
typedef pair<int,int>P;
typedef unsigned long long ull;
const int inf=0x7f7f7f7f;
const ll linf=1e18;
const int maxn=2e5+9;
const int maxm=2e5+9;
const double PI=3.1415926;
const double eps=1e-5;
const ll mod=998244353;
const int base=131;
const int N=1e6;

int n,m;
char s[maxn];
int sum[10][maxn];
int main(){
#ifndef ONLINE_JUDGE
    freopen("in0.txt","r",stdin);
#endif
    cin>>n>>m;
    scanf("%s",s+1);
    //1
    rep(i,1,n){
        if(i%3==0&&s[i]!='a') sum[1][i]++;  
        if(i%3==1&&s[i]!='b') sum[1][i]++;
        if(i%3==2&&s[i]!='c') sum[1][i]++;
        sum[1][i]+=sum[1][i-1];
    }
    //2
    rep(i,1,n){
        if(i%3==0&&s[i]!='a') sum[2][i]++;  
        if(i%3==1&&s[i]!='c') sum[2][i]++;
        if(i%3==2&&s[i]!='b') sum[2][i]++;
        sum[2][i]+=sum[2][i-1];
    }
    //3
    rep(i,1,n){
        if(i%3==0&&s[i]!='b') sum[3][i]++;  
        if(i%3==1&&s[i]!='a') sum[3][i]++;
        if(i%3==2&&s[i]!='c') sum[3][i]++;
        sum[3][i]+=sum[3][i-1];
    }
    //4
    rep(i,1,n){
        if(i%3==0&&s[i]!='b') sum[4][i]++;  
        if(i%3==1&&s[i]!='c') sum[4][i]++;
        if(i%3==2&&s[i]!='a') sum[4][i]++;
        sum[4][i]+=sum[4][i-1];
    }
    //5
    rep(i,1,n){
        if(i%3==0&&s[i]!='c') sum[5][i]++;  
        if(i%3==1&&s[i]!='a') sum[5][i]++;
        if(i%3==2&&s[i]!='b') sum[5][i]++;
        sum[5][i]+=sum[5][i-1];
    }
    //6
    rep(i,1,n){
        if(i%3==0&&s[i]!='c') sum[6][i]++;  
        if(i%3==1&&s[i]!='b') sum[6][i]++;
        if(i%3==2&&s[i]!='a') sum[6][i]++;
        sum[6][i]+=sum[6][i-1];
    }
    int l,r;
    while(m--){
        scanf("%d %d",&l,&r);
        int ans=inf;
        rep(i,1,6){
            ans=min(ans,sum[i][r]-sum[i][l-1]);
        }
        printf("%d\n",ans);
    }
    return 0LL;
}
