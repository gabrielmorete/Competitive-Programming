// Algoritmo de Tarjan para BCC
// complexidade : O(n + m)

#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e5 + 10;

int n, m, sn, clk, id;
int pre[MAXN], lo[MAXN], pa[MAXN], stk[MAXN], bcc[MAXN]; // bcc[v] é a componente biconexa de v
vector< pair<int,int> > adj[MAXN], adjbcc[MAXN];

void dfsRebcc( int v) {
	pre[v] = clk++;
	stk[sn++] = v;
	lo[v] = pre[v];
	for (auto x : adj[v]) {
		int  w = x.fst;
		if (pre[w] == -1) { 
			pa[w] = v; 
			dfsRebcc( w); 
			lo[v] = min( lo[v], lo[w]);
		} 
		else if (w != pa[v]) 
			lo[v] = min( lo[v], pre[w]); 
	} 
	if (lo[v] == pre[v]) { 
		int u;
		do {
			u = stk[--sn];
			bcc[u] = id;
		} while (u != v);
		id++;
	}
}

int ebcc() {
	for (int v = 0; v < n; v++) // 0 indexed
		pre[v] = -1;
	sn = clk = id = 0;
	for (int v = 0; v < n; v++)
		if (pre[v] == -1) { 
			pa[v] = v;
			dfsRebcc( v);
		}
	return id;
}

// Monta arvore de BCC
void build_ebcc_graph() {
	for (int v = 0; v < n; v++)
		for (auto x : adj[v])
			if (bcc[v] != bcc[x.fst])
				adjbcc[bcc[v]].push_back({bcc[x.fst], x.snd});
			// ponte vira uma aresta de mesmo custo na árvore
}