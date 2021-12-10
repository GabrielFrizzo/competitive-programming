#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	double e1, e2, at, d;
	while (cin >> e1 >> e2 >> at >> d, e1) {
		e1 = ceil(e1/d);
		e2 = ceil(e2/d);
		
		if (at == 3) {
			cout << fixed << setprecision(1) << e1/(e1+e2)*100 << endl;
		} else {
			double x = 1-pow((6-at)/at, e1);
			double y = 1-pow((6-at)/at, e1+e2);

			cout << fixed << setprecision(1) << x/y*100 << endl;
		}
	}


	return 0;
}

