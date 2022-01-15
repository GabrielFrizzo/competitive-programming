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
int memo[MxN][MxS];
int N;
int chosen[MxN][MxS];

#define INF MxS-1

int dp(int i, int last_s, int last_w) {
	if (i >= N) return 0;
	if (memo[i][last_s] != -1) return memo[i][last_s];

	if (elep[i].s >= last_s || elep[i].w == last_w) {
		chosen[i][last_s] = 0;
		return memo[i][last_s] = dp(i+1, last_s, last_w);
	}
	int ch1 = dp(i+1, last_s, last_w);
	int ch2 = dp(i+1, elep[i].s, elep[i].w)+1;
	chosen[i][last_s] = ch2 > ch1;
	if (ch2 > ch1){
		return memo[i][last_s] = ch2;
	}
	else {
		return memo[i][last_s] = ch1;
	}
}

bool cmp(const elephant& e1, const elephant& e2) {
	if (e1.w < e2.w) return true;
	if (e1.w > e2.w) return false;
	return e1.s < e2.s;
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
    // for (int i = 0; i < N; ++i)
    // 	cout << elep[i].i << " " << elep[i].w << " " << elep[i].s << endl;
    // cout << endl;

    memset(memo, -1, sizeof(memo));
    memset(chosen, 0, sizeof(chosen));

    int aux = dp(0, INF, -1);
    cout << aux << endl;

    int curr_s = INF;
    for (int i = 0; i < N; ++i) {
    	if (chosen[i][curr_s]) {
    		// cout << elep[i].i << " " << elep[i].w << " " << elep[i].s << endl;
    		cout << elep[i].i << endl;
    		curr_s = elep[i].s;
    	}
    }

	return 0;
}
