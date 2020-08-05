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
//cout << setprecision(9)<<fixed;

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const ll MAXN = 1e6 + 10;

int lp[MAXN];
vector<int> pr;

void crivo(){
	for (ll i = 2; i < MAXN; i++) {
	    if (lp[i] == 0) {
	        lp[i] = i;
	        pr.push_back(i);
	    }
	    for (ll j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] < MAXN; ++j)
	        lp[i * pr[j]] = pr[j];
	}
}

int n, dist[MAXN];
vi adj[MAXN], dcp[MAXN]; 
vii edge;

int other(int idx, int u){
	return edge[idx].fst == u ? edge[idx].snd : edge[idx].fst;
}

int bfs(int p){
	memset(dist, 0, sizeof(dist));

	queue<pii> fila;

	for (int x : adj[p]){
		fila.push({x, other(x, p)});
		dist[other(x, p)] = 1;
	}

	int u, v, ans = INF;
	pii aux;
	while (!fila.empty()){
		aux = fila.front();
		fila.pop();
		u = aux.snd;

		for (int w : adj[u]){
			if (w != aux.fst){
				v = other(w, u);

				if (dist[v] == 0 and v != p){
					fila.push({w, v});
					dist[v] = dist[u] + 1;
				}
				else
					ans = min(ans, dist[u] + dist[v] + 1);
			}
		}
	}

	return ans;	
}

int32_t main(){
	fastio;
	crivo();
	lp[1] = 1;	

	cin>>n;

	for (int i = 2; i < MAXN; i++){
		dcp[i] = dcp[i / lp[i]];
		auto it = find(all(dcp[i]), lp[i]);
		
		if (it != dcp[i].end())
			dcp[i].erase(it);
		else
			dcp[i].pb(lp[i]);
	}

	int a;
	fr(i, n){
		cin>>a;

		if (dcp[a].empty()){
			cout<<1<<endl;
			return 0;
		}

		if (dcp[a].size() == 1)
			dcp[a].pb(1);

		edge.pb({dcp[a][0], dcp[a][1]});
		adj[dcp[a][0]].pb(i);
		adj[dcp[a][1]].pb(i);
	}

	int ans = INF;

	pr.insert(pr.begin(), 1);

	for (int p : pr){
		if (p * p > MAXN)
			break;
	
		ans = min(ans, bfs(p));
	}	

	cout<<(ans == INF? -1 : ans)<<endl;
}