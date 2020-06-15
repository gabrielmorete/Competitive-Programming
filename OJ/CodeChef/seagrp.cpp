// Edomonds Blosssom
// acha emparelhamento em grafos arbitrarios
// complexidade : O(EV^2)
// arestas são guardadas como uma lista ligada
// adj[v] é a primeira aresta, percorrer até 0 (e = nxt[e])

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110;
int ned = 1, adj[MAXN], to[2 * MAXN * MAXN], nxt[2 * MAXN * MAXN];
int n, m, st, en; // n # de vértices, m # de arestas
int match[MAXN], pai[MAXN], base[MAXN], q[MAXN]; // match[i] = v, (i, v) estão emparelahdos (ou -1)
bool inq[MAXN], inb[MAXN];

void init(){
	ned = 1;
	fill(adj, adj + n, 0);
}

void add_edge(int u, int v){ // adicionar aresta uv
	to[ned] = u, nxt[ned] = adj[v], adj[v] = ned++;
	to[ned] = v, nxt[ned] = adj[u], adj[u] = ned++;	
}

int find_lca(int root, int u, int v){
	static bool inp[MAXN];
	memset(inp, 0, sizeof(inp));
	while (1){
		inp[u = base[u]] = true;
		if (u == root) 
			break;
		u = pai[match[u]];
	}
	while (1){
		if (inp[v = base[v]]) 
			return v;
		v = pai[match[v]];
	}
}

void mark_blossom(int lca, int u) {
	while (base[u] != lca){
		int v = match[u];
		inb[base[u]] = inb[base[v]] = true;
		u = pai[v];
		if (base[u] != lca) 
			pai[u] = v;
	}
}

void blossom_contraction(int s, int u, int v) {
	memset(inb, 0, sizeof(inb));
	int lca = find_lca(s, u, v);
	mark_blossom(lca, u);
	mark_blossom(lca, v);
	if (base[u] != lca)
		pai[u] = v;
	if (base[v] != lca)
		pai[v] = u;
	for (int u = 0; u < n; u++)
		if (inb[base[u]]){
			base[u] = lca;
			if (!inq[u])
				inq[q[en++] = u] = true;
		}
}

void augment_path( int t) {
	int x, w;
	do{
		x = pai[t];
		w = match[x];
		match[x] = t;
		match[t] = x;
		t = w;
	} while (t != -1);
}

bool find_augmenting_path(int s){
	memset(inq, 0, sizeof(inq));
	memset(pai, -1, sizeof(pai));
	for (int i = 0; i < n; i++) 
		base[i] = i;
	st = en = 0;
	q[en++] = s;
	inq[s] = true;
	while (st < en){
		int u = q[st++];
		for (int e = adj[u]; e != 0; e = nxt[e]){
			int v = to[e];
			if (base[u] != base[v] && match[u] != v){
				if ((v == s)||(match[v] != -1 && pai[match[v]] != -1))
					blossom_contraction(s, u, v);
				else if (pai[v] == -1) {
					pai[v] = u;
					if (match[v] == -1){
						augment_path(v);
						return true;
					}
					if (!inq[match[v]])
						inq[q[en++] = match[v]] = true;
				}
			}	
		}
	}
	
	return false;
}

int blossom(){
	int matchc = 0;
	memset(match, -1, sizeof(match));
	for (int v = 0; v < n; v++)
		if (match[v] == -1 && find_augmenting_path(v))
			matchc++;
	return matchc; // cardinalidade do emparelhamento
}

int ed[MAXN][MAXN];

void solve() {
	init();
	memset(ed, 0, sizeof(ed));

	int u, v;
	cin>>n>>m;
	for (int i = 0; i < m; i++){
		cin>>u>>v;
		u--; v--;
		if (!ed[u][v]){
			add_edge(u, v);
			ed[u][v] = ed[v][u] = 1;
		}
	}
	if (2 * blossom() == n)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}
int main(){
	int T;
	cin>>T;
	while (T--)
		solve();
}

// Based (almost a copy) from : https://codeforces.com/blog/entry/49402