// Algoritmo de Tarjan para SCC
// complexidade : O(n + m)

#include "bits/stdc++.h"
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 10;

int n, clk, sn, id;
int pre[MAXN], lo[MAXN], stk[MAXN], scc[MAXN]; // scc[v] é a componente forte de v
vector<int> adj[MAXN], adjscc[MAXN];

void dfsRscc( int v) {
	pre[v] = lo[v] = clk++;
	stk[sn++] = v;
	for (auto x : adj[v]) {
		if (pre[x] == -1)
			dfsRscc( x);
		lo[v] = min( lo[v], lo[x]);
	}
	if (lo[v] == pre[v]) {
		int u;
		do {
			u = stk[--sn];
			scc[u] = id;
			lo[u] = INF;
		} while (u != v);
		id++;
	}
}

int tarjan() {
	for (int v = 0; v < n; v++)
		pre[v] = -1;
	clk = sn = id = 0;
	for (int v = 0; v < n; v++)
		if (pre[v] == -1)
			dfsRscc( v);
	return id;	
}

// Constoi arvore das scc
void build_scc_graph() {
	for (int v = 0; v < n; v++)
		for (auto x : adj[v])
			if (scc[v] != scc[x])
				adjscc[scc[v]].push_back(scc[x]);
}