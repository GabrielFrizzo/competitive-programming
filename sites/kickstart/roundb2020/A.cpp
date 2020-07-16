#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

void solve() {
	int N, inp;
	scanf("%d", &N);
	vi h(N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &h[i]);
	}

	int total = 0;
	for (int i = 1; i < N-1; ++i) {
		total += h[i]>h[i-1] && h[i] > h[i+1];
	}

	printf("%d\n", total);
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