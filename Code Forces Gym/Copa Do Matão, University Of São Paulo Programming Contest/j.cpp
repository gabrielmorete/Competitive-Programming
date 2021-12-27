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
const int MAXN = 5e5 + 10;

int n, m, clk, sn, id;
int pre[MAXN], lo[MAXN], stk[MAXN], scc[MAXN]; // scc[v] é a componente forte de v
vector<int> adj[MAXN], adjscc[MAXN];

void dfs_scc(int v){
	pre[v] = lo[v] = clk++;
	stk[sn++] = v;
	for (auto x : adj[v]){
		if (pre[x] == -1)
			dfs_scc(x);
		lo[v] = min(lo[v], lo[x]);
	}
	if (lo[v] == pre[v]){
		int u;
		do {
			u = stk[--sn];
			scc[u] = id;
			lo[u] = INF;
		} while (u != v);
		id++;
	}
}

int findscc(){
	fill(pre, pre + n + 1, -1);
	clk = sn = id = 0;
	for (int v = 0; v < n; v++) // 0 indexed
		if (pre[v] == -1)
			dfs_scc(v);
	return id;	
}

void build_scc_graph(){
	for (int v = 0; v < n; v++)
		for (auto x : adj[v])
			if (scc[v] != scc[x]){
				adjscc[scc[v]].push_back(scc[x]);
				adjscc[scc[x]].push_back(scc[v]);
			}
}

int frq[MAXN];

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>m;

	fr(i, m){
		int x, y;
		cin>>x>>y;
		adj[x - 1].pb(y - 1);
	}

	findscc();
	build_scc_graph();

	fr(i, n)
		frq[scc[i]]++;
	
	int ans = 0;
	fr(i, id){
		if (!adjscc[i].empty() or frq[i] > 1)
			ans += (2 * frq[i]) - 1;	
	}

	cout<<ans<<endl;
}
