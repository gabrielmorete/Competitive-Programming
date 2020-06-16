// Algoritmo para lca
// usa sparse table, memo[v][i] é 
// o acentral a distancia 2^i de v
// complexidade:
// build_lca O(nlog(n))
// query_lca O(log(n))

#include<bits/stdc++.h>
const int MAXN = 1e5 + 10;
const int LMAXN = 25; //log2(MAXN)

int n, hgt[MAXN], memo[MAXN][LMAXN]; 
bool vis[MAXN]; 
vi adj[MAXN]; 

void dfs_lca(int v){
	vis[v] = 1; 
	for (auto x : adj[v]){
		if (vis[x]) 
			continue;
		hgt[x] = hgt[v] + 1; 
		memo[x][0] = v; 
		for (int i = 1; i < LMAXN; i++) 
			memo[x][i] = memo[memo[x][i-1]][i-1];
		dfs_lca(x);
	}
}

void build_lca(){
	for (int i = 0; i < LMAXN; i++) 
		memo[1][i]=1;
	dfs_lca(1); 
}

int find_lca(int a, int b){
	if (hgt[a] < hgt[b])
		swap(a, b); 
	for (int i = LMAXN - 1; i >= 0; i--) // equilibra os vértices
		if (hgt[memo[a][i]] >= hgt[b])
			a = memo[a][i];
	if (a == b) 
		return a; 
	for (int i = LMAXN - 1; i >= 0; i--) // sobe junto
		if (memo[a][i] != memo[b][i]){
			a = memo[a][i];
			b = memo[b][i];
		}
	return memo[a][0]; // para imediatamente antes do lca
}