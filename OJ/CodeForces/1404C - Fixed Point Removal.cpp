#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

#define endl '\n'
#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(), x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 4e5 + 10;

priority_queue<int> pq;

namespace seg{
	int seg[4 * MAXN], lazy[4 * MAXN];

	void propagate(int node, int l, int r){
		if (l != r){
			lazy[node<<1] += lazy[node];
			lazy[node<<1|1] += lazy[node];
		}

		seg[node] += lazy[node];
		lazy[node] = 0;
	}

	void update(int node, int l, int r, int ql, int qr, int val){
		propagate(node, l, r);

		if (qr < l or r < ql)
			return;
		if (ql <= l and r <= qr){
			lazy[node] = val;
			propagate(node, l, r);
			return;
		}

		int m = (l + r)/2;

		update(node<<1, l, m, ql, qr, val);
		update(node<<1|1, m + 1, r, ql, qr, val);

		seg[node] = min(seg[node<<1], seg[node<<1|1]);
	}

	void update2(int node, int l, int r, int ql, int qr, int val){
		propagate(node, l, r);

		if (qr < l or r < ql)
			return;
		if (ql <= l and r <= qr){
			seg[node] = val;
			return;
		}

		int m = (l + r)/2;

		update2(node<<1, l, m, ql, qr, val);
		update2(node<<1|1, m + 1, r, ql, qr, val);

		seg[node] = min(seg[node<<1], seg[node<<1|1]);
	}



	void query(int node, int l, int r, int ql, int qr){
		propagate(node, l, r);
		if (qr < l or r < ql)
			return;

		if (seg[node] != 0) // não tenho elemento zero
			return;

		if (l == r){
			pq.push(l);
			seg[node] = INF;
			return;
		}

		int m = (l + r)/2;

		query(node<<1, l, m, ql, qr);
		query(node<<1|1, m + 1, r, ql, qr);

		seg[node] = min(seg[node<<1], seg[node<<1|1]);
	}
};


#define oper(a, b) a + b // opreação
#define NEUT 0 // elemento neutro

namespace segper{
	vector<int> seg(1, NEUT), lft(1, 0), rgt(1, 0); 
	int rt(0); // ultima raiz

	int new_node(int v, int l = 0, int r = 0){
		seg.pb(v);
		lft.pb(l);
		rgt.pb(r);
		return (int)(seg.size()) - 1;
	}

	int update(int nd, int l, int r, int pos, int val){
		int ks = new_node(seg[nd], lft[nd], rgt[nd]);
		if (l == r){
			seg[ks] += val;
			return ks;
		}
		
		int m = (l + r)/2, ps;
		if(pos <= m)
		    ps = update(lft[nd], l, m, pos, val), lft[ks] = ps;
		else 
			ps = update(rgt[nd], m + 1, r, pos, val), rgt[ks] = ps;
		
		seg[ks] = oper(seg[lft[ks]], seg[rgt[ks]]);
		return ks;
	}

	int query(int nd, int l, int r, int ql, int qr){
		if(r < ql or qr < l)
			return NEUT;
		if(ql <= l and r <= qr)
			return seg[nd];
		int m = (l + r)/2;
		return oper(query(lft[nd], l, m, ql, qr), query(rgt[nd], m + 1, r, ql, qr));
	}

	int update(int l, int r, int pos, int val){ return rt = update(rt, l, r, pos, val); } // ultima raiz
} 

int n, q, a[MAXN];
vi root;

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n>>q;
	fr(i, n){
		cin>>a[i];
		a[i]--;
	}

	seg::update(1, 0, n - 1, 0, n - 1, INF);

	for (int i = n - 1; i >= 0; i--){
		if (a[i] == i){
			pq.push(i);
			while (!pq.empty()){
				int u = pq.top();
				pq.pop();

				root.pb(segper::update(0, n - 1, u, 1)); // tirei o elemento
				seg::update(1, 0, n - 1, u, n - 1, -1); // diminuo -1 de geral
				seg::query(1, 0, n - 1, 0, n - 1);
			}
		}
		else if (a[i] < i){
			seg::update2(1, 0, n - 1, i, i, i - a[i]); // define dlt
		}
	}

	while (q--){
		int x, y;
		cin>>x>>y;

		if (root.size() == 0){
			cout<<0<<endl;
			continue;
		}

		int r = n - 1 - y; // nunca é -1

		if (x == 0){
			cout<<segper::query(root.back(), 0, n - 1, 0, r)<<endl;
		}
		else{
			int ini = 0, fim = root.size() - 1, bst = 0;

			while (ini <= fim){
				int m = (ini + fim)/2;

				if (segper::query(root[m], 0, n - 1, 0, x - 1) <= 0){
					ini = m + 1;
					bst = m;
				}
				else
					fim = m - 1;
			}
			cout<<segper::query(root[bst], 0, n - 1, x, r)<<endl;
		}
	}
}