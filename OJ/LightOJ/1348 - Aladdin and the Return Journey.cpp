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
const int MAXN = 30010;
const int MAXM = 1001000;
const ll mod=1e9+7;
const int LMAXN = 25;

int n;

namespace seg {
	
	int v[2 * MAXN];

	void build() {  // build the tree
		for (int i = n - 1; i > 0; --i) 
			v[i] = v[i<<1] + v[i<<1|1];
	}

	void update(int p, int value) {  // set value at position p
		for (v[p += n] = value; p > 1; p >>= 1) 
			v[p>>1] = v[p] + v[p^1];
	}

	int query(int l, int r) {  // sum on interval [l, r)
		int res = 0;
		r++;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l&1) res += v[l++];
		if (r&1) res += v[--r];
		}
		return res;
	}
};


vector<int> adj[MAXN];
int pos[MAXN], sz[MAXN];
int peso[MAXN], pai[MAXN];
int h[MAXN], clk;

void build_hld(int k, int p = -1, int f = 1){
	pos[k] = clk++;
	seg::v[clk - 1 + n] = peso[k]; // building segtree on-the-fly
	sz[k] = 1;
	for (auto &i : adj[k])
		if (i != p){
			pai[i] = k;
			if (i == adj[k][0])
				h[i] = h[k];
			else
				h[i] = i;

			build_hld(i, k, f);
			sz[k] += sz[i];
			if (sz[i] > sz[adj[k][0]] or adj[k][0] == p){ // fixing things on first run
				swap(i, adj[k][0]);
			}
		}
	if (p * f == -1)
		build_hld(h[k] = k, -1, clk = 0);// this shit just run twice
}

void build(int r = 0){
	clk = 0;
	build_hld(r);
	seg::build();
}

ll query_path(int a, int b){
	if (pos[a] < pos[b])
		swap(a, b);
	if (h[a] == h[b])
		return seg::query(pos[b], pos[a]);
	return seg::query(pos[h[a]], pos[a]) + query_path(pai[h[a]], b);
}


void solve(){
	scanf("%d", &n);
	fr(i, n){
		scanf("%d", peso + i);
		adj[i].clear();
	}
	int a, b, x;
	fr(i, n - 1){
		scanf("%d %d", &a, &b);
		adj[a].pb(b);
		adj[b].pb(a);
	}

	build();

	int q;
	scanf("%d", &q);
	while (q--){
		scanf("%d %d %d", &x, &a, &b);

		if (!x)
			printf("%d\n", query_path(a, b));
		else
			seg::update(pos[a], b);
	}
}

int main(){

	int T;
	scanf("%d", &T);

	frr(i, T){
		printf("Case %d:\n", i);
		solve();
	}
}
