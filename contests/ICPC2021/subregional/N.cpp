#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<ll,ll>;

const int MxN = 312345;
const int MOD = 1e9 + 7;

int Y, N;
ll bit[MxN], resp[MxN];

void setbit(int i , ll v){
  while(i<MxN){
    bit[i]+=v;
    i+=i&-i;
  }
}

ll getbit(int i){
  ll ret = 0;
  while(i>0){
    ret+=bit[i];
    i-=i&-i;
  }
  return ret;
}


struct query {
	ll k, l, r, id;
};

query queries[MxN];
pii entries[MxN];
ll entries_uns[MxN];

bool cmp(query a, query b)
{
  if (a.k == b.k)
      return a.l > b.l;

  return a.k > b.k;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> Y >> N;

	for(int i = 0; i < Y; ++i) {
		int inp;
		cin >> inp;
		entries[i] = {inp, i+1};
		entries_uns[i+1] = inp;
	}

	for(int i = 0; i < N; ++i) {
		int l, k, sz;
		cin >> l >> k >> sz;
		int r = l+sz;
		l++;
		queries[i] = {k, l, r, i};
	}

	sort(entries, entries + Y, greater<pii>());
	sort(queries, queries+N, cmp);

	for(int q = 0, e = 0; q<N;/*lembrar*/) {
		// cerr << q << 'a' << e << endl;
		if (queries[q].k > entries[e].first || (e == Y-1)) { // faz a query
			if (entries_uns[queries[q].l-1] >= queries[q].k) {
				resp[queries[q].id] = 0;
			} else {
				resp[queries[q].id] = getbit(queries[q].r) - getbit(queries[q].l-1);
				// cerr << resp[queries[q].id] << ' ' << getbit(queries[q].r) << endl;
			}
			q++;
		} else { // faz a entry
			// cerr << entries[e] << ' ' << getbit(entries[e]) << endl;
			setbit(entries[e].second, 1);
			// for(int i = 1; i < 14; ++i) {
			// 	cerr << i << 'l' << getbit(i) << endl;
			// }
			e++;
		}
	}

	for(int i = 0; i < N; ++i) {
		cout << resp[i] << endl;
	}


	return 0;
}