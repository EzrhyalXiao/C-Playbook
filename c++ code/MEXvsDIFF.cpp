//https://codeforces.com/contest/1684/problem/E
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

int n,k;
map<int,int>mp;
vector<int>a;
int main(){
#ifndef ONLINE_JUDGE    
	freopen("in0.txt","r",stdin);
//	freopen("1.out","w",stdout);
#endif
	int cse;cin>>cse;
    while(cse--){
        cin>>n>>k;mp.clear();a.clear();
        rep(i,1,n){
            int x;scanf("%d",&x);
            mp[x]++;
        }
        int mex,tmp=k;
        rep(i,0,n){
            if(!mp[i]) {
                if(tmp) tmp--;
                else{
                    mex=i;break;
                }
            }
        }
        for(auto x:mp){
            if(x.first>mex) a.pb(x.second);
        }
        sort(a.begin(),a.end());
        tmp=0;
        for(auto x:a){
            if(k>=x) k-=x,tmp++;
            else break;
        }
        cout<<a.size()-tmp<<endl;
    }  
	return 0;
}