#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

#define endl '\n'
#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(), x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;

template<typename T = int> struct mcmf {
	struct edge {
		int to, rev, flow, cap; // para, id da reversa, fluxo, capacidade
		bool res; // se eh reversa
		T cost; // custo da unidade de fluxo
		edge() : to(0), rev(0), flow(0), cap(0), cost(0), res(false) {}
		edge(int to_, int rev_, int flow_, int cap_, T cost_, bool res_)
			: to(to_), rev(rev_), flow(flow_), cap(cap_), res(res_), cost(cost_) {}
	};

	vector<vector<edge>> g;
	vector<int> par_idx, par;
	T inf;
	vector<T> dist;

	mcmf(int n) : g(n), par_idx(n), par(n), inf(numeric_limits<T>::max()/3) {}

	void add(int u, int v, int w, T cost) { // de u pra v com cap w e custo cost
		edge a = edge(v, g[v].size(), 0, w, cost, false);
		edge b = edge(u, g[u].size(), 0, 0, -cost, true);

		g[u].push_back(a);
		g[v].push_back(b);
	}

	void get(int &to, int &rev, int &flow, int &cap, bool &res, T &cost, edge &e){
		to = e.to;rev = e.rev; flow = e.flow; cap = e.cap; res = e.res; cost = e.cost;
	}

	vector<T> spfa(int s) { // nao precisa se nao tiver custo negativo
		deque<int> q;
		vector<bool> is_inside(g.size(), 0);
		dist = vector<T>(g.size(), inf);

		dist[s] = 0;
		q.push_back(s);
		is_inside[s] = true;

		while (!q.empty()) {
			int v = q.front();
			q.pop_front();
			is_inside[v] = false;

			for (int i = 0; i < g[v].size(); i++) {
				int to, rev, flow, cap; // para, id da reversa, fluxo, capacidade
				bool res; // se eh reversa
				T cost; // custo da unidade de fluxo
				get(to, rev, flow, cap, res, cost, g[v][i]);
				if (flow < cap and dist[v] + cost < dist[to]) {
					dist[to] = dist[v] + cost;

					if (is_inside[to]) continue;
					if (!q.empty() and dist[to] > dist[q.front()]) q.push_back(to);
					else q.push_front(to);
					is_inside[to] = true;
				}
			}
		}
		return dist;
	}
	bool dijkstra(int s, int t, vector<T>& pot) {
		priority_queue<pair<T, int>, vector<pair<T, int>>, greater<>> q;
		dist = vector<T>(g.size(), inf);
		dist[s] = 0;
		q.emplace(0, s);
		T d;
		int v;
		while (q.size()) {
			tie(d, v) = q.top();
			q.pop();
			if (dist[v] < d) continue;
			for (int i = 0; i < g[v].size(); i++) {
				int to, rev, flow, cap; // para, id da reversa, fluxo, capacidade
				bool res; // se eh reversa
				T cost; // custo da unidade de fluxo
				get(to, rev, flow, cap, res, cost, g[v][i]);				
				cost += pot[v] - pot[to];
				if (flow < cap and dist[v] + cost < dist[to]) {
					dist[to] = dist[v] + cost;
					q.emplace(dist[to], to);
					par_idx[to] = i, par[to] = v;
				}
			}
		}
		return dist[t] < inf;
	}

	pair<int, T> min_cost_flow(int s, int t, int flow = INF) {
		vector<T> pot(g.size(), 0);
		dijkstra(s, t, pot); // mudar algoritmo de caminho minimo aqui
		// pot = spfa(s);
		int f = 0;
		T ret = 0;
		while (f <= flow and dijkstra(s, t, pot)) {
			for (int i = 0; i < g.size(); i++)
				if (dist[i] < inf) pot[i] += dist[i];

			int mn_flow = flow - f, u = t;
			while (u != s){
				mn_flow = min(mn_flow,
					g[par[u]][par_idx[u]].cap - g[par[u]][par_idx[u]].flow);
				u = par[u];
			}

			ret += pot[t] * mn_flow;

			u = t;
			while (u != s) {
				g[par[u]][par_idx[u]].flow += mn_flow;
				g[u][g[par[u]][par_idx[u]].rev].flow -= mn_flow;
				u = par[u];
			}

			f += mn_flow;
		}

		return make_pair(f, ret);
	}

	// Opcional: retorna as arestas originais por onde passa flow = cap
	vector<pair<int,int>> recover() {
		vector<pair<int,int>> used;
		for (int i = 0; i < g.size(); i++) for (edge e : g[i])
			if(e.flow == e.cap && !e.res) used.push_back({i, e.to});
		return used;
	}
};




int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, freq[30];
	string t;

	cin>>t>>n;

	int src = 0;
	int snk = 30 *(n + 10) + 1;

	memset(freq, 0, sizeof freq);
	fr(i, t.size())
		freq[t[i] - 'a']++;

	int cnt = n + 1;

	map<pii, int> edg;
	
	fr(i, 26)
		edg[{n + 1, i}] = cnt++;
	
	mcmf<> flow(snk + 1);

	fr(i, 26)
		if (freq[i] > 0)
			flow.add(edg[{n + 1, i}], snk, freq[i], 0);

	int cst;	
	string s;	
	frr(i, n){
		cin>>s>>cst;
		flow.add(src, i, cst, i);

		fr(j, 26)
			edg[{i, j}] = cnt++;

		memset(freq, 0, sizeof freq);
		fr(j, s.size())
			freq[s[j] - 'a']++;

		fr(j, 26)
			if (freq[j] > 0){
				flow.add(i, edg[{i, j}], freq[j], 0);
				flow.add(edg[{i, j}], edg[{n + 1, j}], INF, 0);
			}
	}					

	pii res = flow.min_cost_flow(src, snk);

	if (res.fst == t.size())
		cout<<res.snd<<endl;
	else
		cout<<-1<<endl;
}