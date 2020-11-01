// Algoritmo para suffix array
//
// complexidade : O(nlog(n))

#include "bits/stdc++.h"
using namespace std;

const int MAXN = 4e5 + 10;

int p[MAXN], c[MAXN], c_new[MAXN], cnt[MAXN], cp[MAXN], lcp[MAXN];
pair<int, int> a[MAXN];

void count_sort(int n){
	fill(cnt, cnt + n, 0);
	for (int i = 0; i < n; i++)
		cnt[c[i] + 1]++;
	for (int i = 1; i < n; i++)
		cnt[i] += cnt[i - 1];
	for (int i = 0; i < n; i++){
		int x = c[p[i]];
		cp[cnt[x]] = p[i];
		cnt[x]++;
	}
	for (int i = 0; i < n; i++)
		p[i] = cp[i];
}

// suffix array está em p, o suffixo vazio é incluido (p[0] = n)
void suffix_array(string &s){
	int n = s.size() + 1;
	for (int i = 0; i < n - 1; i++)
		a[i] = {s[i], i};
	a[n - 1] = {' ', n - 1}; // caractere 32

	sort(a, a + n);

	p[0] = n - 1;
	c[p[0]] = 0;
	for (int i = 1; i < n; i++){
		p[i] = a[i].second;
		c[p[i]] = c[p[i - 1]] + (a[i].first != a[i - 1].first);
	}

	int k = 0;
	while ((1 << k) < n){
		for (int i = 0; i < n; i++)
			p[i] = (p[i] - (1 << k) + n) % n;

		count_sort(n);

		c_new[p[0]] = 0;
		for (int i = 1; i < n; i++){
			int eq = c[p[i - 1]] != c[p[i]];
			eq |= c[(p[i - 1] + (1 << k)) % n] != c[(p[i] + (1 << k)) % n];
			c_new[p[i]] = c_new[p[i - 1]] + eq;
		}
		for (int i = 0; i < n; i++)
			c[i] = c_new[i];	
		k++;
	}

	k = 0;
	for (int i = 0; i < n - 1; i++){ // calcula lcp
		int pi = c[i]; // é a permutação inversa sufixo -> posição
		int j = p[pi - 1];
		while (s[i + k] == s[j + k]) k++;
		lcp[pi - 1] = k; // lcp[i] é entre o sufixo p[i] -> p[i + 1]
		k = max(k - 1, 0);
	}
}
