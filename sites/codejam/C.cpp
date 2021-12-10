#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

vi v;
int N, C;

void rev(int low, int high) {
	int mid = (high + low) / 2;
	// cout <<low << ' ' << mid <<' ' << high << endl;
	for (int i = 0; i <= mid - low; ++i) {
		swap(v[low + i], v[high-i]);
	}
}

int trial(vi vec) {
	v = vec;
	int count = 0;
	// for (int j = 0; j < N; ++j) {
	// 	cout << v[j] << ' ';
	// }
	// cout << endl;
	for (int i = 0; i < N-1; ++i) {
		for (int j = i; j < N; ++j) {
			if (v[j] == i) {
				count += j-i+1;
				rev(i, j);
				break;
			}
		}
	}

	return count;
}

void solve() {
	cin >> N >> C;
	vi vec(N);
	
	for (int i = 0; i < N; ++i) {
		vec[i] = i;
	}

	do {
		if (trial(vec) == C) {
			for (int i = 0; i < N; ++i) {
				cout << vec[i]+1 << ' ';
			}
			cout << endl;
			return;
		}
	} while (next_permutation(vec.begin(), vec.end()));
	cout << "IMPOSSIBLE\n";
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int TC;
    cin >> TC;
    for (int i = 1; i <= TC; ++i) {
    	cout << "Case #" << i << ": ";
    	solve();
    }
	return 0;
}