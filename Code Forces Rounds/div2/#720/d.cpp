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

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(), x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;

int n, pai[MAXN], deg[MAXN];
bool rem[MAXN], vis[MAXN];
vi adj[MAXN], ans;


void dfs(int v, int p){
	int lft = adj[v].size(); // filhos
	if (v != p) lft--;

	pai[v] = p;
	
	for (auto x : adj[v])
		if (x != p){
			dfs(x, v);
			lft -= rem[x];
		}

	if (lft >= 2){
		if (v != 1){
			rem[v] = 1;
			ans.pb(v);
			deg[v]--;
			deg[p]--;
		}

		for (auto x : adj[v])
			if (x != p and !rem[x] and lft > 2){
				rem[x] = 1;
				ans.pb(x);
				lft--;
				deg[v]--;
				deg[x]--;
			}
	}
}

vii cmp;
vi ext;

void dfs2(int v){
	vis[v] = 1;

	for (auto x : adj[v]){
		if (vis[x])
			continue;

		if (x == pai[v] and !rem[v])
			dfs2(x);
		if (v == pai[x] and !rem[x])
			dfs2(x);
	}

	if (deg[v] <= 1)
		ext.pb(v);
}

void solve(){
	ans.clear();
	cmp.clear();

	cin>>n;
	frr(i, n){
		adj[i].clear();
		rem[i] = vis[i] = deg[i] = 0;
	}

	int x, y;
	fr(i, n - 1){
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
		deg[x]++;
		deg[y]++;
	}

	dfs(1, 1);

	frr(i, n)
		if (!vis[i]){
			ext.clear();
			dfs2(i);

			assert(ext.size() > 0);
			assert(ext.size() <= 2);

			if (ext.size() == 1)
				ext.pb(ext.back());

			cmp.pb({ext[0], ext[1]});
		}

	assert(ans.size() == cmp.size() - 1);	

	cout<<ans.size()<<endl;

	fr(i, (int)(cmp.size()) - 1)
		cout<<ans[i]<<' '<<pai[ans[i]]<<' '<<cmp[i].snd<<' '<<cmp[i + 1].fst<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}