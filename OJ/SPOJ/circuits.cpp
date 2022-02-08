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
const int MAXN = 4e5 + 10;

int n, m, sn, clk, id;
int pre[MAXN], lo[MAXN], stk[MAXN], ebcc[MAXN];
vi adj[MAXN], adjebcc[MAXN];
int deg[MAXN], tam[MAXN];

void dfs_ebcc(int v, int p){
	lo[v] = pre[v] = clk++;
	stk[sn++] = v;

	for (auto x: adj[v]){
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

void build_ebcc(){
	fr(i, n){
		adjebcc[i].clear();
		tam[i] = 0;
		deg[i] = 0;
	}

	frr(i, n){
		tam[ebcc[i]]++;
		// cout<<i<<' '<<ebcc[i]<<endl;		
		for (auto x : adj[i])
			if (ebcc[i] != ebcc[x]){
				deg[ebcc[x]]++;
				adjebcc[ebcc[i]].pb(ebcc[x]);
			}
	}
}

int findebcc(){
	fill(pre, pre + n + 1, -1);
	sn = clk = id = 0;
	for (int v = 1; v <= n; v++)
		if (pre[v] == -1)
			dfs_ebcc(v, v);
		
	build_ebcc();
		
	return id;
}

void desfolha(){
	queue<int> fila;
	fr(i, id)
		if (deg[i] == 1 and tam[i] >= 3)
			fila.push(i); // todas as folhas de tamanho 3

	while (!fila.empty()){
		int v = fila.front();
		fila.pop();

		deg[v] = 0; // eu tiro esse cara do grafo, não me ajuda em nada

		for (auto x : adjebcc[v]){
			deg[x]--;

			if (deg[x] == 1 and tam[x] >= 3)
				fila.push(x);
		}
	}	
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (cin>>n>>m and n != -1){
		frr(i, n)
			adj[i].clear();
		
		int x, y;	
		fr(i, m){
			cin>>x>>y;
			adj[x].pb(y);
			adj[y].pb(x);
		}

		findebcc();

		bool ok = 1;
		for (int i = 0; i < id; i++)
			if (tam[i] < 3)
				ok = 0;
		
		if (ok){ // todos estão em algum circuito, feito!
			cout<<0<<endl;
			continue;
		}	


		// ok, hora de desfolhar
		desfolha();

		int folha = 0;
		int isolado = 0;

		fr(i, id)
			if (tam[i] < 3){
				if (deg[i] == 0)
					isolado++;
				if (deg[i] == 1)
					folha++;
			}

		if (folha > 0)
			cout<<((folha + 1)/2 + isolado)<<endl;
		else{
			if (isolado >= 3)
				cout<<isolado<<endl;
			else{
				int ok = 0;
				fr(i, id)
					if (tam[i] < 3)
						if (!adjebcc[i].empty())// se só se era não isolado no original
							ok = 1;
				
				if (isolado == 2)		
					cout<<(3 - ok)<<endl;
				else
					cout<<(2 - ok)<<endl;
			}
		}		
	}
}