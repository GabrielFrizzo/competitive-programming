#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;

#define MxF 100
#define MxN 5

struct state {
	int time, elevator, floor;

	state() {}
	state(int _time, int _elevator, int _floor) : time(_time), elevator(_elevator), floor(_floor) {}
};
bool operator<(const state& self, const state& other) {
	return self.time > other.time;
}

int speed[MxN];
int visited[MxN][MxF];

void solve(int n, int k) {
	vector<set<int>> goesto(MxN);
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < n; ++i) {
		cin >> speed[i];
	}
	cin.ignore();
	for (int i = 0; i < n; ++i) {
		string buff;
		getline(cin, buff);
		istringstream iss(buff);
		int floor;
		while (iss >> floor)
			goesto[i].insert(floor);
	}

	priority_queue<state> pq;
	for (int i = 0; i < n; ++i)
		if (goesto[i].count(0))
			pq.push({0, i, 0});

	while (!pq.empty()) {
		state curr = pq.top(); pq.pop();
		// cout << curr.floor << endl;
		if (visited[curr.elevator][curr.floor]) continue;
		visited[curr.elevator][curr.floor] = true;
		if (curr.floor == k) {cout << curr.time << endl; return;}

		for (int i = 0; i < n; ++i) // switch elevator
			if (i != curr.elevator && goesto[i].count(curr.floor))
				pq.push(state(curr.time+60, i, curr.floor));

		for (int floor : goesto[curr.elevator]) {
			int dt = speed[curr.elevator]*abs(curr.floor-floor);
			pq.push(state(curr.time+dt, curr.elevator, floor));
		}
	}

	cout << "IMPOSSIBLE" << endl;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	while(cin >> n >> k) {
		solve(n, k);
	}
	return 0;
}