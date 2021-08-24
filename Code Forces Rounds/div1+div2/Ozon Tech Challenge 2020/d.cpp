#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

// #define endl '\n'
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

int n;
vi adj[MAXN];

int query(int a, int b){
	cout<<"? "<<a<<' '<<b<<endl;
	int c;
	cin>>c;
	return c;
}

void apaga(int a, int b){ // apaga a da lista de b
	int p = 0;
	fr(i, adj[b].size())
		if (adj[b][i] == a)
			p = i;
	adj[b].erase(adj[b].begin() + p);
}

int pai[MAXN], sz[MAXN];

void dfs(int v, int p){
	sz[v] = 1;
	pai[v] = p;

	for (auto x : adj[v])
		if (x != p){
			dfs(x, v);
			sz[v] += sz[x];
		}
}

int get_leaf(int v, int p){
	if (sz[v] == 1)
		return v;
	if (p == adj[v].back())
		return get_leaf(adj[v][0], v);
	return get_leaf(adj[v].back(), v);
}

void solve(int r){
	dfs(r, r);
	if (sz[r] == 1){
		cout<<"! "<<r<<endl;
		exit(0);
	}

	int a = r;
	int b = get_leaf(adj[r][0], r);

	if (adj[r].size() > 1)
		a = get_leaf(adj[r][1], r);

	int u = query(a, b);

	if (u == r){
		apaga(adj[r][0], r);
		if (!adj[r].empty())
			apaga(adj[r][0], r);
		solve(r);
	}

	apaga(pai[u], u);



	if (u == a)
		solve(a);

	if (u == b)
		solve(b);

	apaga(a, pai[a]);
	apaga(b, pai[b]);
	solve(u);
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;

	int x, y;
	fr(i, n - 1){
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	solve(1);
}