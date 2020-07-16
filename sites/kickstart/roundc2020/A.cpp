#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

void solve() {
    int N, K;
    cin >> N >> K;
    vi v(N);
    for (int i =0; i < N; ++i) {
    	cin >> v[i];
    }
    reverse(v.begin(), v.end());

    int last = -1;
    int count = 0;
    for (int i : v) {
    	if (last != -1) {
    		if (++last != i) {
    			if (i == 1) {
    				last = 1;
    			} else {
    				last = -1;
    			}
    		} else if (last == K) {
    			count++;
    			last = -1;
    		}

    	} else if (i == 1) {
    		last = 1;
    	}

    }
    cout << count << endl;
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