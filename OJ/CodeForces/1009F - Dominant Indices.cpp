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
const int MAXN = 1e6 + 10;

int sz[MAXN], dpt[MAXN], in[MAXN], out[MAXN], rt[MAXN], clk;

int freq[MAXN], ans[MAXN];
int ind;

vi adj[MAXN];
void dfs_sz(int v, int p = -1){
	sz[v] = 1;
	in[v] = clk;
	rt[clk++] = v;
	for (auto &x : adj[v]){
		if (x != p){
			dpt[x] = dpt[v] + 1;
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
				freq[dpt[k]]++;
				if (freq[dpt[k]] > freq[ind])
					ind = dpt[k];
				if (freq[dpt[k]] == freq[ind] and dpt[k] < ind)
					ind = dpt[k];						
	    	}
	    }	

	int k = v;	
	freq[dpt[k]]++;
	if (freq[dpt[k]] > freq[ind])
		ind = dpt[k];
	if (freq[dpt[k]] == freq[ind] and dpt[k] < ind)
		ind = dpt[k];						

	ans[v] = ind - dpt[v];    	

    if (!keep){
     	for(int x = in[v]; x <= out[v]; x++){
     		int k = rt[x];
			freq[dpt[k]]--;
    	}
    	ind = 0;
    }
}

int32_t main(){
	fastio;
	int n;
	cin>>n;

	int x, y;
	fr(i, n - 1){
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	dfs_sz(1);
	dfs(1);

	frr(i, n)
		cout<<ans[i]<<endl;
}