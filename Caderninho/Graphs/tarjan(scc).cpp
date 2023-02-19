// Algoritmo de Tarjan para componentes fortemente conexas (scc)
// complexidade : O(n + m)
//
// Vértices u e v estão na mesma compoente se há caminho u->v e v->u

#include "bits/stdc++.h"
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 10;

int n, clk, sn, id;
int pre[MAXN], lo[MAXN], stk[MAXN], scc[MAXN]; // scc[v] é a componente forte de v
vector<int> adj[MAXN], adjscc[MAXN];

void dfs_scc(int v){
	pre[v] = lo[v] = clk++;
	stk[sn++] = v;
	for (auto x : adj[v]){
		if (pre[x] == -1)
			dfs_scc(x);
		lo[v] = min(lo[v], lo[x]);
	}
	if (lo[v] == pre[v]){
		int u;
		do {
			u = stk[--sn];
			scc[u] = id;
			lo[u] = INF;
		} while (u != v);
		id++;
	}
}

int findscc(){
	fill(pre, pre + n + 1, -1);
	clk = sn = id = 0;
	for (int v = 0; v < n; v++) // 0 indexed
		if (pre[v] == -1)
			dfs_scc(v);
	return id;	
}

// constoi DAG das scc
void build_scc_graph(){
	for (int v = 0; v < n; v++)
		for (auto x : adj[v])
			if (scc[v] != scc[x])
				adjscc[scc[v]].push_back(scc[x]);
}