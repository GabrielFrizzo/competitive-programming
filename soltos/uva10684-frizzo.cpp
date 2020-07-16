// HaHa3.5 - Max 1D Range Sum

#include <bits/stdc++.h>
using namespace std;

void solve(int N) {
	int inp, res = 0, sum = 0;

	while (N--) {
		cin >> inp;
		sum = max(sum+inp, 0);
		res = max(res, sum);
	}

	if (res)
		cout << "The maximum winning streak is " << res  << "." << endl;
	else
		cout << "Losing streak." << endl;
}


int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
	cin >> N;

    while(N) {	
    	solve(N);
    	cin >> N;
    }
	return 0;
}
