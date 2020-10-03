// PD para árvore de Steiner
// complexidade : O(2**n * n**2 + 3**n * n)

#include "bits/stdc++.h"
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e3 + 10;
const int NTERM = 10;

int memo[1<<NTERM][MAXN]; // memo[mask][v] custo da árvore de steiner
			  // conectando vértices da mask com raiz v

int steiner_pd(){
	memset(memo, INF, sizeof memo);

	// aqui consideramos que o primeiros k nós são terminais

	for (int v = 0; v < n; v++) // valores iniciais, árvores triviais
		for (int t = 0; t < nterm; t++)
			memo[1<<t][v] = dist(v, t); // distancia entre v e t
	
	// se quiser que os terminais sejam folhas basta iterar a partir de k
	// e não de zero, isto é, "não considerar" o terminal como um nó do grafo	
 
	for (int mask = 1; mask < (1 << k); mask++){ // terminimais que vamos conectar
		for (int v = 0; v < n; v++){ // raiz
			for (int smask = (mask - 1) & mask; smask > 0; smask = (smask - 1) & mask) // percorre todas submasks
				memo[mask][v] = min(memo[mask][v], memo[smask][v] + memo[mask ^ smask][v]);
 
			for (int u = 0; u < n; u++) // resposta melhor para u, ligando com v
				memo[mask][u] = min(memo[mask][u], memo[mask][v] + dist(u, v));
		}

	int ans = *get_min(memo[(1<<k) - 1], memo[(1<<k) - 1] + n); // menor custo que conecta todos os terminais

	return ans;	
}
