// Algoritmo para 2-SAT
//
// SEJA CUIDADOSO com n (dobras de valor), lembre-se que
// toda variável k tem vértices : 2k (true) e 2k + 1(false)
// complexidade : O(n + m) 

#include "bits/stdc++.h"
using namespace std;

const int MAXN = 4e5 + 10;

int n; // # de vertices
vector<int> adj[MAXN], adjt[MAXN];
int stk[MAXN], st, scc[MAXN];
bool vis[MAXN], val[MAXN]; // val[k] é o valor de k

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

void init(){ // LIMPE o grafo
	for (int i = 0; i < n; i++)
		adj[i].clear(), adjt[i].clear();
}

void add(int a, int b){
	adj[a].push_back(b);
	adjt[b].push_back(a);
}