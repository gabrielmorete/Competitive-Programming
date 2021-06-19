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

int n, pai[MAXN], szt[MAXN]; // pai[root] = root
bool blk[MAXN]; // vértice bloqueado

ll ans[MAXN];
vector<pair<ll, ll>> adj[MAXN], query[MAXN];

int dfs_sz(int v, int p){ // calcula tamanho da subárvore
	szt[v] = 1;
	for (auto x : adj[v])
		if (x.fst != p and !blk[x.fst])
			szt[v] += dfs_sz(x.fst, v);
	return szt[v];	
}

vector<ll> dist;

void dfs_dist(ll v, ll p, ll dst){ // calcula distancias partindo do centroid
	dist.pb(dst);
	for (auto x : adj[v])
		if (x.fst != p and !blk[x.fst])
			dfs_dist(x.fst, v, dst + x.snd);
}

void dfs_cnt(ll v, ll p, ll dpt, ll sng){
	for (auto q : query[v])
		if (q.fst - dpt >= 0){
			ll p = (ll)(upper_bound(all(dist), q.fst - dpt) - dist.begin()) - 1;
			ans[q.snd] += sng * p;
		}

	for (auto x : adj[v])
		if (x.fst != p and !blk[x.fst])
			dfs_cnt(x.fst, v, dpt + x.snd, sng);	
}

int dfs_decomp(int v, int p = -1, int sz = -1){ // O(nlog(n))
	if (sz < 0)
		sz = dfs_sz(v, v); // tamanho da subárvore, muda quando achamos o centroid
	for (auto x : adj[v])
		if (!blk[x.fst] and szt[x.fst] * 2 >= sz){
			szt[v] = 0; // evita cliclagem
			return dfs_decomp(x.fst, p, sz);
		}
	blk[v] = true;
	pai[v] = (p == -1? v : p);	

	dfs_dist(v, v, 0); // distancia do centroid para geral
	sort(all(dist));
	dfs_cnt(v, v, 0, 1);

	for (auto x : adj[v])
		if (x.fst != p and !blk[x.fst]){
			dist.clear();
			dfs_dist(x.fst, v, x.snd);
			sort(all(dist));
			dfs_cnt(x.fst, v, x.snd, -1);
		}

	dist.clear();
	for (auto x : adj[v])
		if (!blk[x.fst])
			dfs_decomp(x.fst, v);
	return v;	
}

int centroid(int r){
	memset(blk, 0, sizeof blk);
	return dfs_decomp(r);
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll q;

	cin>>n>>q;

	ll x, y, z;
	fr(i, n - 1){
		cin>>x>>y>>z;
		adj[x].pb({y, z});
		adj[y].pb({x, z});
	}

	fr(i, q){
		cin>>x>>y;
		query[x].pb({y, i});
	}

	centroid(1);

	fr(i, q)
		cout<<ans[i] + 1<<endl;
}