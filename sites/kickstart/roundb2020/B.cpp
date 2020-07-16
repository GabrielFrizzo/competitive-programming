#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

void solve() {
	int N, D;
	scanf("%d %d", &N, &D);
	vi v(N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &v[i]);
	}

	for (int i = N-1; i >=0; --i) {
		D -= (D%v[i]);
	}

	printf("%d\n", D);
}

int main(int argc, char const *argv[])
{
    int TC;
    scanf("%d", &TC);
    for (int i = 1; i <= TC; ++i) {
    	printf("Case #%d: ", i);
    	solve();
    }

	return 0;
}