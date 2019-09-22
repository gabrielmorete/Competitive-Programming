#include "bits/stdc++.h"
using namespace std;

//vertex input size
const int MAXN = 100100;

vector< pair<int,int> > adj[MAXN], adjbcc[MAXN];
int pre[MAXN], lo[MAXN], pa[MAXN], stk[MAXN];
int n, m;
int t, cnt, id;
int bcc[MAXN];

void dfsRebcc( int v) {
	pre[v] = cnt++;
	stk[t++] = v;
	lo[v] = pre[v];
	for (pair<int,int> x : adj[v]) {
		int  w = x.fst;
		if (pre[w] == -1) { 
			pa[w] = v; 
			dfsRebcc( w); 
			if (lo[w] < lo[v]) 
			lo[v] = lo[w]; 
			} else { 
		if (w != pa[v] && pre[w] < lo[v]) 
			lo[v] = pre[w]; 
		} 
	} 
		if (lo[v] == pre[v]) { 
			int u;
		do {
			u = stk[--t];
			bcc[u] = id;
		} while (u != v);
	id++;
	}
}
// compute the array bcc[], bcc[v] is the biconnected component that contain v
int ebcc( ) {
   for (int v = 0; v < MAXN; ++v)
      pre[v] = -1;
   t = cnt = id = 0;
   for (int v = 1; v < MAXN; ++v)
      if (pre[v] == -1) { 
         pa[v] = v;
         dfsRebcc( v);
      }
   return id;
}
//build the graph of biconnected components
void build_ebcc_graph() {
	for (int v = 0; v < n; v++)
		for (pair<int,int> x : adj[v]){
			if (bcc[v] != bcc[x.fst])
				adjbcc[bcc[v]].push_back({bcc[x.fst], x.snd});
			//A bridge becomes an edge with the same cost in the new graph
	}
}

//Inspiration and Credits : https://www.ime.usp.br/~pf/algoritmos_para_grafos/index.html