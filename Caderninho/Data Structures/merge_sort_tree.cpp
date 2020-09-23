// Merge sort tree
// Encontra o número de elementos <= k no intervalo [l, r] 
// Encontra o k-ésimo elemento no intervalo [l, r] 
// complexidade:
// 		build 	  :	O(nlog(n))
//		query 	  : O(log(n)^2)
//		query_kth : O(log(n)^2) 
//		memória	  : O(nlog(n)

#include "bits/stdc++.h"
using namespace std;

#define all(x)  x.begin(), x.end()
const int MAXN = 1e5 + 10;

int v[MAXN]; // vetor de elementos (vetor de pair para kth-element)
vector<int> tree[4 * MAXN];

void build(int node, int l, int r){
	if (l == r) return tree[node].push_back(v[l]);
	int meio = (l + r)/2;
	build(node<<1, l, meio); 
	build(node<<1|1, meio + 1, r);
	std::merge(all(tree[node<<1]), all(tree[node<<1|1]), back_inserter(tree[node]));
}

// query(1, 1(0), n(n-1), ql, qr, val) devolve o # elementos <= val em v[l:r]
int query(int node, int l, int r, int ql, int qr, int val){
	if (qr < l or r < ql) return 0;
	if (ql <= l and r <= qr) 
		return lower_bound(all(tree[node]), val + 1) - tree[node].begin();
	int meio = (l + r)/2;
	return query(node<<1, l, meio, ql, qr, val) + query(node<<1|1, meio + 1, r, ql, qr, val);
}

// Para consultar k-ésimo elemento em [l:r] modifique a build com
// if (l == r) return tree[node].push_back(v[l].snd);
// em que v = {valor, indice} é um vetor ordenado contendo os
// elementos do vetor original e seus indices originais.
// A função retorna a posição original do k-ésimo elemento e não
// o seu valor.

#error ordene o vetor {valor, indice}	
// query_kth(1, 1(0), n(n-1), ql, qr, val) devolve o k-ésimo elemento em v[l:r]
int query_kth(int node, int l, int r, int ql, int qr, int val){
	if (l == r)	return tree[node][0]; // posição original do k-ésimo elemento
	int fst = lower_bound(all(tree[node<<1]), ql) - tree[node<<1].begin(); // filho esquerdo
	int lst = lower_bound(all(tree[node<<1]), qr + 1) - tree[node<<1].begin();
	int meio = (l + r)/2;
	int amnt = lst - fst; // # de elementos no filho esquerdo
	if (amnt >= val) // val está no filho esquerdo
		return query_kth(node<<1, l, meio, ql, qr, val);
	else
		return query_kth(node<<1|1, meio + 1, r, ql, qr, val - amnt);
}
