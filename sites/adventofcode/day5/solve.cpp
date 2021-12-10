#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int MxN = 1123;
const int MOD = 1e9 + 7;

struct point {
	int x, y;
	point(int _x, int _y) : x(_x), y(_y) {};
};

struct vec {
	int x, y;
	vec(point p1, point p2) : x(p2.x-p1.x), y(p2.y-p1.y) {};
	vec(int _x, int _y) : x(_x), y(_y) {};

	vec operator/(const double n) {
		return vec(x/(int)n, y/(int)n);
	}

	double size() {
		return sqrt(x*x + y*y);
	}
};

struct line {
	point p1, p2;
	line(point _p1, point _p2) : p1(_p1), p2(_p2) {};

	double size() {
		return vec(p1, p2).size();
	}

	vec dir() {
		return vec(p1, p2)/size();
	}

	bool isHoriz() {
		return p1.y == p2.y;
	}

	bool isVer() {
		return p1.x == p2.x;
	}
};

vector<line> lines;
int m[MxN][MxN];

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for(int i = 0; i < N; ++i) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 != x2 && y1 != y2) continue;
		lines.push_back(line(point(x1, y1), point(x2, y2)));
	}

	for (line l : lines) {
		if (l.isHoriz()) {
			int dir = l.p1.x < l.p2.x ? 1 : -1;
			for(int x = l.p1.x, y = l.p1.y; (x <= l.p2.x && dir == 1) || (x >= l.p2.x && dir == -1); x += dir) {
				m[y][x]++;
			}
		}
		if (l.isVer()){
			int dir = l.p1.y < l.p2.y ? 1 : -1;
			for(int x = l.p1.x, y = l.p1.y; (y <= l.p2.y && dir == 1) || (y >= l.p2.y && dir == -1); y += dir) {
				m[y][x]++;
			}
		}
	}

	int total = 0;
	for(int i = 0; i < MxN; ++i) {
		for(int j = 0; j < MxN; ++j) {
			total += m[i][j] > 1;
		}
	}

	cout << total << endl;

	return 0;
}