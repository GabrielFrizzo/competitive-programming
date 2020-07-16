#include <bits/stdc++.h>
using namespace std;

#define SPACE 0
#define MEAL 1
#define GHOST 2


int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char inp;
    int n;

    cin >> n;

    int mat[112][112];

    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		cin >> inp;
    		int col = i % 2 ? n - 1 - j : j;
    		
    		mat[i][col] = inp == '.' ? SPACE : inp == 'o' ? MEAL : GHOST;
    	}
    }

    int best = 0, curr = 0;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		if (mat[i][j] == MEAL) {
    			curr++;
    		} else if (mat[i][j] == GHOST) {
    			best = max(best, curr);
    			curr = 0;
    		}
    	}
    }
    best = max(best, curr);
    cout << best << endl;
	return 0;
}