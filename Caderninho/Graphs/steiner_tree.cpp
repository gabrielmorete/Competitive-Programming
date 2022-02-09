// PD para árvore de Steiner
// complexidade : O((2**n) * (n**2) + (3**n) * n)
// Computa o menor custo de conectar todos os subconjuntos de
// termais. Podemos utilizar isso e uma pd para calcular uma 
// floresta de steiner

#include "bits/stdc++.h"
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e3 + 10;
const int NTERM = 10;

int stein[1<<NTERM][MAXN]; // stein[mask][v] custo da árvore de steiner
			  // conectando vértices da mask com raiz v

int steiner_pd(){
	memset(stein, INF, sizeof stein);

	// aqui consideramos que o primeiros nterm nós são terminais
	// no caso geral, lembre de mapear o terminal para o nó no grafo

	for (int v = 0; v < n; v++) // valores iniciais, árvores triviais
		for (int t = 0; t < nterm; t++)
			stein[1<<t][v] = dist(v, t); // distancia entre v e o terminal t
	
	// se os terminais precisarem ser folhas, basta ignorar o "vertice real" de 
	// cada terminal e iterar somente sobre os demais vertices nas linas 20 e 29 e 33.
 
	for (int msk = 1; msk < (1 << nterm); msk++) // terminimais que vamos conectar
		for (int v = 0; v < n; v++){ // raiz
			for (int smsk = (msk - 1)&msk; smsk > 0; smsk = (smsk - 1) & msk)
				stein[msk][v] = min(stein[msk][v], stein[smsk][v] + stein[msk^smsk][v]);
			for (int u = 0; u < n; u++) // resposta melhor para u, ligando com v
				stein[msk][u] = min(stein[msk][u], stein[msk][v] + dist(u, v));	
		}	

	int ans = *min_element(stein[(1<<k) - 1], stein[(1<<k) - 1] + n); // menor custo que conecta todos os terminais

	return ans;	
}
