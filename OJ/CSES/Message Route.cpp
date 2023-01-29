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

int n, m, dist[MAXN];
vi adj[MAXN], ans;

void bfs(int src){
	frr(i, n)
		dist[i] = -1;

	queue<int> fila;
	fila.push(src);
	dist[src] = 0;

	int v;
	while (!fila.empty()){
		v = fila.front();
		fila.pop();

		for (auto u : adj[v])
			if (dist[u] == -1){
				dist[u] = dist[v] + 1;
				fila.push(u);
			}
	}
}


void dfs(int v){
	ans.pb(v);
	
	if (v == n){
		cout<<ans.size()<<endl;
		for (auto x : ans)
			cout<<x<<' ';
		gnl;
		exit(0);
	}

	for (auto x : adj[v])
		if (dist[x] == dist[v] + 1)
			dfs(x);

	ans.pop_back();
	dist[v] = -1; // no cycle	
}


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>m;

	fr(i, m){
		int a, b;
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	bfs(1);
	dfs(1);

	cout<<"IMPOSSIBLE"<<endl;
}