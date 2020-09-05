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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 5e5 + 10;

int n;

namespace seg{
	int seg[4*MAXN], delta[4*MAXN];
	void unlazy(int node, int l, int r){
		if (delta[node] == -1)
			return;
		if (l != r){
			delta[node<<1] = delta[node];
			delta[node<<1|1] = delta[node];
		}
		seg[node] = delta[node];
		delta[node] = -1;
	}

	void update(int node, int l, int r, int ul, int ur, int val){
		unlazy(node, l, r);
		if (r < ul or ur < l)
			return;
		if (ul <= l and r <= ur){
			delta[node] = val;
			unlazy(node, l, r);
			return;
		}

		int meio = (l + r)/2;
		update(node<<1, l, meio, ul, ur, val);
		update(node<<1|1, meio + 1, r, ul, ur, val);
		seg[node] = seg[node<<1] + seg[node<<1|1];
	}

	int query(int node, int l, int r, int pos){
		unlazy(node, l, r);
		if (r < pos or pos < l)
			return 0;
		if (l == r)
			return seg[node];

		int meio = (l + r)/2;
		return query(node<<1, l, meio, pos) | query(node<<1|1, meio + 1, r, pos);
	}

	void pupdate(int a, int b, int x){
		a++;b++;
		update(1, 1, n, a, b, x);
	}

	int pquery(int a, int b){
		a++;b++;
		return query(1, 1, n, a);
	}
}


vector<int> adj[MAXN];

namespace hld{
	int pos[MAXN], sz[MAXN], pai[MAXN], h[MAXN], clk;

	void dfs_sz(int v, int p = -1){
		sz[v] = 1;
		for (auto &x : adj[v]){
			if (x != p){
				dfs_sz(x, v);
				sz[v] += sz[x];
				if (sz[x] > sz[adj[v][0]] or adj[v][0] == p) 
					swap(x, adj[v][0]); // filho mais pesado em adj[v][0]
			}
		}
	}

	void dfs_build(int v, int p = -1){
		pos[v] = clk++; // contém a subárvore de v sequêncialmente
		for (auto &x : adj[v])
			if (x != p){
				pai[x] = v;
				if (x == adj[v][0])
					h[x] = h[v]; // na mesma cadeia que o pai
				else
					h[x] = x; // nova cabeça de cadeia
				dfs_build(x, v);
			}
	}

	void build(int r){ // monta a hld com raiz r
		clk = 0;
		h[r] = r;
		dfs_sz(r);
		dfs_build(r);
		fr(i, MAXN) // prepara a estutura de dados
			seg::delta[i] = -1;
	}

	// a hld como está opera sobre os vértices
	// podemos modificar a mesma para arestas
	// armazene o valor de uma aresta no filho
	// as alterações em indices estão descritas nos comentários

	void update_path(int a, int b, int x){
		if (pos[a] < pos[b])
			swap(a, b);
		if (h[a] == h[b])
			return (void) seg::pupdate(pos[b], pos[a], x); // pos[b] + 1
		seg::pupdate(pos[h[a]], pos[a], x);
		update_path(pai[h[a]], b, x);
	}

	void update_subtree(int a, int x){
		seg::pupdate(pos[a], pos[a] + sz[a] - 1, x); // pos[a] + 1
	}

	int query_vertex(int v){
		return seg::pquery(pos[v], pos[v]);
	}
}

int32_t main(){
	fastio;

	cin>>n;

	int a, b;
	fr(i, n - 1){
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	hld::build(1);

	int q;
	cin>>q;

	while (q--){
		cin>>a>>b;
		if (a == 1)
			hld::update_subtree(b, 1);
		else if (a == 2)
			hld::update_path(b, 1, 0);
		else
			cout<<hld::query_vertex(b)<<endl;
	}
}