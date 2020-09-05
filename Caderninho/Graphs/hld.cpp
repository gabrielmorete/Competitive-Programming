// Heavy-Light Decomposition 
// Permite fazer operações em caminhos/subárvores
// Complexidades:
// build - O(n)
// query_path - O(log(n)^2)
// update_path - O(log(n)^2)
// query_subtree - O(log(n))
// update_subtree - O(log(n))
// lca - O(log(n))
// anc - O(1)

#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e5 + 10;

namespace seg{}; // seg é só um modelo, pode ser qualquer ed

int n;
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
		// prepare a estutura de dados
	}

	// a hld como está opera sobre os vértices
	// podemos modificar a mesma para arestas
	// armazene o valor de uma aresta no filho
	// as alterações em indices estão descritas nos comentários

	void update_path(int a, int b, int x){
		if (pos[a] < pos[b])
			swap(a, b);
		if (h[a] == h[b])
			return (void) seg::update(pos[b], pos[a], x); // pos[b] + 1
		seg::update(pos[h[a]], pos[a], x);
		update_path(pai[h[a]], b, x);
	}

	int combine(int a, int b){
		// combina os valores das query
	}

	int query_path(int a, int b){
		if (pos[a] < pos[b])
			swap(a, b);
		if (h[a] == h[b])
			return seg::query(pos[b], pos[a]); // pos[b] + 1
		return combine(seg::query(pos[h[a]], pos[a]) , query_path(pai[h[a]], b));
	}

	void update_subtree(int a, int x){
		seg::update(pos[a], pos[a] + sz[a] - 1, x); // pos[a] + 1
	}
	
	int query_subtree(int a){ // subarvore guardada sequencialmente
		return seg::query(pos[a], pos[a] + sz[a] - 1); //pos[a] +1
	}

	int lca(int a, int b){ // lca de a e b
		if (pos[a] < pos[b])
			swap(a, b);
		return h[a] == h[b] ? b : lca(pai[h[a]], b);
	}

	bool anc(int a, int b){ // a é ancestral de b?
		return pos[a] < pos[b] and pos[b] < pos[a] + sz[a];
	}
}

// Baseado em : https://github.com/brunomaletta/Biblioteca/tree/master/Codigo/Grafos/LCA-HLD