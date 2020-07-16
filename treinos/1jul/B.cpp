#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

int Z, L, I, M;

const int MxN = 11234;
int vis[MxN];

void solve() {
	memset(vis, 0, sizeof vis);
	int cnt = 0;
	vis[L] = cnt++;
	while (true) {
		L = (Z*L+I)%M;
		if (vis[L]) {
			cout << cnt - vis[L] << endl;
			return;
		};
		vis[L] = cnt++;
    }
}
int main(int argc, char const *argv[])
{
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int TC = 1;
    while(cin >> Z >> I >> M >> L, Z || M) {
    	cout << "Case " << TC++ << ": ";
    	solve();
    }

    
	return 0;
}