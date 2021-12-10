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
const int MxN = 51;

int m[MxN][MxN];
int existe[MxN][MxN][21];
unordered_map<int, int> cont[21];

int ni[] = {-1, 0, 1, 1};
int nj[] = {1, 1, 1, 0};

int L, C;


void find(int i, int j, int asd) {		
	if (cont[asd][m[i][j]] == 0) return;
	
	int tam = 0;
	for (auto cc : cont[asd]) {
		tam += cc.second;
	}
	
	for (int dir = 0; dir < 4; ++dir) {
		unordered_map<int, int> mapa = cont[asd];
		mapa[m[i][j]]--;
		// busca nessa direcao
		bool flag = true;
		for (int pos = 1; pos < tam; ++pos) {
			int ii = i + ni[dir]*pos;
			int jj = j + nj[dir]*pos;
			if (ii >= L || jj >= C || ii < 0 || jj < 0) {flag=false;break;}
			if (mapa[m[ii][jj]]) {
				mapa[m[ii][jj]]--;
			} else {
				flag = false;
				break;
			}
		}

		if (flag) {
			for (int pos = 0; pos < tam; ++pos) {
				int ii = i + ni[dir]*pos;
				int jj = j + nj[dir]*pos;
				existe[ii][jj][asd] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> L >> C;

	for (int i = 0; i < L; ++i) {
		for (int j = 0; j < C; ++j) {
			char inp;
			cin >> inp;
			m[i][j] = inp -'A';
		}
	}

	int N;
	cin >> N;


	for (int i = 0; i < N; ++i) {
		string inp;
		cin >> inp;

		for (char c : inp) {
			cont[i][c-'A']++;
		}
	}

	for (int asd = 0; asd < N; ++asd) {
		for (int i = 0; i < L; ++i) {
			for (int j = 0; j < C; ++j) {
				find(i, j, asd);
			}
		}
	}

	//DEBUG
	// for (int i = 0; i < L; ++i) {
	// 	for (int j = 0; j < C; ++j) {
	// 		cout << existe[i][j][1] << ' ';
	// 	}
	// 	cout << endl;
	// }
	//DEBUG

	int res = 0;
	for (int i = 0; i < L; ++i) {
		for (int j = 0; j < C; ++j) {
			int tt = 0;
			for (int asd = 0; asd < N; ++asd) {
				tt += existe[i][j][asd];
			}
			res += tt > 1;
		}
	}


	cout << res << endl;
}