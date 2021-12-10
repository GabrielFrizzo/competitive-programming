#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;
using pii = pair<ll,ll>;

struct point {
    ll x,y;
    point() {}
    point(ll _x, ll _y) : x(_x),y(_y) {}
};

struct vec {
    ll x,y;
    vec () {}
    vec (ll _x,ll _y) : x(_x), y(_y) {}
    vec (point a, point b) : x(b.x - a.x), y(b.y - a.y) {}
};

struct seg {
    point a,b;
    seg() {}
    seg(point _a,point _b):a(_a),b(_b) {}
};
ll dot(vec u, vec v)  {return u.x*v.x + u.y*v.y; }
ll dot(seg u, seg v)  {return dot(vec(u.a, u.b), vec(v.a, v.b)); }
ll cross (vec u , vec v ){    return u.x*v.y - u.y*v.x; }
ll cross(seg u, seg v) { return cross(vec(u.a, u.b), vec(v.a, v.b)); }

double angle(point a, point b, point c){
    vec u(b, a), v(b ,c);
    return acos(dot(u, v)/ sqrt((double) dot(u,u) * dot(v,v)));
}


const ll MxN = 112;
const ll MOD = 1e9 + 7;

point points[MxN];
vector<pair<double, ll>> across, bcross;

ll memo[MxN][MxN];
ll N, A, B;

ll dp(ll i, ll j) {
	if (i >= N || j >= N) return 0;
	if (memo[i][j] != -1) return memo[i][j];

	ll fb = -1, esquerda = -1;
	for (ll jj = j; jj < N; ++jj)
		if (bcross[jj].second == across[i].second)
			fb = jj;
	if (fb != -1)
		 esquerda = dp(i+1, fb+1);

	ll fa = -1, direita = -1;
	for (ll ii = i; ii < N; ++ii)
		if (across[ii].second == bcross[j].second)
			fa = ii;
	if (fa != -1)
		 direita = dp(fa+1, j+1);

	return memo[i][j] = max(max(esquerda, direita) + 1, dp(i+1, j+1));
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	cin >> N >> A >> B;
	point a = point(A, 0), b = point(B, 0);
	for (ll i = 0; i < N; ++i)
	{
		ll x, y;
		cin >> x >> y;
		points[i] = point(x, y);
	}


	for (ll i = 0; i < N; ++i)
	{
		across.push_back({angle(b, a, points[i]), i});
		bcross.push_back({angle(a, b, points[i]), i});
	}

	sort(across.begin(), across.end());
	sort(bcross.begin(), bcross.end());

	// for (pair<double, ll> aa : across)
	// 	cout << aa.first << ' ' << aa.second << endl;
	// cout << endl;
	// for (pair<double, ll> bb : bcross)
	// 	cout << bb.first << ' ' << bb.second << endl;
	memset(memo, -1, sizeof(memo));
	cout << dp(0, 0) << endl;

	// for (int i = 0; i < N; ++i) {
	// 	for (int j = 0; j < N; ++j) {
	// 		cout << memo[i][j] << '\t';
	// 	}
	// 	cout << endl;
	// }
	return 0;
}