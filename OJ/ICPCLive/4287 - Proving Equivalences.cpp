#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 100100;
const int MAXM = 1001000;
const ll mod=1e9+7;
const int LMAXN = 25;

vector<int> adj[MAXN];
vi adjscc[MAXN];
int pre[MAXN], lo[MAXN], stk[MAXN], scc[MAXN];
int clk, sn, id;
int n, m;
int in[MAXN], out[MAXN];

void dfsRscc( int v) {
	pre[v] = lo[v] = clk++;
	stk[sn++] = v;
	for (int x : adj[v]) {
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

// compute the array scc[], scc[v] is the strong connected component that contain v
int tarjan() {
	for (int v = 0; v < n; v++)
		pre[v] = -1;
	clk = sn = id = 0;
	for (int v = 0; v < n; v++)
		if (pre[v] == -1)
			dfsRscc( v);
	return id;	
}

//build the graph of strong onnected components
void build_scc_graph() {
	for (int v = 0; v < n; v++)
		for (int x : adj[v])
			if (scc[v] != scc[x]){
				adjscc[scc[v]].push_back(scc[x]);
				adjscc[scc[x]].push_back(scc[v]);
			}
}

int vis[112345];
void dfs(int v, int cmp){
	vis[v] = cmp;
	for (auto x : adjscc[v]){
		if (!vis[x])
			dfs(x, cmp);
	}
}

int inc[MAXN], outc[MAXN];

void solve(){
	cin>>n>>m;
	fr(i, n){
		adj[i].clear();
		adjscc[i].clear();
	}

	int a, b;
	fr(i,m){
		cin>>a>>b;
		adj[a - 1].pb(b - 1);
	}
	
	tarjan();

	fr(i,id)
		in[i] = out[i] = 0;

	build_scc_graph();

	ms(vis, 0);
	int cmp = 1;

	fr(i,id)
		if (!vis[i])
			dfs( i, cmp++);
	
	ms(in, 0);
	ms(out, 0);
	fr(i,n)
		for (int x : adj[i])
			if (scc[i] != scc[x]){
				in[scc[x]]++;
				out[scc[i]]++;
			}

	ms(inc, 0);
	ms(outc, 0);

	int src , snk;
	src = snk = 0;

	fr(i,id){
		if (in[i] == 0)
			src++;
		if (out[i] == 0)
			snk++;
	}

	if (id == 1)
		cout<<0<<endl;
	else		
		cout<<max(src, snk)<<endl;			
}

int main(){
	fastio;
	int t;
	cin>>t;
	while (t--)
		solve();
}