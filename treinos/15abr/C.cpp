#include <bits/stdc++.h>
using namespace std;

#define MAX 112345
#define EPS 0.0000001

int N;
double A, high, startarea;
double h[MAX], currh[MAX];

double area() {
	double total = 0;
	for (int i = 0; i < N; ++i)
		total += currh[i];

	return total;
}

double bsearch() {
	double l = 0, r = high, mid = 0;

	while (r - l > EPS) {
		mid = (l+r)/2;

		for (int i = 0; i < N; ++i)
			currh[i] = min(mid, h[i]);

		double currarea = startarea - area();

		// cout << "D" << mid << " " << A << " " << currarea << endl;

		if (currarea > A)
			l = mid;
		else if (currarea < A)
			r = mid;
		else
			return mid;
	}

	return mid;
}

void solve() {
	startarea = area();
	// cout << "inicio" << startarea << endl;
	if (startarea == A) {
		cout << ":D" << endl;
		return;
	}
	if (startarea < A) {
		cout << "-.-" << endl;
		return;
	}

	double res = bsearch();

	cout << fixed << setprecision(4) << res << endl;
}


int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double inp;

    while (cin >> N >> A, N!=0) {
    	high = -1;
    	for (int i = 0; i < N; ++i){
    		cin >> inp;
    		currh[i] = h[i] = inp;
    		if (h[i] > high) high = h[i];
    	}

    	solve();
    }
	return 0;
}

// binary search