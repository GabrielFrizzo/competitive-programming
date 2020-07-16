#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int MxN = 212345;

ll bit1par[MxN], bit2par[MxN];
ll bit1impar[MxN], bit2impar[MxN];
int N, Q;

void setbitpar(int i, ll val) {
  while (i <= N) {
    bit1par[i] += val;
    i += i & -i;
  }}

ll getbitpar(int i) {
  ll ret = 0;
  while (i > 0) {
    ret += bit1par[i];
    i -= i & -i;
  }
  return ret;
}

void setbitpar2(int i, ll val) {
  while (i <= N) {
    bit2par[i] += val;
    i += i & -i;
  }
}

ll getbitpar2(int i) {
  ll ret = 0;
  while (i > 0) {
    ret += bit2par[i];
    i -= i & -i;
  }
  return ret;
}

void setbitimpar(int i, ll val) {
  while (i <= N) {
    bit1impar[i] += val;
    i += i & -i;
  }}

ll getbitimpar(int i) {
  ll ret = 0;
  while (i > 0) {
    ret += bit1impar[i];
    i -= i & -i;
  }
  return ret;
}

void setbitimpar2(int i, ll val) {
  while (i <= N) {
    bit2impar[i] += val;
    i += i & -i;
  }
}

ll getbitimpar2(int i) {
  ll ret = 0;
  while (i > 0) {
    ret += bit2impar[i];
    i -= i & -i;
  }
  return ret;
}

int itob(int i) {
	if (i&1) {
		return i/2+1;
	}
	else {
		return i/2;
	}
}

void solve() {
    cin >> N >> Q;
    memset(bit1impar, 0, sizeof(bit1impar));
    memset(bit2impar, 0, sizeof(bit2impar));
    memset(bit1par, 0, sizeof(bit1par));
    memset(bit2par, 0, sizeof(bit2par));
    for (int i = 1; i <= N; ++i) {
    	int inp;
    	cin >> inp;
    	if (i&1) {
    		int cons = i*2-1;
    		setbitimpar((i+1)/2, inp);
    		setbitimpar2((i+1)/2, inp*cons);
    	} else {
    		int cons = i-1;
    		setbitpar(i/2, inp);
    		setbitpar2(i/2, inp*cons);
    	}
    }

    ll total = 0;
    while(Q--) {
    	char op;
    	cin >> op;
    	if (op == 'Q') {
    		int l, r;
    		cin >> l >> r;
    		ll resp = 0;
    		int sign = (l&1) ? -1 : 1;
    		if (l&1) {
    			resp -= getbitimpar2(itob(l)-1);
    			resp += getbitpar2(itob(l+1)-1);
    		} else {
    			resp += getbitimpar2(itob(l+1)-1);
    			resp -= getbitpar2(itob(l)-1);
    		}
    		if (r&1) {
    			resp += sign*getbitimpar2(itob(r));
    			resp -= sign*getbitpar2(itob(r-1));
    		} else {
    			resp -= sign*getbitimpar2(itob(r-1));
    			resp += sign*getbitpar2(itob(r));
    		}
    		if (l&1) {
    			resp += (l-1)*getbitimpar(itob(l)-1);
    			resp -= (l-1)*getbitpar(itob(l+1)-1);
    		} else {
    			resp -= (l-1)*getbitimpar(itob(l+1)-1);
    			resp += (l-1)*getbitpar(itob(l)-1);
    		}
    		if (r&1) {
    			resp += sign*(l-1)*getbitimpar(itob(r));
    			resp -= sign*(l-1)*getbitpar(itob(r-1));
    		} else {
    			resp -= sign*(l-1)*getbitimpar(itob(r-1));
    			resp += sign*(l-1)*getbitpar(itob(r));
    		}
    		total += resp;
    	} else {
    		assert(op =='U');
    		int i, v;
    		cin >> i >> v;
    		if (i&1) {
    			int cons = i;
    			i = (i+1)/2;
    			ll prev = getbitimpar(i);
    			ll curr = v - prev;
    			ll prev2 = getbitimpar2(i);
    			ll curr2 = v*cons - prev2;
    			setbitimpar(i, curr);
    			setbitimpar2(i, curr2);
    		} else {
    			int cons = i-1;
    			i /= 2;
    			ll prev = getbitpar(i);
    			ll curr = v - prev;
    			ll prev2 = getbitpar2(i);
    			ll curr2 = v*cons - prev2;
    			setbitpar(i, curr);
    			setbitpar2(i, curr2);
    		}
    	}
    }

    cout << total << endl;
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int TC;
    cin >> TC;
    for (int i = 1; i <= TC; ++i) {
    	cout << "Case #" << i << ": ";
    	solve();
    }
	return 0;
}