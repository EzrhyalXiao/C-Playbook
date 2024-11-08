// https://codeforces.com/contest/1638/problem/E
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rpe(i,a,b) for(int i=a;i>=b;--i)
#define pts putchar('\n')
#define ptc putchar(' ')
#define pb push_back 
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int N=1e6;
const int maxn=N+9;
const int inf=0x7f7f7f7f;
const int maxm=4*N+9;

int n,q;
ll val[maxn];

ll t[maxn];
inline int low(int x){return (x&-x);}
void update(int pos,ll v){
	for(;pos<=n;pos+=low(pos)) t[pos]+=v;
}
ll query(int x){ll sum=0;
	for(;x;x-=low(x)) sum+=t[x];
	return sum;
}
struct node{
	int l,r,c;
	bool operator < (const node x)const{
		return l<x.l;
	}
};
set<node>s;

void split(int x){
	auto it = s.lower_bound({x,0,0});
	if(it!=s.end()&&it->l==x) return;
	it--;
	int L=it->l,R=it->r,C=it->c;
	s.erase(it);
	s.insert({L,x-1,C});
	s.insert({x,R,C}); 
}

void solve(int l,int r,int c){
	split(l);split(r+1);
	auto itl=s.lower_bound({l,0,0});
	auto itr=s.lower_bound({r+1,0,0});
	for(auto it=itl;it!=itr;it++){
		update(it->l,val[it->c]);
		update(it->r+1,-val[it->c]);
	}
	s.erase(itl,itr);
	s.insert({l,r,c});
	update(l,-val[c]);update(r+1,val[c]);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
//	freopen("1.out","w",stdout);
#endif
	int cse=1;//cin>>cse;
	while(cse--){
		cin>>n>>q;
		s.insert({1,n,1});
		char ss[10];int a,b,c;
		while(q--){
			cin>>ss;
			if(ss[0]=='C'){
				scanf("%d %d %d",&a,&b,&c);
				solve(a,b,c);
			}
			else if(ss[0]=='A'){
				scanf("%d %d",&a,&b);
				val[a]+=b;
			}
			else{
				scanf("%d",&a);
				auto it = s.upper_bound({a,0,0});
				it--;
				printf("%lld\n",query(a)+val[it->c]);
			}
		}
	}
	return 0;
}