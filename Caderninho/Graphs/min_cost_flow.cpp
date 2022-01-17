// Algoritmo para Min Cost Flow
// Complexidade O(nm + f * m log n)
// min_cost_flow(s, t, f) computa o par (fluxo, custo)
// com max(fluxo) <= f que tenha min(custo)
// Se G é um DAG, pode usar uma PD no lugar no Bellman
// Para maximizar, negue os custos

const int INF =  0x3f3f3f3f; // MUDE se ll
const int MAXN = 1e3 + 10;
const int MAXM = 4e3 + 10;
using tcst = int; // tipo de custo
using tflw = int; // tipo de fluxo

int ned, to[MAXM], nxt[MAXM], first[MAXM]; 
int N, is_in[MAXN], pre[MAXN];
tflw cap[MAXM];  
tcst cost[MAXM], dist[MAXN], pot[MAXN];

void init(int n){
	N = n;
	fill(first, first + N, -1);
	ned = 0;
}

void add(int u, int v, tflw f, tcst c){ // de u pra v com cap f e custo c
	to[ned] = v, cap[ned] = f, cost[ned] = c;
	nxt[ned] = first[u];
	first[u] = ned++;
	
	to[ned] = u, cap[ned] = 0, cost[ned] = -c;
	nxt[ned] = first[v];
	first[v] = ned++;
} // arestas reversas são impares

void bellman(int s) { // nao precisa se nao tiver custo negativo
	fill(dist, dist + N, INF);
	fill(is_in, is_in + N, 0);

	queue<int> fila;
	fila.push(s);
	dist[s] = 0;
	is_in[s] = true;

	while (!fila.empty()){
		int u = fila.front();
		fila.pop();
		is_in[u] = false;
	
		for (int e = first[u]; e != -1; e = nxt[e]){
			int v = to[e];
			if (cap[e] > 0 and dist[u] + cost[e] < dist[v]){
				dist[v] = dist[u] + cost[e];

				if (!is_in[v]){
					fila.push(v);
					is_in[v] = true;
				}
			}
		}
	}
	for (int i = 0; i < N; i++) 
		pot[i] = (dist[i] < INF? dist[i] : 0);
}

bool dijkstra(int s, int t){
	priority_queue<pair<tcst, int>, vector<pair<tcst, int>>, greater<pair<tcst, int>>> pq;
	fill(dist, dist + N, INF);
	pq.emplace(0, s);
	dist[s] = 0;
	tcst dst;
	int u;
	while (!pq.empty()){
		tie(dst, u) = pq.top();
		pq.pop();

		if (dst <= dist[u]){
			for (int e = first[u]; e != -1; e = nxt[e]){
				int v = to[e];
				tcst ndst = dst + cost[e] + pot[u] - pot[v];			
				if (cap[e] > 0 and ndst < dist[v]){
					dist[v] = ndst;
					pq.emplace(ndst, v);
					pre[v] = e;
				}
			}
		}				
	}
	return dist[t] < INF;
}

pair<tflw, tcst> min_cost_flow(int s, int t, tflw flow = INF) {
	fill(pot, pot + N, 0);	
	bellman(s); // se os custos são positivos, é desnecessário pot = 0

	tflw f = 0;
	tcst val = 0;
	while (f < flow and dijkstra(s, t)){
		for (int i = 0; i < N; i++) 
			pot[i] += (dist[i] < INF? dist[i] : 0);

		tflw df = flow - f; 
		for (int u = t; u != s; u = to[pre[u] ^ 1])
			df = min(df, cap[pre[u]]);

		// para min cust free flow, faça somente pot[t] < 0
		val += pot[t] * df;

		for (int u = t; u != s; u = to[pre[u] ^ 1]){
			cap[pre[u]] -= df;
			cap[pre[u] ^ 1] += df;
		}

		f += df;
	}

	return make_pair(f, val);
}
