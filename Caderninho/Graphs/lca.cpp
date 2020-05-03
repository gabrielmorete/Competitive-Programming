#include<bits/stdc++.h>
#define MAXN 101000 //Size of the graph
#define LMAXN 25  //log2(MAXN)

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

		for (int i = 1;i < LMAXN; i++) 
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

	for (int i = LMAXN - 1; i >= 0; i--)
		if (hgt[memo[a][i]] >= hgt[b])
			a = memo[a][i];

	if (a == b) 
		return a; 

	for (int i = LMAXN - 1; i >= 0; i--)
		if (memo[a][i] != memo[b][i]){
			a = memo[a][i];
			b = memo[b][i];
		}

	return memo[a][0];
}