#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, inp, prev, res = 0;
    cin >> N;
    prev = -1;
    while (N--) {
    	cin >> inp;
    	if (inp > prev) {
    		res++;
    	}
    	prev = inp;
    }

    cout << res << endl;
	return 0;
}