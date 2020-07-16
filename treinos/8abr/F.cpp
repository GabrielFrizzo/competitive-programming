#include <bits/stdc++.h>
using namespace std;

bool isperm(vector<int> v) {
	sort(v.begin(), v.end());

	for (int i = 1; i <= v.size(); i++) {
		if (v[i-1] != i)
			return false;
	}
	return true;
}

void solve() {
	int n, inp;
	vector<int> a;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> inp;
		a.push_back(inp);
	}

	int _max = *max_element(a.begin(), a.end());

	bool perm1, perm2;

	perm1 = isperm(vector<int>(a.begin(), a.begin()+_max)) && isperm(vector<int>(a.begin()+_max, a.end()));
	perm2 = isperm(vector<int>(a.begin(), a.begin()+(n-_max))) && isperm(vector<int>(a.begin()+(n-_max), a.end())) && _max != n-_max;
	cout << perm1+perm2 << endl;
	if (perm1)
		cout << _max << " " << n-_max << endl;
	if (perm2)
		cout << n-_max << " " << _max << endl;
}



int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) solve();
	return 0;
}