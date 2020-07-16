#include <bits/stdc++.h>
using namespace std;

#define MOD 1000

void iden(int a[2][2]) {
 	a[0][0] = a[1][1] = 1;
  	a[0][1] = a[1][0] = 0;
}

void multmat(int a[2][2], int b[2][2]) {
	int c[2][2];
  	int i, j;
  	for (i = 0; i < 2; i++)
    	for (j = 0; j < 2; j++)
      		c[i][j] = (a[i][0] * b[0][j] + a[i][1] * b[1][j]) % MOD;

     memcpy(b, c, sizeof(c));
}


void expbin(int a[2][2], string n, int b[2][2]) {
	iden(b);
	for (int i = 0; i < n.length()-1; ++i) {
		if (n[i] == '1') 
	 		multmat(a, b);
	 	multmat(b, b);
	}
	if (n.back() == '1') 
	 	multmat(a, b);
}

void solve() {
	string inp;
	cin >> inp;
	// reverse(inp.begin(), inp.end());
	int a[2][2] = {{0, 1}, {1, 1}}, b[2][2];
	expbin(a, inp, b);
	cout << setfill('0') << setw(3) << b[1][0]%MOD << endl;
}


int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    while (N--) {
    	solve();
    }
	return 0;
}

// multiplicar a matriz pelo primeiro digito do binario

// 0 1
// 1 1

// 1 1		1 2
// 1 2		2 3

// 2 3
// 3 5

