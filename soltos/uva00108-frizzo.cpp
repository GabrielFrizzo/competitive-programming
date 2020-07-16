// HaHa3.5 - Max 2D Range Sum

#include <bits/stdc++.h>
using namespace std;
#define MAX 112

int N, inp[MAX][MAX];

void solve() {
	for (int i = 0; i < N; i++) {
    	for (int j = 0; j < N; j++) {
    		if (i > 0) inp[i][j] += inp[i-1][j];
    		if (j > 0) inp[i][j] += inp[i][j-1];
    		if (i > 0 && j > 0) inp[i][j] -= inp[i-1][j-1];
    	}
    }

    int res = -200*MAX*MAX, sum;

    for (int i = 0; i < N; i++) {
    	for (int j = 0; j < N; j++) {
    		for (int k = i; k < N; k++) {
    			for (int l = j; l < N; l++) {
    				sum = inp[k][l];
    				if (i) sum -= inp[i-1][l];
    				if (j) sum -= inp[k][j-1];
    				if (i && j) sum += inp[i-1][j-1];
    				res = max(sum, res);
    			}
    		}
    	}
    }

    cout << res << endl;

}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
    	for (int j = 0; j < N; j++) {
    		cin >> inp[i][j];
    	}
    }

    solve();

	return 0;
}

//  4
//  0	-2	-7	 0 
//  9	 2  -6   2
// -4   1  -4   1
// -1	 8   0  -2
