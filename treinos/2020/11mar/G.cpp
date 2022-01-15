#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int TC;
    cin >> TC;
    while (TC--) {
    	int N;
    	cin >> N;
    	vector<pii> v;
    	for (int i = 0; i < N; ++i) {
    		int inp;
    		cin >> inp;
    		v.push_back({inp, i});
    	}

    	sort(v.begin(), v.end());
    	reverse(v.begin(), v.end());

    	int total = 0;
    	for (int i = 0; i < N; ++i) {
    		total += v[i].second == i;
    	}

    	cout << total << endl;
    }
	return 0;
}