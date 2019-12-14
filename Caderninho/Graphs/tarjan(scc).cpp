// Tarjan's algorithm for SCC
#include "bits/stdc++.h"
using namespace std;

const int INF = 0x3f3f3f3f;

// vertex input size
const int MAXN = 100100;

vector<int> adj[MAXN], adjscc[MAXN];
int pre[MAXN], lo[MAXN], stk[MAXN], scc[MAXN];
int clk, sn, id;
int n;

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

// Compute scc[], scc[v] is the strong connected component that contain v
int tarjan() {
	for (int v = 0; v < n; v++)
		pre[v] = -1;
	clk = sn = id = 0;
	for (int v = 0; v < n; v++)
		if (pre[v] == -1)
			dfsRscc( v);
	return id;	
}

// Build scc graph
void build_scc_graph() {
	for (int v = 0; v < n; v++)
		for (auto x : adj[v])
			if (scc[v] != scc[x])
				adjscc[scc[v]].push_back(scc[x]);
}