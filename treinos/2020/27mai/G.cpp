#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int MxN = 112345;

int last[MxN];
int head[MxN];
int query[MxN];
int h[MxN];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int Q;
    cin >> Q;
    memset(last, -1, sizeof last);
    memset(head, -1, sizeof head);

    h[0] = 0;
    for (int i = 1; i <= Q; ++i) {
    	char c;
    	int v, x;
    	cin >> c;
    	if (c == 'E') {
    		cin >> v >> x;
    		last[i] = x;
    		if (head[v] == -1) head[i] = x;
    		else head[i] = head[v];
    	} else {
    		cin >> v;
    		cout << head[v] << endl;
    		int count = 1;
    		while (count < h[v]) {
    			cout << "entrou" << endl;
    			if (last[v] == -1) count++;
    			// if (count >= h[v]) break;
    			v = query[v];
    		}
    		cout << last[v] << endl;
    		head[i] = last[v];
    	}
    	query[i] = v;
    	h[i] = h[v]+1;
    }
	return 0;
}