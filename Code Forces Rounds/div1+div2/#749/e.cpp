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

int n, m, pai[MAXN], deg[MAXN];
vi adj[MAXN];

void dfspre(int v, int p){
	pai[v] = p;
	for (auto x : adj[v])
		if (!pai[x])
			dfspre(x, v);
}

int cnt;
vi ans[MAXN];

bool dfs(int v, int p, int u){
	ans[cnt].pb(v);

	if (v == u)
		return true;

	for (auto x : adj[v])
		if (x != p and dfs(x, v, u))
			return true;

	ans[cnt].pop_back();
	return false;	
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>m;

	int x, y;
	fr(i, m){
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	dfspre(1, 1);

	frr(i, n)
		adj[i].clear();
	
	frr(i, n)
		if (pai[i] != i){
			adj[i].pb(pai[i]);
			adj[pai[i]].pb(i);	
		}

	int q;
	cin>>q;

	fr(i, q){
		cin>>x>>y;
		deg[x]++;
		deg[y]++;

		dfs(x, x, y);

		cnt++;
	}	


	int od = 0;
	frr(i, n)
		if (deg[i]&1)
			od++;

	if (od > 0){
		cout<<"NO"<<endl;
		cout<<od/2<<endl;
		return 0;
	}

	cout<<"YES"<<endl;
	fr(i, q){
		cout<<ans[i].size()<<endl;
		for (auto x : ans[i])
			cout<<x<<' ';
		gnl;
	}
}