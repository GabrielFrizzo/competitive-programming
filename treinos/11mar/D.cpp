#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

void solve(int N) {
	vi v;
	vi suf(N), pref(N);
	vector<string> names;
	for (int i =0; i < N; ++i) {
		string inp;
		cin >> inp;
		int total = 0;
		for (char c : inp)
			total += c;
		v.push_back(total);
		names.push_back(inp);
	}

	int total = 0;
	for (int i = N-1; i >= 0; --i) {
		total += v[i];
		suf[i] = total;
	}

	total = 0;
	for (int i = 0; i < N; ++i) {
		total += v[i];
		pref[i] = total;
	}


	int s2 = 0, s1 = 0;
	for (int i = 0; i < N; ++i) {
		s2 += (i+1)*v[i];
	}

	// cout << s1 << " " << s2 << endl;
	for (int i = 0; i < N; ++i) {
		s1 += pref[i];
		s2 -= suf[i];
		// cout << s1 << " " << s2 << endl;
		if (s1 == s2) {
			cout << names[i] << endl;
			return;
		}
	}

	cout << "Impossibilidade de empate." << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    while (cin >> N, N) {
    	solve(N);
    }
	return 0;
}