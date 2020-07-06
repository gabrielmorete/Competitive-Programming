// DSU Persistente
// garda o tempo que os vértices se uniram
// complexidade:
// 	find O(log(n))
// 	merge O(log(n))
// 	get_time O(log(tempo)log(n))	

#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e6 + 10;

int id[MAXN], sz[MAXN], his[MAXN]; // his[v] é o tempo que v virou filho

void init(){
	for (int i = 0; i < MAXN; i++){
		id[i] = i;
		sz[i] = 1;
	    his[i] = 0; // todos disjuntos no tempo zero
	}
}

int find(int a, int t){ // Retorna id[a] no tempo t
	if (id[a] == a or his[a] > t) 
		return a;
	return find(id[a], t); // Não pode usar path compression
}

void merge(int a, int b, int t){
	a = find(a, t);
	b = find(b, t);
	if (a == b)
		return;
	if (sz[a] < sz[b])
		swap(a, b);
	his[b] = t;
	sz[a] += sz[b];
	id[b] = a;
}

int get_time(int a, int b){ // Retorna o tempo em que a uniu com b
	int bst, l, r, meio;
	l = 1;
	r = bst = MAXN;

	while (l <= r){
		meio = (l + r)/2;
		if (find(a, meio) != find(b, meio))
			l = meio + 1;
		else{
			r = meio - 1;
			bst = meio;
		}
	}
	return bst;
}
