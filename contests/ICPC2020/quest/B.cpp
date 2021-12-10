#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "


using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int MxN = 11;

int m[MxN][MxN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	bool flag = true;


	for (int asd = 0; asd < N && flag; ++asd) {
		int D, L, R, C;
		cin >> D >> L >> R >> C;

		if (!D) {
			if (C+L-1 >= 11) {flag = false;break;};
			for (int i = C; i < C + L; ++i) {
				m[R][i]++;
			}
		} else {
		// cout << "asdas" << endl;
				// cout << R << 'a' << R+L << endl;
			if (R+L-1 >= 11) {flag = false;break;};
			for (int i = R; i < R + L; ++i) {
				m[i][C]++;
			}
		}
	}

	for (int i = 1; i < 11 && flag; ++i) {
		for (int j = 1; j < 11; ++j) {
			if (m[i][j] >= 2) {
				flag = false;
				break;
			}
		}		
	}

	// for (int i = 1; i < 11; ++i) {
	// 	for (int j = 1; j < 11; ++j) {
	// 		cout << m[i][j] << ' ';
	// 	}		
	// 	cout << endl;
	// }	

	if (flag) {
		cout << "Y" << endl;
	} else {
		cout << "N" << endl;
	}
}