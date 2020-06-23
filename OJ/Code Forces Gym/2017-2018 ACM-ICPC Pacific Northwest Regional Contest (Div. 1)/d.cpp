#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 5e4 + 10;

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
		a++; b++;
		update(1, 1, n, a, b, x);
	}

	int pquery(int a, int b){
		a++; b++;
		return query(1, 1, n, a, b);
	}
}

vi adj[MAXN];
int pos[MAXN], sz[MAXN], pai[MAXN], h[MAXN], clk;

void dfs_hld(int k, int p = 0){
	sz[k] = 1;
	for (auto &i : adj[k]){
		if (i != p){
			dfs_hld(i, k);
			sz[k] += sz[i];
			if (sz[i] > sz[adj[k][0]] or adj[k][0] == p){
				swap(i, adj[k][0]);
			}
		}
	}
}

void build_hld(int k, int p = 0){
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
}

int query_path(int a, int b){
	if (pos[a] < pos[b])
		swap(a, b);
	if (h[a] == h[b])
		return seg::pquery(pos[b], pos[a]);
	return seg::pquery(pos[h[a]], pos[a]) + query_path(pai[h[a]], b);
}

int query_subtree(int a){
	return seg::pquery(pos[a], pos[a] + sz[a] - 1);
}

void update_subtree(int a, int x){
	seg::pupdate(pos[a], pos[a] + sz[a] - 1, x);
}

vii adj2[MAXN];

int32_t main(){
	fastio;
	cin>>n;

	int a, b, c;
	fr(i, n - 1){
		cin>>a>>b>>c;
		a--;
		b--;
		
		adj[a].pb(b);
		adj[b].pb(a);
		
		adj2[a].pb({c, b});
		adj2[b].pb({c, a});
	}
	
	fr(i, n)
		sort(all(adj2[i]));
	
	build();	

	vi cor;
	bool p;
	int i, j, m, u;
	for (int v = 0; v < n; v++){
	
		m = adj2[v].size();
		i = 0;
		while (i < m){
			p = 0;
			cor.clear();
			j = i;

			while (j < m and adj2[v][j].fst == adj2[v][i].fst){ // mesma cor
				u = adj2[v][j].snd;
				if (u == pai[v])
					p = 1;
				cor.pb(u);
				j++;
			}
			
			i = j;

			if (cor.size() > 1){
				if (p){ // marco todos que não são filhos de v ou v;
					update_subtree(0, 1); 
					update_subtree(v, -1);
				}
				for (auto f : cor){
					if (f != pai[v])
						update_subtree(f, 1);
				}
			}
		}
	}

	vi ans;
	for (int v = 0; v < n; v++)
		if (seg::pquery(pos[v], pos[v]) == 0)
			ans.pb(v + 1);

	cout<<ans.size()<<endl;	
	for (auto f : ans)
		cout<<f<<endl;
}