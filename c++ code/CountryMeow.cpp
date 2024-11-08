// https://codeforces.com/gym/101981/attachments
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const double eps = 1e-3;
struct Point {
	double x, y, z;
	Point() {
		x = y = z = 0.0;
	}
	Point(double xx, double yy, double zz) {
		x = xx, y = yy, z = zz;
	}
	Point operator-(const Point& p) {
		return Point(x-p.x, y-p.y, z-p.z);
	}
	double dis() {
		return sqrt(x*x+y*y+z*z);
	}
}pt[110];
int n;
 
double cal(double x, double y, double z) {
	double res = 0;
	for(int i=1;i<=n;i++) {
		res = max(res, (pt[i]-Point(x, y, z)).dis());
	}
	return res;
}
 
double cal2(double x, double y) {
	double res = 1e18;
	double l = -100000, r = 100000;
	while(r-l>eps) {
		double m1 = (r-l)/3 + l;
		double m2 = (r-l)/3*2 + l;
		double res1 = cal(x, y, m1), res2 = cal(x, y, m2);
		res = min(res, min(res1, res2));
		if(res1<res2) r = m2;
		else l = m1;
	}
	return res;
}
 
double cal3(double x) {
	double res = 1e18;
	double l = -100000, r = 100000;
	while(r-l>eps) {
		double m1 = (r-l)/3 + l;
		double m2 = (r-l)/3*2 + l;
		double res1 = cal2(x, m1), res2 = cal2(x, m2);
		res = min(res, min(res1, res2));
		if(res1<res2) r = m2;
		else l = m1;
	}
	return res;
}
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
	cin>>n;
	for(int i=1;i<=n;i++) {
		scanf("%lf %lf %lf", &pt[i].x, &pt[i].y, &pt[i].z);
	}
 
	double res = 1e18;
	double l = -100000, r = 100000;
	while(r-l>eps) {
		double m1 = (r-l)/3 + l;
		double m2 = (r-l)/3*2 + l;
		double res1 = cal3(m1), res2 = cal3(m2);
		res = min(res, min(res1, res2));
		if(res1<res2) r = m2;
		else l = m1;
	}
	printf("%.10lf\n", res);
	return 0;
}