#include <bits/stdc++.h>
using namespace std;



void test_case(int N, int M) {
	char mat[100][100];


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mat[i][j];
		}
	}

	int a, b;
	cin >> a >> b;

	int NT = a/N;
	int MT = b/M;


	for (int i = 0; i < N; i++) {
		for (int it = 0; it < NT; it++) {
			for (int j = 0; j < M; j++) {
				for (int jt = 0; jt < MT; jt++) {
					cout << mat[i][j];
				}
			}
			cout << endl;
		}
	}	


	cout << endl;
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