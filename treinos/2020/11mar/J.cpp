#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

double dist(int bx, int by, int x, int y) {
	double dx = bx-x, dy = by-y;
	return dx*dx+dy*dy;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int TC;
    cin >> TC;
    while(TC--) {
    	int N;
    	cin >> N;
    	int bx, by, x, y;
    	cin >> bx >> by;
    	double best = 1e9+5;
    	int besti;
    	for (int i = 1; i <= N; ++i) {
    		cin >> x >> y;
    		double d = dist(bx, by, x, y);
    		if (d < best) {
    			best = d;
    			besti = i;
    		}
    	}

    	cout << besti << endl;
    }
	return 0;
}