#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int MxN = 1123456;

ll bit[2][MxN];
ll X, Y;
ll H, V;
ll total;

void setbit(ll i , ll v, int hor){
	ll l = hor ? H : V;
  while(i<=l){
    bit[hor][i]+=v;
    i+=i&-i;
  }
}

ll getbit (int i, int hor){
  ll ret = 0;
  while(i>0){
    ret+=bit[hor][i];
    i-=i&-i;
  }
  return ret;
}


void hor() {
	vector<pii> v;
	vi rank;
	for (int i = 0; i < H; ++i) {
		int x, y;
		cin >> x >> y;
		v.push_back({y, x});
	}

	sort(v.begin(), v.end());

	for (int i = 1; i <= H; ++i) {
		v[i-1].first = v[i-1].second;
		v[i-1].second = i;
	}


	sort(v.rbegin(), v.rend());
	// for (pii p : v) {
		// cout << p.first << ' ' << p.second << endl;
	// }

	for (int i = 1; i <= H; ++i) {
		int asd = v[i-1].second;
		ll res;
		res = getbit(asd, true);
		total += res;
		setbit(asd, 1, true);
		// cout << getbit(asd, true) << endl;
	}
}

void ver() {
	vector<pii> v;
	for (int i = 0; i < V; ++i) {
		int x, y;
		cin >> x >> y;
		v.push_back({y, x});
	}
	// for (pii p : v) {
	// 	cout << p.first << ' ' << p.second << endl;
	// }

	sort(v.begin(), v.end());
	for (int i = 1; i <= V; ++i) {
		v[i-1].first = v[i-1].second;
		v[i-1].second = i;
	}

	// for (pii p : v) {
	// 	cout << p.first << ' ' << p.second << endl;
	// }

	sort(v.rbegin(), v.rend());

	// for (pii p : v) {
	// 	cout << p.first << ' ' << p.second << endl;
	// }

	for (int i = 1; i <= V; ++i) {
		int asd = v[i-1].second;
		ll res;
		res = getbit(asd, false);
		total += res;
		setbit(asd, 1, false);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> X >> Y;

	cin >> H >> V;

	total = H*V + 1 + H + V;

	// cout << total << endl;
	hor();
	// cout << total << endl;
	ver();

	cout << total << endl;
		
	return 0;
}
