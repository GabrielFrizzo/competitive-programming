#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a, b, c, d;

    cin >> a >> b >> c >> d;
    int f = a*60 + b;
    int f2 = c*60+d;
    int res = f2-f;

    res = res > 0 ? res : 24*60+res;
    int h = res/60;
    int min = res%60;

    cout << "O JOGO DUROU " << h << " HORA(S) E " << min << " MINUTO(S)" << endl;


	return 0;
}