#include <bits/stdc++.h>
using namespace std;

void solve() {
	int mat[9][9];
	char inp;
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j) {
			cin >> inp;
			mat[i][j] = inp-'0';
		}

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			mat[i*3+j][j*3+i] = (mat[i*3+j][j*3+i]%9) + 1;

	for (int i = 0; i < 9; ++i){
		for (int j = 0; j < 9; ++j)
			cout << mat[i][j];
		cout << endl;
	}
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int TC;
    cin >> TC;
    while (TC--)
    	solve();
	return 0;
}