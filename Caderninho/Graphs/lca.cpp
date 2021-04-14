// Algoritmo para manor ancestral comum em arvore
// complexidade:
// 		build_lca O(nlog(n))
// 		query_lca O(log(n))

const int MAXN = 5e5 + 10;
const int LMAXN = 25; //log2(MAXN)

// memo[v][i] é o acentral a distancia 2^i de v
int hgt[MAXN], memo[MAXN][LMAXN]; 
vector<int> adj[MAXN];

void dfs_lca(int v, int p){
	for (auto x : adj[v])
		if (x != p){ 
			hgt[x] = hgt[v] + 1; 
			memo[x][0] = v; 
			for (int i = 1; i < LMAXN; i++) 
				memo[x][i] = memo[memo[x][i - 1]][i - 1];
			dfs_lca(x, v);
		}
}

void build_lca(int r){ // enraizado em r
	fill(memo[r], memo[r] + LMAXN, r);
	dfs_lca(r, r); 
}

int find_lca(int a, int b){
	if (hgt[a] < hgt[b])
		swap(a, b); 
	for (int i = LMAXN - 1; i >= 0; i--) // equilibra os vértices
		if (hgt[memo[a][i]] >= hgt[b])
			a = memo[a][i];
	if (a == b) 
		return a; 
	for (int i = LMAXN - 1; i >= 0; i--) // sobe junto
		if (memo[a][i] != memo[b][i]){
			a = memo[a][i];
			b = memo[b][i];
		}
	return memo[a][0]; // para imediatamente antes do lca
}
