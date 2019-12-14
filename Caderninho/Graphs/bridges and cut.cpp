//Code for bridges and cut vertex

#include "bits/stdc++.h"
using namespace std;

//vertex input size
const int MAXN = 100100;

vector<int> adj[MAXN];
int pre[MAXN], lo[MAXN], pa[MAXN], cut[MAXN];
int clk, n, m;
map <pii, bool> bridge;

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