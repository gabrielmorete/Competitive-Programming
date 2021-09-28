// Fenwick Tree
// Computa o valor de uma função reversível no intervalo
// Complexidade : O(log(n)) (tudas as operações)

#include "bits/stdc++.h"
using namespace std;

struct fenwic{
	int n;
	vector<int> bit;

	fenwic (int _n){
		n = _n + 1;
		bit.resize(n + 1);
		fill(bit.begin(), bit.end(), 0);
	}

	void modfy(int p, int val){
		for (p++; p <= n; p += (p & -p))
			bit[p] += val;		
	}

	void modfy(int r, int l, int val){ modfy(r + 1, -val); modfy(l, val);}

	int query(int p){
		int res = 0;
		for (p++; p > 0; p -= (p & -p))
			res += bit[p];
		return res;
	}

	int query(int l, int r){return query(r) - query(l - 1);}
};