#include <bits/stdc++.h>
using namespace std;



void test_case(int N, int M) {
	int res;
	int inp;
	bool colhas0[112], colhas1[112], t1, t2, t3, t4;
	int rowsum;
	t1 = t4 = true;
	t2 = t3 = false;

	for (int i = 0; i < M; i++) {
		colhas0[i] = colhas1[i] = 0;
	}

	for (int i = 0; i < N; i++) {
		rowsum = 0;
		for (int j = 0; j < M; j++) {
			cin >> inp;
			if(inp) {
				rowsum++;
				colhas1[j] = true;
			} else {
				colhas0[j] = true;
			}
		}		
		if (rowsum == M) {
			t1 = false;
		} else if (rowsum == 0) {
			t4 = false;
		}
	}


	int col0count = 0, col1count = 0;
	for (int i = 0; i < M; i++) {
		col0count += colhas0[i];
		col1count += colhas1[i];
	}

	if (col0count == M) t3 = true;
	if (col1count == M) t2 = true;

	res = t1 + t2 + t3 + t4;

	cout << res << endl;
}



int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
	cin >> N >> M;


    while (N != 0) {
    	test_case(N, M);

    	cin >> N >> M;
    }
	return 0;
}