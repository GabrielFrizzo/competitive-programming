#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int MxN = 5123;
const int MOD = 1e9 + 7;

ll mem[1123456];

string s = "";

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n;
    mem[0] = 1;
    mem[1] = 1;
    int i = 2;
    if (n==1) {
        cout<<"B\n";
        return 0;
    }
    while (1) {
        if (mem[i-1] + mem [i-2]>n) {
            break;
        }
        mem[i] = mem[i-1] + mem [i-2];
        i++;
    }

    m = n;
    
    for (int j = i-1; j>=2&&m>1; j--) {
        if ((m % mem[j]) == 0) {
            m = m/mem[j];
            for (int k = 0; k <j-1; k++) {
                s += "A";
            }
            s += "B";
            //cout<<mem[j]<<endl;;
            j++;
        }

        //cout<<m<<endl;
    }
    if (m!=1) {
      cout<<"IMPOSSIBLE\n";
    } else {
    	cout << s << endl;
    }

    return 0;
}