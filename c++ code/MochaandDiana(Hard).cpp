// https://codeforces.com/contest/1559/problem/D2
#include<bits/stdc++.h>
using namespace std;
#define N 100010
int fa1[N],fa2[N];
set<pair<int,int> > rows;
set<int> row[N],col[N];
set<int>::iterator it;
map<int,int> mp[N];
pair<int,int> Ans[N];
int getfa(int *fa,int x){
	if (x==fa[x]){
		return x;
	}
	return fa[x]=getfa(fa,fa[x]);
}
void Merge_row(int x,int y){
	for (it=row[y].begin();it!=row[y].end();it++){
		mp[x][*it]=mp[y][*it];
		row[x].insert(*it);
		col[*it].erase(y);
		col[*it].insert(x);
	}
}
void Merge_col(int x,int y){
	for (it=col[y].begin();it!=col[y].end();it++){
		mp[*it][x]=mp[*it][y];
		col[x].insert(*it);
		row[*it].erase(y);
		row[*it].insert(x);
	}
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("in0.txt","r",stdin);
#endif
	int n,m1,m2,h=0,i;
	scanf("%d%d%d",&n,&m1,&m2);
	for (i=1;i<=n;i++){
		fa1[i]=fa2[i]=i;
	}
	for (i=1;i<=m1;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		int p=getfa(fa1,x),q=getfa(fa1,y);
		fa1[p]=q;
	}
	for (i=1;i<=m2;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		int p=getfa(fa2,x),q=getfa(fa2,y);
		fa2[p]=q;
	}
	if (m1<m2){
		swap(fa1,fa2);
	}
	
	for (i=1;i<=n;i++){
		int p1=getfa(fa1,i),p2=getfa(fa2,i);
		mp[p1][p2]=i;
		row[p1].insert(p2);
		col[p2].insert(p1);
	}
	for (i=1;i<=n;i++){
		if (getfa(fa1,i)==i){
			rows.insert(make_pair(-row[i].size(),i));
		}
	}
	
	while (rows.size()>1){
		int x=rows.begin()->second;
		rows.erase(rows.begin());
		int y=rows.begin()->second;
		rows.erase(rows.begin());
		if (row[x].size()<row[y].size()){
			swap(x,y);
		}
		it=row[x].begin();
		int a=*it,b=*row[y].begin();
		if (a==b){
			a=*++it;
		}
		Ans[++h]=make_pair(mp[x][a],mp[y][b]);
		if (col[a].size()<col[b].size()){
			swap(a,b);
		}
		Merge_row(x,y);
		Merge_col(a,b);
		rows.insert(make_pair(-row[x].size(),x));
	}
	
	printf("%d\n",h);
	for (i=1;i<=h;i++){
		printf("%d %d\n",Ans[i].first,Ans[i].second);
	}
	return 0;
}