#include <bits/stdc++.h>
#define JONES 0
#define OBJ 1
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const double EPS = 1e-9;
const int INF = 1e9 + 5;

struct point {
	double x, y;
	point() {}
	point(double _x, double _y) : x(_x), y(_y) {}
};

struct seg {
	point a, b;
	seg() {}
	seg(point _a, point _b) : a(_a), b(_b) {}
};

struct vec {
	double x, y;
	vec() {}
	vec(double _x, double _y) : x(_x), y(_y) {}
	vec(point a, point b) : x(b.x-a.x), y(b.y-a.y) {}
};

double dot(vec u, vec v) { return u.x * v.x + u.y * v.y; }

double cross(vec u, vec v) { return u.x * v.y - u.y * v.x; }

vec scale(double l, vec u) { return vec(l * u.x, l * u.y); }

point trans(point a, vec u) { return point(a.x + u.x, a.y + u.y); }

double dpp(point a, point b) {
	vec ab(a,b);
	return sqrt(dot(ab, ab));
}

double dpseg(point p, seg s) {
	vec ab(s.a, s.b), ap(s.a, p);
	double norm_sq = dot(ab, ab);
	if (norm_sq < EPS) return dpp(p, s.a);
	double l = dot(ab, ap) / dot(ab, ab);
	if (l < 0.) return dpp(p, s.a);
	if (l > 1.) return dpp(p, s.b);
	point c = trans(s.a, scale(l, ab));
	return dpp(c, p);
}

int collinear(seg s, seg r) {
	return abs(cross(vec(s.a, s.b), vec(s.a, r.a))) < EPS &&
		   abs(cross(vec(s.a, s.b), vec(s.a, r.b))) < EPS;
}

int intersect(seg s, seg r) {
	double d1 = cross(vec(s.a, s.b), vec(s.a, r.a));
	double d2 = cross(vec(s.a, s.b), vec(s.a, r.b));
	double d3 = cross(vec(r.a, r.b), vec(r.a, s.a));
	double d4 = cross(vec(r.a, r.b), vec(r.a, s.b));
	return d1*d2 < EPS && d3*d4 < EPS;
}

double dseg(seg s, seg r) {
	if (!collinear(s, r) && intersect(s, r)) return 0.;
	return  min(dpseg(s.a, r),
		     min(dpseg(s.b, r),
		      min(dpseg(r.a, s), dpseg(r.b, s)
		      )
		     )
		    );
}

int N;

vector<seg> walls;

void addwall(int x, int y, int l) {
	point p1 = point(x, y);
	point p2 = point(x, y);
	if (l > 0) p2.x += l;
	else	   p2.y -= l;
	walls.push_back(seg(p1, p2));
}

vi taken;
using pdi = pair<double, int>;

double prim() {
	priority_queue<pdi, vector<pdi>, greater<pdi>> pq;
	taken.assign(N, 0);
	pq.push({0, JONES});
	double res = 0;
	while (!pq.empty()) {
		int u; double cost;
		tie(cost, u) = pq.top(); pq.pop();
		if (taken[u]) continue;
		taken[u] = true;
		res = max(res, cost);
		if (u == OBJ) return res;
		for (int v = 0; v < N; ++v) {
			double vcost = dseg(walls[u], walls[v]);
			// cout << vcost << endl;
			if (!taken[v])
				pq.push({vcost, v});
		}
	}

	return 0;
}

void solve() {
	int x, y, l;
	walls.clear();

	for (int i = 0; i < N; ++i) {
		cin >> x >> y >> l;
		addwall(x, y, l);
	}

	cout << fixed << setprecision(2) << prim() << endl;
}

int main(int argc, char const *argv[])
{
	while (cin >> N, N) {
		solve();
	}

	return 0;
}