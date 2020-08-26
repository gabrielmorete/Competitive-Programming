#include "bits/stdc++.h"
using namespace std;


#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> ordered_set;


#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

#define endl '\n'
#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 5e4 + 10;

ll n, m, leaf[MAXN], ans[MAXN];
vi adj[MAXN];

int sz[MAXN], in[MAXN], out[MAXN], rt[MAXN], clk;
void dfs_sz(int v, int p = -1){
	sz[v] = 1;
	in[v] = clk;
	rt[clk++] = v;
	for (auto &x : adj[v]){
		if (x != p){
			dfs_sz(x, v);
			sz[v] += sz[x];
			if (sz[x] > sz[adj[v][0]] or adj[v][0] == p) // adj[v][0] é sempre o filho pesado
				swap(x, adj[v][0]);
		}
	}
	out[v] = clk - 1; // ultimo filho de v
}

// find_by_order(i) -> iterator to ith element
// order_of_key(k) -> position (int) of lower_bound of k

ordered_set q;
ll val = (1ll<<31) - 1;

void dfs(int v, int p = -1, bool keep = 0){
	int bc = adj[v].size() > 1 ? adj[v][0] : -1;// filho grande
	if (bc != -1 and adj[bc].size() == 1) // bc é folha
		bc = -1;

	for (int u : adj[v])
		if (u != p and u != bc)
			dfs(u, v);
	
	if (bc != -1)
		dfs(bc, v, 1); // guarda o resultado do mais pesado

	ll aux;
	for (int u : adj[v])
		if (u != p and u != bc){
	    	for(int x = in[u]; x <= out[u]; x++){ // sequancial pela dfs
				if (leaf[rt[x]] != -INF){ // é folha
					aux = leaf[rt[x]];

					int p = q.order_of_key(aux);
					if (p < q.size())
						val = min(val, abs<ll>((*q.find_by_order(p)) - aux));
					if (p > 0)
						val = min(val, abs<ll>((*q.find_by_order(p - 1)) - aux));
					q.insert(aux);
				}	
			}
	    }	

	ans[v] = val;
    
    if (!keep){
     	q.clear();
     	val = (1ll<<31) - 1;
    }
}



int32_t main(){
	//fastio;
	fill(ans, ans + MAXN, (1ll<<31) - 1);

	scanf("%d %d", &n, &m);

	int x;
	for (int i = 2; i <= n; i++){
		scanf("%d", &x);
		adj[i].pb(x);
		adj[x].pb(i);
	}

	fill(leaf, leaf + MAXN, -INF);
	for (int i = n - m + 1; i <= n; i++){
		scanf("%d", &x);
		leaf[i] = x;
	}

	dfs_sz(1);
	dfs(1);

	for(int i = 1; i <= n - m; i++)
		printf("%d ", ans[i]);
	printf("\n");
}