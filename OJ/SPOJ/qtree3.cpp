#include "bits/stdc++.h"
using namespace std;

#define pb push_back
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
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;
const ll mod=1e9+7;

int n;
vi adj[MAXN];
int pos[MAXN], rpos[MAXN], sz[MAXN], pai[MAXN], peso[MAXN];
int h[MAXN], clk;

void dfs_hld(int k, int p = -1){
	sz[k] = 1;
	for (auto &i : adj[k]){
		if (i != p){
			dfs_hld(i, k);
			sz[k] += sz[i];
			if (sz[i] > sz[adj[k][0]] or adj[k][0] == p)
				swap(i, adj[k][0]);
		}
	}
}

void build_hld(int k, int p = -1){
	pos[k] = clk++;
	rpos[pos[k]] = k;
	for (auto i : adj[k]){
		if (i != p){
			pai[i] = k;
			if (i == adj[k][0])
				h[i] = h[k];
			else
				h[i] = i;
			build_hld(i, k);
		}
	}
}

void build(int r = 0){
	clk = 0;
	h[r] = r;
	dfs_hld(r);
	build_hld(r);
}

set<int> q;
bool black[MAXN];

int query(int a, int b){
	auto it = q.lower_bound(a);
	if (it == q.end())
		return -1;
	int aux = *it;
	if (aux <= b)
		return rpos[aux];
	return -1;
}


int query_path(int a, int b){
	if (pos[a] < pos[b])
		swap(a, b);
	if (h[a] == h[b])
		return query(pos[b], pos[a]);

	int aux = query_path(pai[h[a]], b);
	if (aux != -1)
		return aux;
	else
		return query(pos[h[a]], pos[a]);
}


int32_t main(){
	int k;
	scanf("%d %d", &n, &k);

	int a, b;
	fr(i, n - 1){
		scanf("%d %d", &a, &b);
		a--;b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	build();

	while (k--){
		scanf("%d %d", &a, &b);
		if (a == 0){
			b--;
			if (black[b])
				q.erase(pos[b]);
			else
				q.insert(pos[b]);
			black[b] = !black[b];				
		}
		else{
			b--;
			int aux = query_path(b, 0);
			printf("%d\n", aux == -1? aux : aux + 1);
		}
	}
}