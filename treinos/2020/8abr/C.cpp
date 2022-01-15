#include <bits/stdc++.h>
using namespace std;

void g1() {
	cout << "Jogador 1 ganha!" << endl;
	exit(0);
}

void g2() {
	cout << "Jogador 2 ganha!" << endl;
	exit(0);
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int p, j1, j2, r, a;

    cin >> p >> j1 >> j2 >> r >> a;

    if (r) {
    	if (a)
    		g2();
    	else
    		g1();
    }
    if (a)
    	g1();

	if ((j1 + j2) % 2) {
		p ? g2() : g1();
	}

	p ? g1() : g2();

	return 0;
}