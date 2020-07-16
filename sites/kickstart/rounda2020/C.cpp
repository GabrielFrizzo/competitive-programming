#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

void solve() {
	int N, K;
    cin >> N >> K;
    priority_queue<int> pq;
    int prev, inp;
    cin >> prev;N--;
    while (N--) {
        cin >> inp;
        pq.push(abs(inp-prev));
        prev = inp;
    }

    while (K--) {
        int curr = pq.top(); pq.pop();
        pq.push(curr/2); pq.push(curr/2+(curr&1));
    }

    cout << (pq.top() == 0 ? 1 : pq.top()) << endl;
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int TC;
    cin >> TC;
    for (int i = 1; i <= TC; ++i) {
    	cout << "Case #" << i << ": ";
    	solve();
    }
	return 0;
}