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
const int LMAXN = 23;

#define oper(a, b) a + b // opreação
#define NEUT 0 // neutro

namespace seg{
	vector<int> seg(1, NEUT), lft(1, 0), rgt(1, 0); 
	int rt(0);

	int new_node(int v, int l = 0, int r = 0){
		seg.pb(v);
		lft.pb(l);
		rgt.pb(r);
		return (int)(seg.size()) - 1;
	}

	int update(int nd, int l, int r, int pos, int val){
		int ks = new_node(seg[nd], lft[nd], rgt[nd]);
		if (l == r){
			seg[ks] += val;
			return ks;
		}
		
		int m = (l + r)/2, ps;
		if(pos <= m)
		    ps = update(lft[nd], l, m, pos, val), lft[ks] = ps;
		else 
			ps = update(rgt[nd], m + 1, r, pos, val), rgt[ks] = ps;
		
		seg[ks] = oper(seg[lft[ks]], seg[rgt[ks]]);
		return ks;
	}

	int query(int a, int b, int c, int d, int l, int r, int k){
		int m = (l + r)/2;

		if (l == r)
			return l;
		
		int aux = seg[lft[a]] + seg[lft[b]] - seg[lft[c]] - seg[lft[d]];

		if (aux >= k)
			return query(lft[a], lft[b], lft[c], lft[d], l, m, k);
		else	
			return query(rgt[a], rgt[b], rgt[c], rgt[d], m + 1, r, k - aux);
	}
} 

int n, m, wgt[MAXN], root[MAXN], hgt[MAXN], memo[MAXN][LMAXN]; 
vi adj[MAXN];

void dfs_lca(int v, int p){
	root[v] = seg::update(root[p], 1, n, wgt[v], 1);
	for (auto x : adj[v])
		if (x != p){ 
			hgt[x] = hgt[v] + 1; 
			memo[x][0] = v; 
			for (int i = 1; i < LMAXN; i++) 
				memo[x][i] = memo[memo[x][i - 1]][i - 1];
			dfs_lca(x, v);
		}
}

void build_lca(int r){ // enraizado em r
	fill(memo[r], memo[r] + LMAXN, r);
	dfs_lca(r, r); 
}

int find_lca(int a, int b){
	if (hgt[a] < hgt[b])
		swap(a, b); 
	for (int i = LMAXN - 1; i >= 0; i--) // equilibra os vértices
		if (hgt[memo[a][i]] >= hgt[b])
			a = memo[a][i];
	if (a == b) 
		return a; 
	for (int i = LMAXN - 1; i >= 0; i--) // sobe junto
		if (memo[a][i] != memo[b][i]){
			a = memo[a][i];
			b = memo[b][i];
		}
	return memo[a][0]; // para imediatamente antes do lca
}

map<int, int> crd, rcrd;

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;
	frr(i, n)
		cin>>wgt[i];

	frr(i, n)
		crd[wgt[i]]; // cria nó

	int cnt = 1;
	for (auto it : crd){
		crd[it.fst] = cnt;
		rcrd[cnt++] = it.fst;
	}	
	frr(i, n)
		wgt[i] = crd[wgt[i]];

	int a, b;
	fr(i, n - 1){
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}	
	
	build_lca(1);

	int u, v, k;
	while (m--){
		cin>>u>>v>>k;
		int lca = find_lca(u, v);
		int ans = seg::query(root[u], root[v], root[lca], lca == 1? 0 : root[memo[lca][0]], 1, n, k);
		cout<<rcrd[ans]<<endl;
	}
}