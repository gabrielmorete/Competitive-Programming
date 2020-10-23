// Algoritmo de Gusfield para árvore de Gomory-Hu
// Gera uma árvore de fluxo equivalente
// Complexidade : O((n - 1)(max_flow))
// 		em que (max_flow) é a complexidade do algoritmo	
//		de maxflow

#include "bits/stdc++.h"
using namespace std;

int n, m;
int back_cap[MAXM]; // backup da capacidade
int pai[MAXN], fpai[MAXN], mflow[MAXN][MAXN]; // tree
int cuts[MAXN];

void find_cut(int v){ // constroi o corte
	cuts[v] = true;
	for (int e = first[v]; e != -1; e = nxt[e])
		if (!cuts[to[e]] and cap[e] > 0)
			find_cut(to[e]);
}

int min_cut(int s, int t){
	memset(cuts, 0, sizeof cuts);
	memcpy(cap, back_cap, sizeof cap);

	int flow = dinic(s, t); // qualquer algoritmo de fluxo
	find_cut(s);			// que computa uma rede residual
							// basta acoplar o dinic desse caderno
	return flow;
}

void gomory_hu(){
	memset(mflow, -1, sizeof mflow); // -1 não tem corte que separa
	memcpy(back_cap, cap, sizeof cap);
	fill(pai, pai + n + 1, 1); // começa com k_{1, n - 1}

	for (int s = 2; s <= n; s++){
		int t = pai[s];
		fpai[s] = min_cut(s, t);
		
		mflow[s][t] = mflow[t][s] = fpai[s];

		for (int v = s + 1; v <= n; v++)
			if (cuts[v] and pai[v] == t)
				pai[v] = s;

		for (int v = 1; v < s; v++)
			if (mflow[s][v] == -1)
				mflow[s][v] = mflow[v][s] = min(mflow[s][t], mflow[t][v]);
	}
}

// Na árvore de Gomory-Hu a menor aresta no caminho entre u e v
// é o valor do fluxo máximo entre esses vértices em G
