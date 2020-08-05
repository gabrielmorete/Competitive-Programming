#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 500100;
const int MAXM = 1001000;
const ll mod=1e9+7;
const int LMAXN = 25;

vector< pair<int,int> > adj[MAXN], adjbcc[MAXN];
int pre[MAXN], lo[MAXN], pa[MAXN], stk[MAXN];
int n, m;
int t, cnt, id;
int bcc[MAXN];

void dfsRebcc( int v) {
	pre[v] = cnt++;
	stk[t++] = v;
	lo[v] = pre[v];
	for (pair<int,int> x : adj[v]) {
		int  w = x.fst;
		if (pre[w] == -1) { 
			pa[w] = v; 
			dfsRebcc( w); 
			if (lo[w] < lo[v]) 
			lo[v] = lo[w]; 
			} else { 
		if (w != pa[v] && pre[w] < lo[v]) 
			lo[v] = pre[w]; 
		} 
	} 
		if (lo[v] == pre[v]) { 
			int u;
		do {
			u = stk[--t];
			bcc[u] = id;
		} while (u != v);
	id++;
	}
}

int ebcc( ) {
   for (int v = 0; v < MAXN; ++v)
      pre[v] = -1;
   t = cnt = id = 0;
   for (int v = 1; v < MAXN; ++v)
      if (pre[v] == -1) { 
         pa[v] = v;
         dfsRebcc( v);
      }
   return id;
}

vii edges;
int tresure[MAXN];

int vis[MAXN];

void build_ebcc_graph() {
	for (int v = 1; v <= n; v++)
		for (auto x : adj[v]){
			if (bcc[v] != bcc[x.fst])
				adjbcc[bcc[v]].push_back({bcc[x.fst], x.snd});
			else if(x.snd)
				tresure[bcc[v]] = 1; //tem tesouro na componente
	}
}



void dfs(int v, bool ok) {
	ok |= tresure[v];
	vis[v] = ok;

	for (auto x : adjbcc[v]){
		if (vis[x.fst] != -1)
			continue;
		dfs( x.fst, ok || x.snd);
	}
}

int main() {
	fastio;
	cin>>n>>m;

	int a,b,c;
	fr(i,m) {
		cin>>a>>b>>c;
		adj[a].pb({b,c});
		adj[b].pb({a,c});
		if (c)
			edges.pb({a,b});

	}

	cin>>a>>b;
	int k = ebcc();

	//monta grafo de ebcc
	build_ebcc_graph();

	if (bcc[a] == bcc[b]){ //tesouro na componente de a e b;
		cout<<(tresure[bcc[a]] ? "YES" : "NO")<<endl;
		return 0;
	}

	ms(vis,-1);
	dfs( bcc[a], 0);
	cout<<(vis[bcc[b]] ? "YES" : "NO" )<<endl;

}	