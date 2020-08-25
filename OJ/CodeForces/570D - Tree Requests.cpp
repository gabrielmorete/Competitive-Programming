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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 5e5 + 10;

int n, m;
string s;

bool ans[MAXN];
int sz[MAXN], dpt[MAXN], in[MAXN], out[MAXN], rt[MAXN], clk;
int cnt[MAXN][30], pal[MAXN];
vi adj[MAXN]; 
vii qry[MAXN];

void dfs_sz(int v, int p = -1){
	sz[v] = 1;
	in[v] = clk;
	rt[clk++] = v;
	for (auto &x : adj[v]){
		if (x != p){
			dpt[x] = dpt[v] + 1;
			dfs_sz(x, v);
			sz[v] += sz[x];
			if (sz[x] > sz[adj[v][0]] or adj[v][0] == p)
				swap(x, adj[v][0]);
		}
	}
	out[v] = clk - 1;
}

void dfs(int v, int p = -1, bool keep = 0){
	int bc = adj[v].size() > 1 ? adj[v][0] : -1;

	for (int u : adj[v])
		if (u != p and u != bc)
			dfs(u, v);
	
	if (bc != -1)
		dfs(bc, v, 1);	

	int k;
	for (int u : adj[v])
		if (u != p and u != bc){
			for (int x = in[u]; x <= out[u]; x++){
				k = rt[x];
				pal[dpt[k]] -= cnt[dpt[k]][s[k] - 'a'];
				cnt[dpt[k]][s[k] - 'a'] ^= 1;
				pal[dpt[k]] += cnt[dpt[k]][s[k] - 'a'];
			}
		}

	k = v;	
	pal[dpt[k]] -= cnt[dpt[k]][s[k] - 'a'];
	cnt[dpt[k]][s[k] - 'a'] ^= 1;
	pal[dpt[k]] += cnt[dpt[k]][s[k] - 'a'];

	for (auto x : qry[v])
		ans[x.snd] = pal[x.fst] <= 1;

	if (!keep)
		for (int x = in[v]; x <= out[v]; x++){
			k = rt[x];
			pal[dpt[k]] = 0;
			cnt[dpt[k]][s[k] - 'a'] = 0;
		}
}

int32_t main(){
	fastio;
	cin>>n>>m;

	int x, y;
	for (int i = 2; i <= n; i++){
		cin>>x;
		adj[i].pb(x);
		adj[x].pb(i);
	}

	cin>>s;
	s = '#' + s;

	fr(i, m){
		cin>>x>>y;
		qry[x].pb({y, i});
	}

	dpt[1] = 1;
	dfs_sz(1);
	dfs(1);

	fr(i, m)
		if (ans[i])
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;

}