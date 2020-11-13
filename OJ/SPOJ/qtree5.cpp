#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

//#define endl '\n'
#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;

int n, sz[MAXN], skip[MAXN], pai[MAXN];// size of subtree, dead nodes, direct ancester in centroid tree
vector<int> adj[MAXN];

namespace hld{
	int pos[MAXN], sz[MAXN], pai[MAXN], h[MAXN], hgt[MAXN], clk;
	void dfs_sz(int v, int p = -1){
		sz[v] = 1;
		for (auto &x : adj[v]){
			if (x != p){
				hgt[x] = hgt[v] + 1;
				dfs_sz(x, v);
				sz[v] += sz[x];
				if (sz[x] > sz[adj[v][0]] or adj[v][0] == p) 
					swap(x, adj[v][0]); // filho mais pesado em adj[v][0]
			}
		}
	}

	void dfs_build(int v, int p = -1){
		pos[v] = clk++; // contém a subárvore de v sequêncialmente
		for (auto &x : adj[v])
			if (x != p){
				pai[x] = v;
				if (x == adj[v][0])
					h[x] = h[v]; // na mesma cadeia que o pai
				else
					h[x] = x; // nova cabeça de cadeia
				dfs_build(x, v);
			}
	}

	void build(int r){ // monta a hld com raiz r
		clk = 0;
		hgt[r] = 0;
		h[r] = r;
		dfs_sz(r);
		dfs_build(r);
	}
	int lca(int a, int b){ // lca de a e b
		if (pos[a] < pos[b])
			swap(a, b);
		return h[a] == h[b] ? b : lca(pai[h[a]], b);
	}

	int dist(int a, int b){
		return hgt[a] + hgt[b] - 2 * hgt[lca(a, b)];
	}
}

int get_sz(int v, int p){ // compute sizes of the subtress
	sz[v] = 1;
	for (auto u : adj[v])
		if (u != p and !skip[u])
			sz[v] += get_sz(u, v);
	return sz[v];	
}

int get_ctrd(int v, int p, int szt){ // find centroid of a tree
	for (auto u : adj[v])
		if (u != p and !skip[u] and sz[u] > szt)
			return get_ctrd(u, v, szt);
	return v;		
}

int find_centroid(int r = 1){
	get_sz(r, r); // need to recompute everytime because of the skip nodes
	return get_ctrd(r, r, sz[r]/2);
}

void rec(int v, int p){
	int cnt = find_centroid(v); // find centroid of the sebtree
	skip[cnt] = true; // block the centoid, split in subtress
	if (p == -1)
		p = cnt;
	pai[cnt] = p;
	for (auto u : adj[cnt]) // for every subtree of the centroid
		if (!skip[u])
			rec(u, cnt); // compute centroid decomp
	skip[cnt] = false;
}
	
void centroid_decomp(int r = 1){
	memset(skip, 0, sizeof skip);
	rec(r, -1);
}

int color[MAXN];
multiset<int> ans[MAXN];

void add(int v){
	int x = v;
	while (x != pai[x]){
		ans[x].insert(hld::dist(x, v));
		x = pai[x];
	}
	ans[x].insert(hld::dist(x, v));
}

void remove(int v){
	int x = v;
	while (x != pai[x]){
		ans[x].erase(ans[x].find(hld::dist(x, v)));
		x = pai[x];
	}
	ans[x].erase(ans[x].find(hld::dist(x, v)));
}

void update(int v){
	if (color[v] == 0)
		add(v);
	else
		remove(v);

	color[v] = 1 - color[v];
}

int query(int v){
	int x = v;
	int ret = INF;
	while(x != pai[x]){
		if (!ans[x].empty())
			ret = min(ret, hld::dist(v, x) + *(ans[x].begin()));
		x = pai[x];
	}
	if (!ans[x].empty())
			ret = min(ret, hld::dist(v, x) + *(ans[x].begin()));
	return ret == INF? -1 : ret;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, q;
	cin>>n;

	int a, b;
	fr(i, n - 1){
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	hld::build(1);

	centroid_decomp(); // root = 1

	cin>>q;

	while (q--){
		cin>>a>>b;
		if (a == 0)
			update(b);
		else
			cout<<query(b)<<endl;
	}
}