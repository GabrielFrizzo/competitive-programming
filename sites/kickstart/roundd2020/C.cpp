#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int MxN = 512345;

int p[MxN];
bool vis[MxN];

int up(int curr, int n) {
	while (n--) {
		curr = p[curr];
	}
	return curr;
}

void solve() {
    int N, A, B;
    cin >> N >> A >> B;
    for (int i = 2; i <= N; ++i) {
    	cin >> p[i];
    }
    p[1] = p[0] = 0;

    ll total = 0;
    for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
    		for (int ii = 1; ii <= N; ++ii) vis[ii] = false;
    		int curr = i;
    		do {
    			total++;
    			vis[curr] = true;
    			curr = up(curr, A);
    		} while (curr >= 1);
    		curr = j;
    		do {
    			total += !vis[curr];
    			curr = up(curr, B);
    		} while (curr >= 1);
    	}
    }

    cout << fixed << setprecision(7) << ((double)total)/(N*N*1.) << endl;
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