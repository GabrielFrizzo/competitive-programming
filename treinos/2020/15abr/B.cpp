#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    bool flag = false;
    int N, M, A, B;
    while (cin >> N >> M) {
    	if (flag)
    		cout << endl;
    	flag = true;
    	A = min(N,M);
    	B = max(N,M);
    	for (int i = A+1; i <= B+1; ++i)
    		cout << i << endl;

    }
	return 0;
}