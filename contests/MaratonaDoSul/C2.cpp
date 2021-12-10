#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int MxN = 19;
const int MOD = 1e9 + 7;

vector <int> v(38);


int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, index = 0;
	cin>>n;
	for (int i = 0; i<n; i++)
	{
		v[i] = 1;
	}
	int i;
	for (i =2; i<112345678912345;i++)
	{
		int j;
		index = 0;
		//cout<<i<<"--------------\n";
		for (j= 0; j<n; j++)
		{
			int aux = (index + i-1)%(2*n-j);
			//cout<<j<<' '<<index<<' '<<aux<<'\n';
			if (v[aux] == 1)
			{
				break;
			}
			index = aux;
		}
		if (j==n)
		{
			break;
		}
	}
	cout<<i<<'\n';

	return 0;
}