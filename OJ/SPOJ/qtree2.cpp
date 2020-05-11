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
vii adj[MAXN];
int pos[MAXN], rpos[MAXN], sz[MAXN], pai[MAXN], hgt[MAXN];
int h[MAXN], clk;

void dfs_hld(int k, int p = -1){
	sz[k] = 1;
	for (auto &i : adj[k]){
		if (i.fst != p){
			dfs_hld(i.fst, k);
			sz[k] += sz[i.fst];
			if (sz[i.fst] > sz[adj[k][0].fst] or adj[k][0].fst == p)
				swap(i, adj[k][0]);
		}
	}
}

void build_hld(int k, int p = -1){
	pos[k] = clk++;
	rpos[pos[k]] = k;
	for (auto i : adj[k]){
		if (i.fst != p){
			pai[i.fst] = k;
			if (i.fst == adj[k][0].fst)
				h[i.fst] = h[k];
			else
				h[i.fst] = i.fst;
			hgt[i.fst] = hgt[k] + i.snd;
			sz[i.fst] = sz[k] + 1;
			build_hld(i.fst, k);
		}
	}
}

void build(int r = 0){
	clk = 0;
	hgt[r] = 0;
	h[r] = r;
	dfs_hld(r);
	sz[r] = 0;
	build_hld(r);
}

int lca(int a, int b){
	if (pos[a] < pos[b])
		swap(a, b);
	return h[a] == h[b] ? b : lca(pai[h[a]], b);
}


int query_path(int a, int b, int k){
	int dst =  sz[a] + sz[b] - 2*sz[lca(a, b)] + 1;

	if (k == 1)
		return a;
	if (k == dst)
		return b;

	int auxd;
	while (true){
		if (pos[a] > pos[b]){
			auxd = sz[a] - sz[h[a]] + 1;
			if (auxd >= k){
				return rpos[pos[a] - (k - 1)	];
			}
			else{
				k -= auxd;
				dst -= auxd;
				a = pai[h[a]];
			}
		}
		else{
			auxd = sz[b] - sz[h[b]] + 1;
			if (auxd >= (dst - k + 1)){
				return rpos[pos[b] - (dst - k)];
			}
			else{
				dst -= auxd;
				b = pai[h[b]];
			}
		}
	}
	return -1;
}

void solve(){
	int k;
	scanf("%d", &n);

	fr(i, n)
		adj[i].clear();

	int a, b, c;
	fr(i, n - 1){
		scanf("%d %d %d", &a, &b, &c);
		a--;b--;
		adj[a].pb({b, c});
		adj[b].pb({a, c});
	}

	build();

	char s[300];
	scanf(" %s ", s);
	while (s[1] != 'O'){
		if (s[1] == 'I'){
			scanf("%d %d", &a, &b);
			a--; b--;
			int aux = lca(a, b);
			printf("%d\n", hgt[a] + hgt[b] - 2*hgt[aux]);
		}
		else{
			scanf("%d %d %d", &a, &b, &k);
			a--; b--;
			printf("%d\n", query_path(a, b, k) + 1);
		}
		scanf(" %s ", s);
	}
	printf("\n");
}

int32_t main(){
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
}