// Algoritmo para pontes e vertices de corte
// complexidade : O(n + m)

#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e5 + 1;

int clk, n, m;
int pre[MAXN], lo[MAXN], pa[MAXN], cut[MAXN]; // cut[v] = 1 se v é de corte
vector<int> adj[MAXN];
map <pii, bool> bridge; // bridge[{u, v}] = 1 de uv é ponte

void dfsRbc( int v) {
	pre[v] = lo[v] = clk++;
	int chd = 0;
	bool any = false;
	for (auto x : adj[v]) {
		if (pre[x] == -1) {
			chd++;
			pa[x] = v;
			dfsRbc(x);
			lo[v] = min( lo[v], lo[x]);
			if (lo[x] >= pre[v])
				any = true;
			if (lo[x] > pre[v])
				bridge[{v,x}] = bridge[{x,v}] = true;
		}
		else if (x != pa[v])
			lo[v] = min( lo[v], pre[x]);
	}
	if (v == pa[v] and chd >= 2)
		cut[v] = true;
	if (v != pa[v] and any)
		cut[v] = true;
}

void findbc() {
	bridge.clear();
	for (int v = 0; v < n; v++)
		pre[v] = -1, cut[v] = 0;
	clk = 0;
	for (int v = 0; v < n; v++)
		if (pre[v] == -1) {
			pa[v] = v;
			dfsRbc( v);
		}
}