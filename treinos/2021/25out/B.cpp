#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int MxN = 5123;
const int MOD = 1e9 + 7;

const double EPS = 1e-9;

struct point {
	double x,y;
	point () {}
	point (double _x,double _y):x(_x),y(_y){}
};
struct seg {
	point a,b;
	seg () {}
	seg (point _a,point _b):a(_a),b(_b){}
};
struct vec{
	double x,y;
	vec () {}
	vec (double _x,double _y):x(_x),y(_y){}
	vec (point a,point b):x(b.x-a.x),y(b.y-a.y){}
};

double dot (vec u , vec v){
	return u.x*v.x + u.y*v.y;
}

double cross (vec u, vec v){
	return u.x*v.y - u.y*v.x;
}

vec scale (double l , vec u){
	l /= sqrt(dot(u, u));
	return vec (l*u.x, l*u.y);
}

point trans (point a, vec u){
	return point(a.x + u.x, a.y + u.y);
}

double dpp(point a, point b){
	vec ab(a,b);
	return sqrt(dot(ab,ab));
}

double dps (point p ,seg s){
	vec ab(s.a,s.b), ap(s.a,p);
	double norm_sq = dot (ab,ab);
	if (norm_sq < EPS) return dpp(p,s.a);
	double l = dot(ab,ap) / dot(ab,ab);
	if (l < 0.) return dpp (p,s.a);
	if (l > 1.) return dpp (p,s.b);
	point c = trans(s.a,scale(l,ab));
	return dpp (c,p);
}

int collinear (seg s, seg r){
	return fabs(cross(vec(s.a,s.b),vec(s.a,r.a)))<EPS&&
		   fabs(cross(vec(s.a,s.b),vec(s.a,r.b)))<EPS;
}

int intersect (seg s, seg r){ // works only for non-collinear
	return cross(vec(s.a,s.b),vec(s.a,r.a))*
		   cross(vec(s.a,s.b),vec(s.a,r.b))<EPS && 
	       cross(vec(r.a,r.b),vec(r.a,s.a))*
		   cross(vec(r.a,r.b),vec(r.a,s.b))<EPS; 
}

double dss(seg s, seg r){
	if (!collinear(s,r) && intersect (s,r)) return 0;
	return min (dps(s.a,r),min(dps(s.b,r),min(dps(r.a,s),dps(r.b,s))));
}

double area(point a, point b, point c)
{
    // double dArea = ((b.x - a.x)*(c.y - a.y) - (c.x - a.x)*(b.y - a.y))/2.0;
    // return (dArea > 0.0) ? dArea : -dArea;
	return abs(cross(vec(a, b), vec(b,c)))/2.0;
}


int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	pii A, B, C;
	cin >> A.first >> A.second;
	cin >> B.first >> B.second;
	cin >> C.first >> C.second;
	int nab;
	int minmax[3][2];
	for (int i = 0; i < 3; ++i)
	{
		minmax[i][0] = 1e9;
		minmax[i][1] = 0;
	}
	for (int lado = 0; lado < 3; ++lado) {
		cin >> nab;
		for (int i = 0; i < nab; ++i) {
			int inp;
			cin >> inp;
			minmax[lado][0] = min(minmax[lado][0], inp);
			minmax[lado][1] = max(minmax[lado][1], inp);
		}
	}
	// for (int i = 0; i < 3; ++i)
	// {
	// 	for (int j = 0; j < 2; ++j)
	// 	{
	// 		cout << minmax[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }


	point a(A.first, A.second), b(B.first, B.second), c(C.first, C.second);
	vec ab(a, b), bc(b, c), ca(c, a);
	point all_points[6];
	all_points[0] = trans(a, scale(minmax[0][0], ab));
	all_points[1] = trans(b, scale(minmax[1][0], bc));
	all_points[2] = trans(c, scale(minmax[2][0], ca));
	all_points[3] = trans(a, scale(minmax[0][1], ab));
	all_points[4] = trans(b, scale(minmax[1][1], bc));
	all_points[5] = trans(c, scale(minmax[2][1], ca));
	
	double top = 0;
	for (int i = 0; i < 6; ++i)
	{
		for (int j = i+1; j < 6; ++j)
		{
			for (int k = j+1; k < 6; ++k)
			{
				top = max(area(all_points[i], all_points[j], all_points[k]), top);
			}
		}
	}

	cout << fixed << setprecision(8) << top << endl;
	

	return 0;
}