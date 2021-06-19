// Algoritmo para centoroid decomposition
// Complexidade: O(nlog(n))
// O caminho entre dois vértices da árvore passa pelo lca na
// árvore de centroid. A árvore de centroid tem altura O(log(n)).

const int MAXN = 1e5 + 10;

int n, pai[MAXN], szt[MAXN]; // pai[root] = root
bool blk[MAXN]; // vértice bloqueado
vector<int> adj[MAXN];

int dfs_sz(int v, int p){ // calcula tamanho da subárvore
	szt[v] = 1;
	for (auto x : adj[v])
		if (x != p and !blk[x])
			szt[v] += dfs_sz(x, v);
	return szt[v];	
}

int dfs_decomp(int v, int p = -1, int sz = -1){ // O(nlog(n))
	if (sz < 0)
		sz = dfs_sz(v, v); // tamanho da subárvore, muda quando achamos o centroid
	for (auto x : adj[v])
		if (!blk[x] and szt[x] * 2 >= sz){
			szt[v] = 0; // evita cliclagem
			return dfs_decomp(x, p, sz);
		}
	blk[v] = true;
	pai[v] = (p == -1? v : p);	
	for (auto x : adj[v])
		if (!blk[x])
			dfs_decomp(x, v);
	return v;	
}

int centroid(int r){
	memset(blk, 0, sizeof blk);
	return dfs_decomp(r);
}