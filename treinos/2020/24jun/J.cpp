#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int MxN = 30;

char m[MxN][MxN];
int hor[MxN], ver[MxN];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
    	for (int j = 0; j < N; ++j) {
    		cin >> m[i][j];
    		hor[i] += m[i][j] == 'W';
    		ver[j] += m[i][j] == 'W';
    	}
    }

    for (int i = 0; i < N; ++i) {
    	if (hor[i] != N/2 || ver[i] != N/2) {
    		cout << 0 << endl;
    		return 0;
    	}
    }

    char last = ' ';
    int curr = 0;
    for (int i = 0; i < N; ++i) {
    	for (int j = 0; j < N; ++j) {
    		if (m[i][j] == last) {
    			if (++curr >= 3) {
    				cout << 0 << endl;
    				return 0;
    			}
    		} else {
    			curr = 1;
    		}
    		last = m[i][j];
    	}
    	curr = 0;
    	last = ' ';
    }

    last = ' ';
    curr = 0;
    for (int i = 0; i < N; ++i) {
    	for (int j = 0; j < N; ++j) {
    		if (m[j][i] == last) {
    			if (++curr >= 3) {
    				cout << 0 << endl;
    				return 0;
    			}
    		} else {
    			curr = 1;
    		}
    		last = m[j][i];
    	}
    	curr = 0;
    	last = ' ';
    }

    cout << 1 << endl;

	return 0;
}