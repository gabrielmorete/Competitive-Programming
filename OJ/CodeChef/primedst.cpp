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
const int MAXN = 6e4 + 10;

vi primos;
bool prime[MAXN];
void crivo(){
	memset(prime, 1, sizeof prime);
	for (ll i = 2; i < MAXN; i++){
		if (prime[i]){
			primos.pb(i);
			for (ll j = i * i; j < MAXN; j += i)
				prime[j] = 0;
		}
	}
}


int n;
vi adj[MAXN];

int pai[MAXN], szt[MAXN]; // pai[root] = root
bool blk[MAXN]; // vértice bloqueado

int dfs_sz(int v, int p){ // calcula tamanho da subárvore
	szt[v] = 1;
	for (auto x : adj[v])
		if (x != p and !blk[x])
			szt[v] += dfs_sz(x, v);
	return szt[v];	
}

int dist[MAXN];

void dfs_dist(int v, int p, int h, int sgn){ // manipula as distancias
	dist[h] += sgn;
	for (auto x : adj[v])
		if (x != p and !blk[x])
			dfs_dist(x, v, h + 1, sgn);
}

ll ans;

void dfs_calc(int v, int p, int h){
	for (auto prm : primos)
		if (prm - h >= 0)
			ans += dist[prm - h]; // estão a distancia prima
	for (auto u : adj[v])
		if (!blk[u] and u != p)
			dfs_calc(u, v, h + 1);	
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

	dfs_dist(v, v, 0, 1); // calculo distancias	na minha sub
	dist[0]++; // tem que dobrar

	for (auto u : adj[v])
		if (!blk[u]){ // ta na minha subárvore
			dfs_dist(u, v, 1, -1); // apaga subárvore
			dfs_calc(u, v, 1); // calcula na subárvore
			dfs_dist(u, v, 1, 1); // liga árvore
		}

	dfs_dist(v, v, 0, -1); // apaga minha sub
	dist[0] = 0;
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
	crivo();

	cin>>n;

	int x, y;
	fr(i, n - 1){
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	centroid(1);

	double val = ans;
	val /= n;
	val /= n - 1;

	cout<<setprecision(10)<<fixed;
	cout<<val<<endl;
}