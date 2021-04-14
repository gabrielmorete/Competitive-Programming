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
const int MAXN = 3e5 + 10;
const int LMAXN = 25;

int q, pai[MAXN], topo[MAXN];

int hgt[MAXN], memo[MAXN][LMAXN]; 
vector<int> adj[MAXN];

void dfs_lca(int v, int p){
	for (auto x : adj[v])
		if (x != p){ 
			hgt[x] = hgt[v] + 1; 
			memo[x][0] = v; 
			for (int i = 1; i < LMAXN; i++) 
				memo[x][i] = memo[memo[x][i - 1]][i - 1];
			dfs_lca(x, v);
		}
}

void build_lca(int r){
	fill(memo[r], memo[r] + LMAXN, r);
	dfs_lca(r, r); 
}

int find_lca(int a, int b){
	if (hgt[a] < hgt[b])
		swap(a, b); 
	for (int i = LMAXN - 1; i >= 0; i--) // equilibra os vértices
		if (hgt[memo[a][i]] >= hgt[b])
			a = memo[a][i];
	if (a == b) 
		return a; 
	for (int i = LMAXN - 1; i >= 0; i--) // sobe junto
		if (memo[a][i] != memo[b][i]){
			a = memo[a][i];
			b = memo[b][i];
		}
	return memo[a][0]; // para imediatamente antes do lca
}


int ans[MAXN], cnt;
vector< tuple<int, int, int> > qry;

void add(int v, int p){
	adj[p].pb(v);
	adj[v].pb(p);
	pai[v] = p;
}	

int n, id[MAXN];

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>q;

	char a;
	int v, u;
	frr(i, q){
		cin>>a;
		if (a == 'a'){
			cin>>v;
			v = id[v];
			id[i] = ++n;
			add(n, v);
			topo[n] = i;
		}
		else if (a == 'b'){
			cin>>v;
			v = id[v];
			id[i] = pai[v];
			ans[cnt++] = topo[v];
		}
		else{
			cin>>v>>u;
			v = id[v];
			id[i] = v;
			qry.pb({cnt++, v, id[u]});
		}
	}

	build_lca(0);

	for (auto x : qry)
		ans[get<0>(x)] = hgt[find_lca(get<1>(x), get<2>(x))];
	
	fr(i, cnt)
		cout<<ans[i]<<endl;
}