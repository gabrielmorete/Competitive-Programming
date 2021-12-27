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

ll ans[MAXN], n, q, a[MAXN];


#define oper(a, b) a + b // opreação
#define NEUT 0 // elemento neutro

namespace seg{
	vector<ll> seg(1, NEUT), lft(1, 0), rgt(1, 0); 
	int rt(0); // ultima raiz

	void init(){ seg = vector<ll>(1, NEUT); lft = vector<ll>(1, 0); rgt = vector<ll>(1, 0); rt = 0;}

	int new_node(int v, int l = 0, int r = 0){
		seg.pb(v);
		lft.pb(l);
		rgt.pb(r);
		return (int)(seg.size()) - 1;
	}

	int build(int l, int r, int *a){ // coloca todos os elementos de a na raiz 0
		if(l == r)
			return new_node(a[l]);
		
		int m = (l + r)/2;
		int nl = build(l, m, a);
		int nr = build(m + 1, r, a);
		return rt = new_node(oper(seg[nl], seg[nr]), nl, nr); // query na ultima raiz!
	}
	
	int update(int nd, int l, int r, int pos, int val){
		int ks = new_node(seg[nd], lft[nd], rgt[nd]);
		if (l == r){
			seg[ks] = val;
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

	ll query(int nd, int l, int r, int ql, int qr){
		if(r < ql or qr < l)
			return NEUT;
		if(ql <= l and r <= qr)
			return seg[nd];
		int m = (l + r)/2;
		return oper(query(lft[nd], l, m, ql, qr), query(rgt[nd], m + 1, r, ql, qr));
	}

	int update(int l, int r, int pos, int val){ return rt = update(rt, l, r, pos, val); } // ultima raiz
} 


vector<pair<ll, ll>> root;

bool test(ll val, ll l, ll r, ll d){
	ll cst = seg::query(root[val].snd, 1, n, l, r);

	return cst <= d;
}

vector<pair<ll, ll>> v;


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>q;

	frr(i, n){
		ll x;
		cin>>x;
		v.pb({x, i});
	}

	sort(all(v));

	int p = 0;
	while (p < n){
		int q = p;
		while (q < n and v[p].fst == v[q].fst)
			q++;

		ll r = seg::update(1, n, v[p].snd, v[p].fst);
		for (int i = p + 1; i < q; i++)
			r = seg::update(1, n, v[i].snd, v[i].fst);

		root.pb({v[p].fst, r});

		p = q;
	}


	ans[0] = 0;
	frr(i, q){
		ll x, y, z;
		cin>>x>>y>>z;


		ll l = 1 + (x + ans[i - 1] - 1) % n; 
		ll r = 1 + (y + ans[i - 1] - 1) % n;
		ll d = z + ans[i - 1];

		ll ini = 0, fim = (int)(root.size()) - 1, bst = -1;

		while (ini <= fim){
			ll mid = (ini + fim)/2;
			if (test(mid, l, r, d)){
				bst = mid;
				ini = mid + 1;
			}
			else
				fim = mid - 1;
		}

		if (bst == -1)
			ans[i] = 0;
		else
			ans[i] = seg::query(root[bst].snd, 1, n, l, r);
	}	

	frr(i, q)
		cout<<ans[i]<<endl;
}