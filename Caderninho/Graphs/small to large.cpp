// Código para small to large (dsu on tree)
//
// Responde todas as queries aproveitando
// a resposta do filho mais pesado
// Complexidade
// dfs_sz: O(n)
// dfs: O(nlog(n))

// Nesse problema vamos contrar todos os pares
// (u, v) com d(u, v) <= val.

#include "bits/stdc++.h"
using namespace std;

typedef long long int ll;
const int MAXN = 5e5 + 10;

int n, m;

namespace seg{ // estrutura de dados auxiliar
	int t[2 * MAXN];

	void modify(int p, int value) {  
		for (t[p += n] += value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
	}

	int query(int l, int r) {  // sum on interval [l, r)
		int res = 0;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l&1) res += t[l++];
			if (r&1) res += t[--r];
		}
		return res;
	}
}

int sz[MAXN], hgt[MAXN], in[MAXN], out[MAXN], rt[MAXN], clk;
vector<int> adj[MAXN]; // adj da árvore

void dfs_sz(int v, int p = -1){
	sz[v] = 1;
	in[v] = clk;
	rt[clk++] = v;
	for (auto &x : adj[v]){
		if (x != p){
			hgt[x] = hgt[v] + 1;
			dfs_sz(x, v);
			sz[v] += sz[x];
			if (sz[x] > sz[adj[v][0]] or adj[v][0] == p) // adj[v][0] é sempre o filho pesado
				swap(x, adj[v][0]);
		}
	}
	out[v] = clk - 1; // in[v] - out[v], tempo de todos os descendentes de v
}

ll dfs(int v, int p, int val, bool keep = 0){
	int bc = adj[v].size() > 1 ? adj[v][0] : -1; // filho pesado
	ll ans = 0;

	for (int u : adj[v])
		if (u != p and u != bc)
			ans += dfs(u, v, val);

	if (bc != -1)
		ans += dfs(bc, v, val, 1); // guarda resposta do filho pesado

	for (auto u : adj[v])
		if (u != p and u != bc){
	    	for(int x = in[u]; x <= out[u]; x++)
				if (val + (2 * hgt[v]) - hgt[rt[x]] > 0) // conta pares com outras arvores
					ans += seg::query(0, val + (2 * hgt[v]) - hgt[rt[x]] + 1);

	    	for (int x = in[u]; x <= out[u]; x++) // adciona a subárvore
				seg::modify(hgt[rt[x]], 1);
	    }

	ans += seg::query(0, val + hgt[v] + 1);    
	seg::modify(hgt[v], 1); // adiciona v

    if (!keep) // apaga trabalho do filho leve
     	for(int x = in[v]; x <= out[v]; x++)
			seg::modify(hgt[rt[x]], -1); 
    return ans;
}

void solve(){
	memset(seg::t, 0, sizeof seg::t);
	int root = 1;
	hgt[root] = clk = 0;
	dfs_sz(root);
	ll ans = dfs(root, root, val);
}
