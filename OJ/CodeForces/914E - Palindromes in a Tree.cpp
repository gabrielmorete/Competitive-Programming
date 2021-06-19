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
const int MAXN = 2e6 + 10;

int n;
vi adj[MAXN];
string s;
int pai[MAXN], szt[MAXN]; // pai[root] = root
bool blk[MAXN]; // vértice bloqueado

int get_mask(int v){
	return 1<<(int)(s[v - 1] - 'a');
}

int dfs_sz(int v, int p){ // calcula tamanho da subárvore
	szt[v] = 1;
	for (auto x : adj[v])
		if (x != p and !blk[x])
			szt[v] += dfs_sz(x, v);
	return szt[v];	
}

int dist[MAXN];

void dfs_dist(int v, int p, int msk, int sgn){ // calcula as masks partindo do centroid
	msk ^= get_mask(v);
	if (v != p) // na raiz é zero, e isso me fudeu de verde e amarelo
		dist[msk] += sgn;
	for (auto x : adj[v])
		if (x != p and !blk[x])
			dfs_dist(x, v, msk, sgn);
}

ll ans[MAXN];

ll dfs_calc(int v, int p, int msk){ // calcula entre subárvores
	msk ^= get_mask(v);

	ll aux = 0;

	for (int j = 0; j < 20; j++)
		aux += dist[msk^(1<<j)];
	aux += dist[msk];

	for (auto u : adj[v])
		if (!blk[u] and u != p)
			aux += dfs_calc(u, v, msk);	
	ans[v] += aux;
	return aux;	
}

ll dfs_me(int v, int p, int msk){ // calcula com o centroid
	msk ^= get_mask(v);

	ll aux = __builtin_popcount(msk) <= 1;

	for (auto u : adj[v])
		if (u != p and !blk[u])
			aux += dfs_me(u, v, msk);

	ans[v] += aux;
	return aux;
}


int dfs_decomp(int v, int p = -1, int sz = -1){ // O(nlog(n))
	if (sz < 0)
		sz = dfs_sz(v, v); // tamanho da subárvore, muda quando achamos o centroid
	for (auto x : adj[v])
		if (!blk[x] and szt[x] * 2 >= sz){
			szt[v] = 0; // evita cliclagem
			return dfs_decomp(x, p, sz);
		}

	// achei o centroid	
	blk[v] = true;
	pai[v] = (p == -1? v : p);	
	dfs_dist(v, v, get_mask(v), 1); // calculo mascaras, partindo da raiz dos meus filhos
	// mando getmask par me anular

	ll aux = 0;
	for (auto u : adj[v])
		if (!blk[u]){ // ta na minha subárvore
			dfs_dist(u, v, 0, -1); // apaga subárvore
			aux += dfs_calc(u, v, get_mask(v)); // calcula na subárvore entre subs
			dfs_dist(u, v, 0, 1); // liga árvore
			ans[v] += dfs_me(u, v, get_mask(v)); // calcula com o centroid

		}

	ans[v] += aux/2; // entre as subárvores eu contei 2x

	dfs_dist(v, v, get_mask(v), -1); // apaga minha sub
	for (auto x : adj[v])
		if (!blk[x])
			dfs_decomp(x, v);
	return v;	
}

int centroid(int r){
	memset(blk, 0, sizeof blk);
	return dfs_decomp(r);
}


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;

	int x, y;
	fr(i, n - 1){
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	cin>>s;

	centroid(1);

	frr(i, n)
		cout<< ans[i] + 1<<' ';
	gnl;	
}