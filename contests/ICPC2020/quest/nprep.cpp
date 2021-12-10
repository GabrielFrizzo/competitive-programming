#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "


using ll = long long;
using vi = vector<ll>;
using pii = pair<int, int>;
const ll MxN = sqrt(1e15) + 100;

ll prime[MxN];
ll l = 0;

void sieve (ll n) {
  bitset <MxN> bs; int ub = n+1;
  bs.set(); bs[0]=bs[1]=0;
  for(ll i=2; i <= ub ; i++) {
    if (bs[i]) {
    	for (ll j = i*i; j < ub; j+=i) bs[j]=0;
    	prime[l++] = i;         
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	sieve(MxN-99);

	cout << l << endl;
	// for (int i = 0; i <= l; ++i) {
	// 	cout << prime[i] << ",";
	// }
}