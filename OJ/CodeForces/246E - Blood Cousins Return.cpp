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

int n, m;
int ans[MAXN];
string name[MAXN];

vi  adj[MAXN], root;
vii qry[MAXN];

int sz[MAXN], dpt[MAXN], in[MAXN], out[MAXN], rt[MAXN], clk;
void dfs_sz(int v, int p = -1){
	sz[v] = 1;
	in[v] = clk;
	rt[clk++] = v;
	for (auto &x : adj[v]){
		if (x != p){
			dpt[x] = dpt[v] + 1;
			dfs_sz(x, v);
			sz[v] += sz[x];
			if (sz[x] > sz[adj[v][0]] or adj[v][0] == p)
				swap(x, adj[v][0]);
		}
	}
	out[v] = clk - 1;
}

set<string> q[MAXN];

void dfs(int v, int p = -1, bool keep = 0){
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
				q[dpt[k]].insert(name[k]);
			}
		}

	q[dpt[v]].insert(name[v]);	

	for (auto x : qry[v]){
		if (dpt[v] + x.fst >= MAXN) // Be caeful with out of bounds!
			ans[x.snd] = 0;
		else
			ans[x.snd] = q[dpt[v] + x.fst].size();
	}

	if (!keep)
		for (int x = in[v]; x <= out[v]; x++){
			k = rt[x];
			q[dpt[k]].clear();
		}
}


int32_t main(){
	fastio;

	cin>>n;

	string s;
	int x;
	frr(i, n){
		cin>>s>>x;
		name[i] = s;
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
		qry[x].pb({y, i});
	}

	for (int u : root){
		dpt[u] = 1;
		dfs_sz(u);
		dfs(u);
	}

	fr(i, m)
		cout<<ans[i]<<endl;
}