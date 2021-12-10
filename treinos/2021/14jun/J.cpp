#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;

const ll MxN = 1e12 + 10;
const ll sqMxN = 1e6+10;

int prime[sqMxN];
ll l = 0;

void sieve (int n){
    bitset <sqMxN> bs; int ub = n+1;
    bs.set(); bs[0]=bs[1]=0;
    for(ll i=2; i <= ub ; i++) 
        if (bs[i]){
        for (ll j = i*i; j < ub; j+=i) bs[j]=0;
        prime[l++]=i;
    }}

vi prime_factors(ll n){
    vi fac; ll ind = 0, p=prime[ind];
    while(p*p <= n){
        while (n%p == 0){ n/=p; fac.push_back(p);}
        p = prime[++ind];
    } 
    if (n!=1) fac.push_back(n);
    return fac;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll N;
	cin >> N;
	sieve(sqMxN-10);

	vi fac = prime_factors(N);
	int last = -1, total_primos = 0;
	for (int i : fac) {
		// cout << i << endl;
		total_primos += i != last;
		last = i;
	}
	cout << (1 << total_primos) - total_primos - 1 << endl;


	return 0;
}