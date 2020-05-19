// Algoritmo para 2-SAT
#include "bits/stdc++.h"
using namespace std;

const int MAXN = 4e5 + 10; // Tamanho máximo do grafo

int n;
vector<int> adj[MAXN], adjt[MAXN];
int stk[MAXN], st, scc[MAXN];
bool vis[MAXN], val[MAXN];

void dfs1(int v){
	vis[v] = 1;
	for (int u : adj[v])
		if (!vis[u])
			dfs1(u);
	stk[st++] = v;	
}

void dfs2(int v, int cmp){
	scc[v] = cmp;
	for (int u : adjt[v])
		if (scc[u] == -1)
			dfs2(u, cmp);
}

bool sat(){
	fill(val, val + n, 0);
	fill(vis, vis + n, 0);
	fill(scc, scc + n, -1);
	st = 0;

	for (int i = 0; i < n; i++)
		if (!vis[i])
			dfs1(i);

	int v, cmp = 0;	
	while (st > 0){
		v = stk[--st];
		if (scc[v] == -1)
			dfs2(v, cmp++);
	}

	for (int i = 0; i < n; i += 2){
		if (scc[i] == scc[i + 1]) // i = true | i + 1 = false
			return false;
		val[i/2] = scc[i] > scc[i + 1]; // scc[!a] < scc[a] => true
	}	
	return true;			
}

void clear(){
	for (int i = 0; i < n; i++)
		adj[i].clear(), adjt[i].clear();
}

void add(int a, int b){
	adj[a].push_back(b);
	adjt[b].push_back(a);
}

// n é o número de vertices
// SEJA CUIDADOSO COM n (dobras de valor), lembre-se que
// toda variável tem vértices : 2k (true) e 2k + 1(false)
// o valor da variável está em val
// LIMPE adj e adjt entre CASOS TESTE
// O(n + m) 