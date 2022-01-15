#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, inp;
    int m2, m3, m4, m5;
	m2 = m3 = m4 = m5 = 0;

    cin >> n;

    while (n--) {
    	cin >> inp;
    	if (inp % 2 == 0) m2++;
    	if (inp % 3 == 0) m3++;
    	if (inp % 4 == 0) m4++;
    	if (inp % 5 == 0) m5++;
    }

    cout << m2 << " Multiplo(s) de 2" << endl;
	cout << m3 << " Multiplo(s) de 3" << endl;
	cout << m4 << " Multiplo(s) de 4" << endl;
	cout << m5 << " Multiplo(s) de 5" << endl;
	return 0;
}