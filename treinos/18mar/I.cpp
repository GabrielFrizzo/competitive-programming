#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	int M, m;
	if (a > b){
		M = a;
		m = b;
	} else {
		M = b;
		m = a;
	}

	if (m == 0) return M;

	return gcd(M%m, m);
}

int lcm(int a, int b) {
	return a*b/gcd(a,b);
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b, res;

    cin >> n >> a >> b;

    while (n!=0) {
    	res = n/a + n/b - n/lcm(a,b);

    	cout << res << endl;
		cin >> n >> a >> b;    	
    }
	return 0;
}