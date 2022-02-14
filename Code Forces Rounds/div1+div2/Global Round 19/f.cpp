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
const int MAXN = 4e5 + 10;

ll n, h[MAXN], pai[MAXN], leaf[MAXN], deg[MAXN], cost[MAXN];
vi adj[MAXN];

int min_leaf;
void dfs(int v, int p){
	if (adj[v].size() == 1){
		if (min_leaf == 0)
			min_leaf = v;
		else if (cost[min_leaf] < cost[v])
			min_leaf = v;
	
	}

	for (auto x : adj[v])
		if (x != p)
			dfs(x, v);
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	frr(i, n)
		cin>>h[i];

	fr(i, n - 1){
		int x, y;
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
		deg[x]++;
		deg[y]++;
	}

	queue<int> fila;

	frr(i, n)
		if (deg[i] == 1){
			fila.push(i);
			leaf[i] = i;
			pai[i] = i;
			cost[i] = h[i];
			deg[i] = 0;
		}

	while (!fila.empty()){
		ll v = fila.front();
		fila.pop();

		cost[leaf[v]] = max(cost[leaf[v]], h[v]);

		deg[v] = 0;

		for (auto x : adj[v])
			if (deg[x] > 0){
				deg[x]--;

				if (leaf[x] == 0){
					leaf[x] = leaf[v];
					pai[x] = v;
				}
				else{
					if (cost[leaf[x]] < cost[leaf[v]]){
						leaf[x] = leaf[v];
						pai[x] = v;
					}
				}

				if (deg[x] == 1)
					fila.push(x);
			}
	}	

	ll mx = 0;
	frr(i, n)
		mx = max(mx, h[i]);

	frr(i, n)
		if (h[i] == mx){
			for (auto x : adj[i])
				if (x != pai[i])
					dfs(x, i);
			cost[min_leaf] = h[i];
			break;
		}

	ll ans = 0;
	frr(i, n)
		ans += cost[i];

	cout<<ans<<endl;
}