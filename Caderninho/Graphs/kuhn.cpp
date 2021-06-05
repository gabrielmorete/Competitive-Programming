// Algoritmo de Kuhn para emparelhamento máximo
// complexidade: 
// 		kuhn O(EV)
// 		min_cover O(V + E)
// Vertices enumerados de 1 a m em U e de 1 a n em V

#include "bits/stdc++.h"
using namespace std;

const int MAXN = 5e2 + 10;
// Em geral, performa mais rápido do que na teoria

vector<int> adju[MAXN];
int matchu[MAXN], matchv[MAXN], coverv[MAXN], coveru[MAXN];
int vis[MAXN], iter;
int m, n;

void min_cover(){
	iter++;
	for (int u = 1; u <= m; u++)
		if (matchu[u] == 0)
			dfs(u);
	for (int u = 1; u <= m; u++){
		coveru[u] = false;
		if (vis[u] < iter)
			coveru[u] = true;	
	}	
	for (int v = 1; v <= n; v++){
		coverv[v] = false;
		if (vis[matchv[v]] == iter)
			coverv[v] = true;
	}	
}

bool dfs(int u){
	vis[u] = iter;
	if (u == 0) return true;
		for (int &v : adju[u]){
			if (vis[matchv[v]] < iter and dfs(matchv[v])){
				matchv[v] = u; 
				matchu[u] = v;
				return true;
			}
		}
	return false;
}

int kuhn(){
	memset(&matchu, 0, sizeof matchu);
	memset(&matchv, 0, sizeof matchv);
	memset(&vis, 0, sizeof vis);
	iter = 0;
	int result = 0;
	for (int u = 1; u <= m; u++){
		iter++;
		if (matchu[u] == 0 and dfs(u)) 
			result++;
	}
	min_cover();
	return result;
}

// baseado em : https://github.com/splucs/Competitive-Programming/tree/master/Macac%C3%A1rio