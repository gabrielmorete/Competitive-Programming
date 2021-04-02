// Algoritmo de Tarjan para componentes biconexas (bcc)
// complexidade : O(V + E)
//
// Dois vértices u e v estão na mesma bcc se há dois caminhos 
// distintos que ligam u e v ou são vizinhos.
// Cuidado, as ligações entre componentes são vertices de corte
// vertices de corte podem estar em várias componentes
// A árvore das componentes forma a block-cut-tree

#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e5 + 10;

int n, m, clk, id; // id = # de componentes
int pre[MAXN], lo[MAXN], bcc[MAXN]; // bcc[v] é a componente biconexa de v
stack< pair<int, int> > stk;
vector<int> adj[MAXN];

void markcomp(int v, int u){
	if (v > u) swap(u, v);
	int a, b, sz = 0;
	id++;
	do { // cuidado, vertices de ligação podem mudar de componente
		tie(a, b) = stk.top();
		stk.pop();
		if (bcc[a] < id)
			bcc[a] = id, sz++;
		if (bcc[b] < id)
			bcc[b] = id, sz++;
	} while (a != v or b != u);
}	

void dfsbcc(int v, int p){
	lo[v] = pre[v] = clk++;
	for (auto x : adj[v]){
		if (pre[x] == -1){ 
			stk.push({min(v, x), max(v, x)});
			dfsbcc(x, v); 
			
			if (lo[x] >= pre[v]) // achei componente
				markcomp(v, x);
			lo[v] = min(lo[v], lo[x]);
		} 
		else if (x != p and pre[x] < pre[v]){
			stk.push({min(v, x), max(v, x)});
			lo[v] = min(lo[v], pre[x]);
		} 
	} 
}

int findbcc(){
	fill(pre, pre + n + 1, -1);
	fill(bcc, bcc + n + 1, -1);
	clk = id = 0;
	for (int v = 0; v < n; v++) // 0 indexed
		if (pre[v] == -1)
			dfsbcc(v, v);
		
	return id;
}
