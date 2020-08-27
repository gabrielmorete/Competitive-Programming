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

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 2e5 + 10;

int n, m;
int t[2 * MAXN];
int freq[MAXN];

void modify(int p, int value) {  
  for (t[p += n] += value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}


ll col[MAXN], ans[MAXN];
int sz[MAXN], in[MAXN], out[MAXN], rt[MAXN], clk;

ll val, sum;

vi adj[MAXN];
vii qry[MAXN];
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
	out[v] = clk - 1;
}

void dfs(int v, int p = -1, bool keep = 0){
	int bc = adj[v].size() > 1 ? adj[v][0] : -1;

	for (int u : adj[v]){
		if (u != p and u != bc)
			dfs(u, v);
	}

	if (bc != -1)
		dfs(bc, v, 1);

	for (auto u : adj[v])
		if (u != p and u != bc){
	    	for(int x = in[u]; x <= out[u]; x++){
				int k = rt[x];

				modify(freq[col[k]], -1); // diminui uma cor nessa freq
				freq[col[k]]++;
				modify(freq[col[k]], 1); // aumenta uma cor nessa freq
		    	}
	    }	

    modify(freq[col[v]], -1); // diminui uma cor nessa freq
	freq[col[v]]++;
	modify(freq[col[v]], 1); // aumenta uma cor nessa freq	    

	for (auto x : qry[v])
		ans[x.snd] = query(x.fst, n + 1);

    if (!keep){
     	for(int x = in[v]; x <= out[v]; x++){
     		int k = rt[x];
			modify(freq[col[k]], -1); // diminui uma cor nessa freq
			freq[col[k]]--;
			modify(freq[col[k]], 1);
    	}
    }
}

int32_t main(){
	fastio;

	cin>>n>>m;

	frr(i, n)
		cin>>col[i];

	int x, y;
	fr(i, n - 1){
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	fr(i, m){
		cin>>x>>y;
		qry[x].pb({y, i});
	}

	dfs_sz(1);
	dfs(1);

	fr(i, m)
		cout<<ans[i]<<endl;
}