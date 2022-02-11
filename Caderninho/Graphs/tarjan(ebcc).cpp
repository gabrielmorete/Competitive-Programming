// Algoritmo de Tarjan para componentes aresta-biconexas (ebcc)
// complexidade : O(n + m)
//
// Dois vértices u e v estão na mesma ebcc se há 
// dois caminhos sem arestas em comum que ligam u e v (repete vertice)
// Toda ebcc é conexa e toda aresta dessa pertence a algum circuito

int n, m, sn, clk, id;
int pre[MAXN], lo[MAXN], stk[MAXN], ebcc[MAXN]; // ebcc[v] é a componente biconexa de v
vector<int> adj[MAXN], adjbcc[MAXN];

void dfs_ebcc(int v, int p){
	lo[v] = pre[v] = clk++;
	stk[sn++] = v;

	for (auto x : adj[v]){
		if (pre[x] == -1){ 
			dfs_ebcc(x, v); 
			lo[v] = min(lo[v], lo[x]);
		} 
		else if (x != p) 
			lo[v] = min(lo[v], pre[x]); 
	} 
	if (lo[v] == pre[v]){ 
		int u;
		do {
			u = stk[--sn];
			ebcc[u] = id;
		} while (u != v);
		id++;
	}
}

int findebcc(){
	fill(pre, pre + n + 1, -1);
	sn = clk = id = 0;
	for (int v = 0; v < n; v++) // 0 indexed
		if (pre[v] == -1)
			dfs_ebcc(v, v);
		
	return id;
}

// Monta a árvore de BCC
void build_ebcc_graph() {
	for (int v = 0; v < n; v++)
		for (auto x : adj[v])
			if (ebcc[v] != ebcc[x])
				adjbcc[ebcc[v]].push_back(ebcc[x]);
}