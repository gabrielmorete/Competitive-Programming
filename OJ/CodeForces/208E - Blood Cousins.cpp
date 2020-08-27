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

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;
const int LMAXN = 25;

int n, m;
int ans[MAXN];

vi  adj[MAXN], root;
vii qry[MAXN], qryt[MAXN];

stack<int> vis;
int lca[MAXN][LMAXN];

int sz[MAXN], dpt[MAXN], in[MAXN], out[MAXN], rt[MAXN], clk;
void dfs_sz(int v, int p = -1){
	vis.push(v);
	sz[v] = 1;
	in[v] = clk;
	rt[clk++] = v;
	for (auto &x : adj[v]){
		if (x != p){
			dpt[x] = dpt[v] + 1;
			
			lca[x][0] = v; // monta sparse table
			for (int i = 1; i < LMAXN; i++) 
				lca[x][i] = lca[lca[x][i-1]][i-1];
			
			dfs_sz(x, v);
			sz[v] += sz[x];
			if (sz[x] > sz[adj[v][0]] or adj[v][0] == p)
				swap(x, adj[v][0]);
		}
	}
	out[v] = clk - 1;
}

int freq[MAXN];

void dfs(int v, int p = -1, bool keep = 0){ // conta número de filhos a distancia d
	int bc = adj[v].size() > 1 ? adj[v][0] : -1;

	for (int u : adj[v])
		if (u != p and u != bc)
			dfs(u, v);
	
	if (bc != -1)
		dfs(bc, v, 1);	

	int k;
	for (int u : adj[v])
		if (u != p and u != bc){
			for (int x = in[u]; x <= out[u]; x++){
				k = rt[x];
				freq[dpt[k]]++;	
			}
		}

	freq[dpt[v]]++;	

	for (auto x : qry[v])
		ans[x.snd] = freq[dpt[v] + x.fst];

	if (!keep)
		for (int x = in[v]; x <= out[v]; x++){
			k = rt[x];
			freq[dpt[k]]--;
		}
}

// Para resolver esse problema vamos inverter a pergunta
// Para cada u que possui uma query vamos perguntar para
// o ancestral de u que está a distância p quantos nós
// descendentes estão a distância p do mesmo.
//
// Para achar esse ancestral vamos usar uma sparse table
// e subir de acordo com os bits ligados da distância

int32_t main(){
	fastio;

	cin>>n;

	string s;
	int x;
	frr(i, n){
		cin>>x;
		if (x != 0){
			adj[i].pb(x);
			adj[x].pb(i);
		}
		else
			root.pb(i);
	}

	cin>>m;
	int y;
	fr(i, m){
		cin>>x>>y;
		qryt[x].pb({y, i}); // query temporária
	}

	for (int u : root){
		dpt[u] = 1;
		for (int i = 0; i < LMAXN; i++) //lca da raiz
			lca[u][i] = u;
	
		dfs_sz(u);

		while (!vis.empty()){ // na subárvore de u
			int v = vis.top();
			vis.pop();
			
			for (auto x : qryt[v]){
				if (x.fst < dpt[v]){
		
					int p = v;
					for (int i = 0; i < LMAXN; i++)  // lca[v][0] é o pai de v
						if (x.fst & (1 << i))
							p = lca[p][i];
					qry[p].pb({x.fst, x.snd}); // toca a refência da query
				}
			}
		}

		dfs(u);
	}

	fr(i, m)
		cout<<ans[i] + (ans[i] <= 0? 0 : -1)<<' '; // queremos só os primos
	gnl;	
}