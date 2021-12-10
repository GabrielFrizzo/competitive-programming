#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

struct node {
	int r,p,s;
	node(){}
	node(int _r,int _p, int _s) : r(_r), p(_p), s(_s) {}
};

typedef vector<node> vn;

struct SegTree {
   	vn V, st; int N;
   	vi lazy;

    int left(int p) { return p<<1; }
    int right(int p) { return (p<<1)+1; }

    SegTree(const vn& _V) {
        V = _V; N = V.size();
        lazy.assign(4*N, 0);
        st.assign(4*N, node(0,0,0));
        build(1, 0, N-1);
    }

    node build(int p, int l, int r) {
        int mid = (l+r)/2;
        if (l == r) return st[p] = V[l];
        node p1 = build(left(p), l, mid);
        node p2 = build(right(p), mid+1, r);
        return st[p] = node(p1.r+p2.r, p1.p + p2.p, p1.s + p1.s);
    }

    node query(int p, int l, int r, int i, int j) {
	    	if (i > r || j < l) return {0,0,0};
				propagate(p, l, r);
        if (l >= i && r <= j) return st[p];

        int mid = (l+r)/2;
        if (i > r || j < l) return node(0,0,0);

        node p1 = query(left(p), l, mid, i, j);
        node p2 = query(right(p), mid+1, r, i, j);

        return node(p1.r+p2.r,p1.p+p2.p,p1.s+p2.s);
    }

    node upd(int p, int l, int r, int i, int j) {
    	propagate(p, l, r);
        if (i > r || j < l) return st[p];

        int mid = (l+r)/2;

        if (l >= i && r <= j) {
					lazy[p]++;
					propagate(p, l, r);
					return st[p];
				}

        node p1 = upd(left(p), l, mid, i, j);
        node p2 = upd(right(p), mid+1, r, i, j);

        return st[p] = node(p1.r+p2.r,p1.p+p2.p,p1.s+p2.s);
    }

    void upd(int i, int j) {
        upd(1, 0, N-1, i, j); 
    }

    node query(int a, int b) {
        return query(1, 0, N-1, a, b);
    }

    void propagate(int p, int l, int r) {
    	if (l != r)
    		lazy[left(p)] = lazy[right(p)] = lazy[p];
	    
	    lazy[p] %= 3;

	    while (lazy[p]--) {
	    	int aux = st[p].r;
	    	st[p].r = st[p].s;
	    	st[p].s = st[p].p;
	    	st[p].p = aux;
	    }
	   }
};


int main(){
	int n,m;
	int first = 1;
	while (scanf("%d %d",&n,&m) != EOF){
		vn init(n+1,node(1,0,0));
		SegTree stree(init);
	    if (!first) printf("\n");
	    first = 0;
	    while(m--) {
	        char op; int a, b;
	        cin >> op >> a >> b;
	        if (op == 'C') {
	        	node ans = stree.query(a,b);
	        	printf("%d %d %d\n",ans.r,ans.p,ans.s);
	        }
	        else if (op == 'M'){
	        	stree.upd(a,b);
	        }
	    }
	}
	return 0;
}