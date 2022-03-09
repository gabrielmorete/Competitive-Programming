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

int n;
vector<array<int, 3>> adj[MAXN];


namespace seg{
	ll seg[4*MAXN], lazy[4*MAXN];

	void propagate(int node, int l, int r){
		if (l != r){
			lazy[node<<1] += lazy[node];
			lazy[node<<1|1] += lazy[node];
		}

		seg[node] += lazy[node];
		lazy[node] = 0;
	}

	void update(int node, int l, int r, int ql, int qr, ll val){
		propagate(node, l, r);

		if (qr < l or r < ql)
			return;
		
		if (ql <= l and r <= qr){
			lazy[node] += val;
			propagate(node, l, r);
			return;
		}

		int m = (l + r)/2;

		update(node<<1, l, m, ql, qr, val);
		update(node<<1|1, m + 1, r, ql, qr, val);

		seg[node] = min(seg[node<<1], seg[node<<1|1]);
	}

	ll query(int node, int l, int r, int ql, int qr){
		propagate(node, l, r);
		if (qr < l or r < ql)
			return INF;
		
		if (ql <= l and r <= qr)
			return seg[node];

		int m = (l + r)/2;

		return min(query(node<<1, l, m, ql, qr), query(node<<1|1, m + 1, r, ql, qr));
	}

	ll query(int ql, int qr){
		return query(1, 1, n, ql, qr);
	}

	void update(int ql, int qr, ll val){
		update(1, 1, n, ql, qr, val);
	}

}

namespace hld{
	int pos[MAXN], sz[MAXN], pai[MAXN], cap[MAXN], h[MAXN], clk;

	void dfs_sz(int v, int p = -1){
		sz[v] = 1;
		for (auto &x : adj[v]){
			if (x[0] != p){
				dfs_sz(x[0], v);
				sz[v] += sz[x[0]];
				if (sz[x[0]] > sz[adj[v][0][0]] or adj[v][0][0] == p) 
					swap(x, adj[v][0]);
			}
		}
	}

	void dfs_build(int v, int p = -1){
		pos[v] = clk++;
		for (auto &x : adj[v])
			if (x[0] != p){
				pai[x[0]] = v;
				cap[x[0]] = x[1];
				if (x[0] == (adj[v][0])[0])
					h[x[0]] = h[v];
				else
					h[x[0]] = x[0];
				dfs_build(x[0], v);
			}
	}

	void build(int r){
		clk = 0;
		h[r] = r;
		dfs_sz(r);
		dfs_build(r);

		for (int i = 2; i <= n; i++)
			seg::update(1, 1, n, pos[i], pos[i], cap[i]);

		seg::update(1, 1, n, pos[r], pos[r], INF);
	}

	ll combine(ll a, ll b){
		return min(a, b);
	}

	void update_path(int a, int b, int x){
		if (pos[a] < pos[b])
			swap(a, b);
		if (h[a] == h[b])
			return (void) seg::update(pos[b], pos[a], x); // pos[b] + 1
		seg::update(pos[h[a]], pos[a], x);
		update_path(pai[h[a]], b, x);
	}

	ll query_path(int a, int b){
		if (pos[a] < pos[b])
			swap(a, b);
		if (h[a] == h[b])
			return seg::query(pos[b], pos[a]); // pos[b] + 1!!
		return combine(seg::query(pos[h[a]], pos[a]) , query_path(pai[h[a]], b));
	}
}

vector<pair<ll, ll>> leaf;

void dfs(int v, int p, ll val){
	if (adj[v].size() == 1 and v != 1){ // sou folha, eu envio fluxo
		leaf.pb({val, v});
		return;
	}

	for (auto x : adj[v])
		if (x[0] != p)
			dfs(x[0], v, val + x[2]); // valor do caminho até lá
}


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;

	fr(i, n - 1){
		int a, b, c, d;
		cin>>a>>b>>c>>d;
		adj[a].pb({b, c, d});
		adj[b].pb({a, c, d});
	}

	hld::build(1);

	dfs(1, 1, 0); // acha as folhas

	sort(all(leaf));

	cout<<setprecision(15)<<fixed;

	ll flow = 0, cost = 0;
	for (auto x : leaf){
		// cout<<x.snd<<' '<<x.fst<<endl;
		if (x.fst <= 0){ // sou livre pra torar o pau
			ll inc = hld::query_path(x.snd, 1); // o quanto posso aumentar no fluxo
			hld::update_path(x.snd, 1, -inc); // diminuo a capacidade
			flow += inc;
			cost += x.fst * inc;
		}
		else{ // humm, vamos ver qual é
			ll inc = hld::query_path(x.snd, 1); // o quanto posso aumentar no fluxo
			hld::update_path(x.snd, 1, -inc); // diminuo a capacidade
			
			// dbg(inc);

			if (inc * x.fst > abs(cost)){ // vou ter que pagar!!
				long double ans = abs(cost);;
				ans /= x.fst; // é o que da pra incrementar agora
				
				ans += flow;

				cout<<ans<<endl;

				return 0;
			}
			else{
				flow += inc;
				cost += x.fst * inc;
			}
		}
	}

	cout<<flow<<endl;
}