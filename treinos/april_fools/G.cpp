#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n[11];
    double a, b, res;

    for (int i = 0; i < 11; i++) {
    	cin >> n[i];
    }

	for (int i = 10; i >= 0; i--) {
		a = sqrt(abs(n[i]));
		b = (n[i]*n[i]*n[i])*5;

		res = a+b;

		if (res <= 400) {
			printf("f(%d) = %.2f\n", n[i], res);
		} else {
			printf("f(%d) = MAGNA NIMIS!\n", n[i]);
		}
    } 
	return 0;
}