#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int MxN = 11234;

int v[MxN];

void solve() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
    	cin >> v[i];
    }	

    int up = 0;
    int prev = v[0];
    int res = 0;
    for (int i = 1; i < N; ++i) {
    	// cout << i << ' ' << up << endl;
    	if (up > 0) {
    		if (v[i] > prev) {
    			if (++up > 4) {
    				res++;
    				// cout << i << endl;
    				up = 0;
    			}
    		} else if (v[i] < prev) {
    			up = -2;
    		}
    	} else if (up < 0) {
    		if (v[i] < prev) {
    			if (--up < -4) {
    				res++;
    				// cout << i << endl;
    				up = 0;
    			}
    		} else if (v[i] > prev) {
    			up = 2;
    		}
    	} else {
    		up = v[i] > prev ? 2 : v[i] < prev ? -2 : 0;
    	}
    	prev = v[i];
    }

    cout << res << endl;
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