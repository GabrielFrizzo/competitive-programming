#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using pid = pair<int, double>;
using vi = vector<int>;
using ll = long long;

const int MxN = 11234;

double memo[MxN][1123][7];
vector<pid> trips;
int N;
double dp(int i, int time, int buy) {
	if (i >= N) return 0;
	// cout << i << ' ' << time << ' ' << buy << endl;
	// cout << memo[i][time][buy] << endl;
	if (memo[i][time][buy] != -1) return memo[i][time][buy];
	double ch1 = dp(i+1, trips[i].first, 1) + trips[i].second;
	if (time >= 120 || buy == 6) return memo[i][time][buy] = ch1;
	double ch2;
	if (buy == 1) ch2 = dp(i+1, time+trips[i].first, buy+1) + trips[i].second*0.5;
	else ch2 = dp(i+1, time+trips[i].first, buy+1) + trips[i].second*0.25;

	// cout << trips[i].second*0.5 << endl;
	return memo[i][time][buy] = min(ch1, ch2);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    trips.resize(N);
    for (int i = 0; i < N; ++i) {
    	cin >> trips[i].first >> trips[i].second;
    }

    for (int i = 0; i < N; ++i)
    	for (int j = 0; j < 1123; ++j)
    		for (int k = 0; k < 7; ++k)
    			memo[i][j][k] = -1;

    cout << fixed << setprecision(2) << dp(1, trips[0].first, 1) + trips[0].second << endl;

	return 0;
}