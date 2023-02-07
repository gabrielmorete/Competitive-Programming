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

int n, m;
vector<int> adj[MAXN];
vector<array<int, 3>> edges;

ll dist[MAXN], p[MAXN];

void bellman(){

	fr(i, n)
		for (auto e : edges)
			dist[e[1]] = min(dist[e[1]], dist[e[0]] + e[2]);

	fr(i, n)	
		for (auto e : edges)
			if (dist[e[1]] > dist[e[0]] + e[2]){
				if (p[e[1]] == 0){
					p[e[1]] = e[0];
					dist[e[1]] = min(dist[e[1]], dist[e[0]] + e[2]);
				}
			}
}

int vis[MAXN];

void dfs(int v){
	vis[v] = 1;

	if (vis[p[v]] == 1){
		int u = v;
		vi ans;
		do{
			ans.pb(u);
			u = p[u];
		} while (u != v);

		cout<<"YES"<<endl;
		ans.pb(v);
		while (!ans.empty()){
			cout<<ans.back()<<' ';
			ans.pop_back();
		}
		gnl;

		exit(0);
	}

	dfs(p[v]);
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;

	fr(i, m){
		int a, b, c;
		
		cin>>a>>b>>c;

		edges.pb({a, b, c});
		adj[a].pb(i);
	}

	bellman();

	bool ok = 1;
	frr(i, n)
		if (p[i] != 0)
			ok = 0;

	if (ok == 1)
		cout<<"NO"<<endl;
	else{
		frr(i, n)
			if (p[i] != 0)
				dfs(i);
	}	
}