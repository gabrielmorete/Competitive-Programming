// Merge sort tree
// Encontra o número de elementos <= k no intervalo [l, r] 
// complexidade:
// 		build : O(nlog(n))
//		query : O(log(n)^2)
//		memória : O(nlog(n)

#include "bits/stdc++.h"
using namespace std;

#define all(x)  x.begin(), x.end()
const int MAXN = 1e5 + 10;

vector<int> v; // vetor de elementos
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
