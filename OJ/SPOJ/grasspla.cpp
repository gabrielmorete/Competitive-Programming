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

namespace seg{
	int seg[4*MAXN], delta[4*MAXN];
	void unlazy(int node, int l, int r){
		if (l != r){
			delta[node<<1] += delta[node];
			delta[node<<1|1] += delta[node];
		}
		seg[node] += (r - l + 1)*delta[node];
		delta[node] = 0;
	}

	void update(int node, int l, int r, int ul, int ur, int val){
		unlazy(node, l, r);
		if (r < ul or ur < l)
			return;
		if (ul <= l and r <= ur){
			delta[node] += val;
			unlazy(node, l, r);
			return;
		}

		int meio = (l + r)/2;
		update(node<<1, l, meio, ul, ur, val);
		update(node<<1|1, meio + 1, r, ul, ur, val);
		seg[node] = seg[node<<1] + seg[node<<1|1];
	}

	int query(int node, int l, int r, int ql, int qr){
		unlazy(node, l, r);
		if (r < ql or qr < l)
			return 0;
		if (ql <= l and r <= qr)
			return seg[node];

		int meio = (l + r)/2;
		return query(node<<1, l, meio, ql, qr) +
				query(node<<1|1, meio + 1, r, ql, qr);
	}

	void pupdate(int a, int b, int x){
		a++;b++;
		update(1, 1, n, a, b, x);
	}

	int pquery(int a, int b){
		a++;b++;
		return query(1, 1, n, a, b);
	}
}


vi adj[MAXN];
int pos[MAXN], sz[MAXN], pai[MAXN], h[MAXN], clk;

void dfs_hld(int k, int p = -1){
	sz[k] = 1;
	for (auto &i : adj[k]){
		if (i != p){
			dfs_hld(i, k);
			sz[k] += sz[i];
			if (sz[i] > sz[adj[k][0]] or adj[k][0] == p){ // ordenando a árvore
				swap(i, adj[k][0]);
			}
		}
	}
}

void build_hld(int k, int p = -1){
	pos[k] = clk++;
	for (auto &i : adj[k])
		if (i != p){
			pai[i] = k;
			if (i == adj[k][0])
				h[i] = h[k];
			else
				h[i] = i;
			build_hld(i, k);
		}
}

void build(int r = 0){
	clk = 0;
	h[r] = r;
	dfs_hld(r);
	build_hld(r);
	// agora devemos montar a estura de dados
}

ll query_path(int a, int b){
	if (pos[a] < pos[b])
		swap(a, b);
	if (h[a] == h[b])
		return seg::pquery(pos[b] + 1, pos[a]); //pos[b] + 1
	return seg::pquery(pos[h[a]], pos[a]) + query_path(pai[h[a]], b);
}

void update_path(int a, int b, int x){
	if (pos[a] < pos[b])
		swap(a, b);
	if (h[a] == h[b])
		return (void) seg::pupdate(pos[b] + 1, pos[a], x); //pos[b] + 1
	seg::pupdate(pos[h[a]], pos[a], x);
	update_path(pai[h[a]], b, x);
}


int32_t main(){
	fastio;
	int q;
	cin>>n>>q;

	int a, b;
	fr(i, n - 1){
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	string s;

	build(1);

	while (q--){
		cin>>s>>a>>b;
		if (s == "P")
			update_path(a, b, 1);
		else
			cout<<query_path(a, b)<<endl;
	}

}