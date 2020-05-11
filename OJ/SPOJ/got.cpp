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
const int MAXN = 1e6 + 10;
const ll mod=1e9+7;

int n, m;
vi adj[MAXN];
int pos[MAXN], sz[MAXN], pai[MAXN], peso[MAXN];
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

vi v[MAXN];

void build(int r = 0){
	clk = 0;
	dfs_hld(r);
	build_hld(r);

	fr(i, n + 1)
		v[i].clear();

	fr(i, n)
		v[peso[i]].pb(pos[i]);
	
	fr(i, n + 1)
		sort(all(v[i]));	
}

bool query(int a, int b, int c){
	auto it = lower_bound(all(v[c]), a);
	if (it == v[c].end())
		return false;
	return *it <= b;
}

bool query_path(int a, int b, int c){
	if (pos[a] < pos[b])
		swap(a, b);
	if (h[a] == h[b])
		return query(pos[b], pos[a], c);
	return query(pos[h[a]], pos[a], c) or query_path(pai[h[a]], b, c);
}

int32_t main(){
	while (scanf("%d %d", &n, &m) != EOF){
		fr(i, n){
			scanf("%d", peso + i);
			adj[i].clear();
		}

		int a, b, c;
		fr(i, n - 1){
			scanf("%d %d", &a, &b);
			a--;b--;
			adj[a].pb(b);
			adj[b].pb(a);
		}

		build();

		fr(i, m){
			scanf("%d %d %d", &a, &b, &c);
			if (query_path(a - 1, b - 1, c))
				printf("Find\n");
			else
				printf("NotFind\n");
		}
		printf("\n");
	}
}