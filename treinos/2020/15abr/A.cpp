#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int P, N, inp, prev;
    cin >> P >> N;

    cin >> prev;
    N--;
    while (N--) {
    	cin >> inp;
    	if (abs(inp - prev) > P) {
    		cout << "GAME OVER" << endl;
    		return 0; 
    	}
    	prev = inp;
    }

    cout << "YOU WIN" << endl;
	return 0;
}