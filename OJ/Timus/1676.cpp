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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 2e3 + 10;

vector<int> adju[MAXN]; // adj da partição U
int matchu[MAXN], matchv[MAXN]; 
int dist[MAXN], q[MAXN];
int m, n;

bool bfs(){
	int st = 0, en = 0;
	for (int u = 1; u <= m; u++){
		if (matchu[u] == 0){
			dist[u] = 0; 
			q[en++] = u;
		}
		else dist[u] = INF;
	}
	dist[0] = INF;
	while (en > st){
		int u = q[st++];
		if (dist[u] >= dist[0]) 
			continue;
		for (int v : adju[u]){
			if (dist[matchv[v]] == INF){
				dist[matchv[v]] = dist[u] + 1;
				q[en++] = matchv[v];
			}
		}
	}

	return (dist[0] != INF);
}

bool dfs(int u){
	if (u == 0) return true;
	for (int v : adju[u]){
		if (dist[matchv[v]] == dist[u] + 1){
			if (dfs(matchv[v])){
				matchv[v] = u; 
				matchu[u] = v;
				return true;
			}
		}
	}
	dist[u] = INF;
	return false;
}

int hopcroftKarp(){
	memset(&matchu, 0, sizeof matchu);
	memset(&matchv, 0, sizeof matchv);
	int result = 0;
	while (bfs()){
		for (int u = 1; u <= m; u++){
			if (matchu[u] == 0 and dfs(u))
				result++;
		}
	}
	return result;
}

bool ans[301][MAXN]; // marca se aresta está em um emparelhamento

int clk, sn, id;
int pre[MAXN], lo[MAXN], stk[MAXN], scc[MAXN]; // scc[v] é a componente forte de v
vector<int> adj[MAXN];

void dfsRscc( int v) {
	pre[v] = lo[v] = clk++;
	stk[sn++] = v;
	for (auto x : adj[v]) {
		if (pre[x] == -1)
			dfsRscc( x);
		lo[v] = min( lo[v], lo[x]);
	}
	if (lo[v] == pre[v]) {
		int u;
		do {
			u = stk[--sn];
			scc[u] = id;
			lo[u] = INF;
		} while (u != v);
		id++;
	}
}

int tarjan() { // acha componente fortemente conexa
	for (int v = 1; v <= MAXN; v++)
		pre[v] = -1;
	clk = sn = id = 0;
	for (int v = 1; v <= MAXN; v++)
		if (pre[v] == -1)
			dfsRscc( v);
	return id;	
}

int vis[MAXN];
void dfs_p(int v){ // acha caminhos alternantes pares
	vis[v] = 1;
	for (int x : adj[v]){
		if (v > m)
			ans[v - m][x] = 1;
		else
			ans[x - m][v] = 1;

		if (vis[x] == 0)
			dfs_p(x);
	}
}

int32_t main(){
	fastio;
	cin>>n>>m; // n - mosntros, m - humanos

	string s;
	frr(v, n){
		cin>>s;
		frr(u, m)
			if (s[u - 1] == '1')
				adju[u].pb(v); // emparelhar a partir dos humanos
	}

	if(hopcroftKarp() < n){ // emparelhamento cobre os monstros
		frr(v, n){
			frr(u, m)
				cout<<1;
			gnl;	
		}
		return 0;
	}

	frr(u, m)
		for (int v : adju[u]) // direcionando grafo, reverte arestas emparelhadas
			if (v == matchu[u]){
				ans[v][u] = 1;
				adj[v + m].pb(u);
			}
			else
				adj[u].pb(v + m);

	tarjan(); // detecta circuitos alternantes
	frr(u, m)
		for (int v : adju[u])
			if (scc[u] == scc[v + m]) // marca aresta do circuito alternante
				ans[v][u] = 1;

	frr(u, m)
		if (matchu[u] == 0 and vis[u] == 0) // vertice solteiro
			dfs_p(u); // pega caminho alternante par
	frr(v, n)
		if (matchv[v] == 0 and vis[v] == 0)
			dfs_p(v);

	frr(v, n){
		frr(u, m)
			cout<<!ans[v][u];
		gnl;							
	}
}