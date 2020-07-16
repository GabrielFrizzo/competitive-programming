#include <bits/stdc++.h>
using namespace std;

#define MxN 112

typedef struct {
	int x, y;
	int keys;
	int len;
} arya;

int N, M;
vector<vector<char>> m;
bool visited[MxN][MxN][128];

int	binary(char c) {
	if (c == 'A' || c == 'a') return 1;
	if (c == 'B' || c == 'b') return 1<<1;
	if (c == 'C' || c == 'c') return 1<<2;
	if (c == 'D' || c == 'd') return 1<<3;
	if (c == 'E' || c == 'e') return 1<<4;
	if (c == 'F' || c == 'f') return 1<<5;
	if (c == 'G' || c == 'g') return 1<<6;
	return 0;	
}

bool iskey(char c) {
	return (c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f' || c == 'g');
}

bool cango(arya& curr, char nxtc) {
	return (nxtc == '.' || iskey(nxtc) || (curr.keys & binary(nxtc)) != 0);
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    N = 0;
    while(getline(cin, line)) {
    	if (line.empty())
    		break;
    	m.push_back(vector<char>());
    	for (char c : line) {
    		m[N].push_back(c);
    	}
    	N++;
    }

    M = m[0].size();

    pair<int,int> pos;
    for (int i = 0; i < N; ++i) {
    	for (int j = 0; j < M; ++j) {
    		if (m[i][j] == '@') {
    			pos = {i,j};
    			m[i][j] = '.';
    		}
    	}
    }
    
	queue<arya> q;
	arya init = {pos.second, pos.first, 0, 0};
	q.push(init);
	vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
	while (!q.empty()) {
		arya curr = q.front(); q.pop();
		visited[curr.x][curr.y][curr.keys] = true;
		for (pair<int,int> pii : directions) {
			arya nxt = curr; nxt.x += pii.first; nxt.y += pii.second; nxt.len++;
			if (nxt.x < 0 || nxt.x >= M || nxt.y < 0 || nxt.y >= N || visited[nxt.x][nxt.y][nxt.keys]) continue;
			char nxtc = m[nxt.y][nxt.x];
			if (nxtc == '#') continue;
			if (nxtc == '*') {cout << nxt.len << endl; exit(0);}
			if (cango(curr, nxtc)) {
				if (iskey(nxtc)) {
					nxt.keys |= binary(nxtc);
				}
				q.push(nxt);
			}
		}
	}

	cout << "--" << endl;

	return 0;
}