#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int MxN = 112345678;
const int MOD = 1e9 + 7;

vector<ll> prime;
ll l = 0;

void sieve (int n){
	bitset <10000010> bs; int ub = n+1;
	bs.set(); bs[0]=bs[1]=0;
	for(ll i=2; i <= ub ; i++) 
		if (bs[i]) {
			for (ll j = i*i; j < ub; j+=i) bs[j]=0;
			prime.push_back(i);
		}
}

vi prime_factors(int n){
	vi fac; int ind = 0, p=prime[ind];
	while(p*p <= n){
		while (n%p == 0){ n/=p; fac.push_back(p);}
		p = prime[++ind];
	}
	if (n!=1) fac.push_back(n);
	return fac;
}

const int fib[100] = {2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040,1346269,2178309,3524578,5702887,9227465,14930352,24157817,39088169,63245986,102334155,165580141,267914296,433494437,701408733,1134903170,1836311903,2971215073,4807526976,7778742049,12586269025,20365011074,32951280099,53316291173,86267571272,139583862445,225851433717,365435296162,591286729879,956722026041,1548008755920,2504730781961,4052739537881,6557470319842,10610209857723,17167680177565,27777890035288,44945570212853,72723460248141,117669030460994,190392490709135,308061521170129,498454011879264,806515533049393};
int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	sieve(10000000);

	int N;
	cin >> N;

	vi primes = prime_factors(N);

	sort(fib, fib+73, greater<int>());

	for(int i = 0; i < count; ++i) {
		
	}

	return 0;
}