#include <bits/stdc++.h>
using namespace std;

#define MxN 1123

int p[MxN], r[MxN];

struct point {
	double x, y;
	point() {}
	point(double _x, double _y) : x(_x), y(_y) {}
};

struct seg {
	point a, b;
	seg() {};
	seg(point _a, point _b) : a(_a), b(_b) {}
};

struct vec {
	double x, y;
	vec() {};
	vec(double _x, double _y) : x(_x), y(_y) {}
	vec(point a, point b) : x(b.x-a.x), y(b.y-a.y) {}
};

int _find(int i) {
	if (p[i] == i) return i;
	return p[i] = _find(p[i]);
}

void _union(int i, int j) {
	i = _find(i); j = _find(j);
	if (r[i] > r[j]) p[j] = i;
	else {
		p[i] = j;
		r[j] = max(r[j], r[i]+1);
	}
}


int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    seg lines[MxN];

    for (int i = 0; i < N; ++i) {
    	int xa, ya, xb, yb;
    	cin >> xa >> ya >> xb >> yb;
    	lines[i] = seg(point(xa, xb), point(ya, yb));
    }

    cout << ceil(kruskal());
	return 0;
}