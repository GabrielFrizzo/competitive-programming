#include <bits/stdc++.h>
using namespace std;

#define MxN 1123
#define MxS 11234

typedef struct elephant{
	int i;
	int w;
	int s;

	elephant() {}
	elephant(int _i, int _w, int _s) : i(_i), w(_w), s(_s) {}
} elephant;

elephant elep[MxN];
int memo[MxN];
int N;
int child[MxN];
int number = 0;


int lis(int i) {
	if (memo[i] != -1) return memo[i];
	if (i == N) return 0;
	int best = 0;
	for (int j = i+1; j < N; ++j) {
		if (elep[i].s > elep[j].s && elep[i].w < elep[j].w) {
			int x = lis(j);

			if (x > best) {
				best = x;
				child[i] = j;
			}
		}
	}

	return memo[i] = best+1;
}

int cmp(const elephant& e1, const elephant& e2) {
	return e1.w < e2.w;
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

 	int w, s;
    N = 0;

    while (cin >> w >> s) {
    	elep[N] = elephant(N+1, w,s);
    	N++;
    }

    sort(elep, elep+N, cmp);
    

    memset(memo, -1, sizeof(memo));
    memset(child, -1, sizeof(child));
    int best = 0, best_start = 0;

    for (int i = 0; i < N; ++i) {
    	int aux = lis(i);
    	if (aux > best) {
    		best = aux;
    		best_start = i;
    	}
    }
    cout << best << endl;

    while (best_start != -1) {
		cout << elep[best_start].i << endl;
		best_start = child[best_start];
    }
	return 0;
}