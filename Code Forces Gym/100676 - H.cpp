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

vector< pair<ll,ll> > adj[MAXN], adjbcc[MAXN];
ll pre[MAXN], lo[MAXN], pa[MAXN], stk[MAXN];
ll n, m;
ll t, cnt, id;
ll bcc[MAXN];

void dfsRebcc( ll v) {
	pre[v] = cnt++;
	stk[t++] = v;
	lo[v] = pre[v];
	for (pair<ll,ll> x : adj[v]) {
		ll  w = x.fst;
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
			ll u;
		do {
			u = stk[--t];
			bcc[u] = id;
		} while (u != v);
	id++;
	}
}

ll ebcc( ) {
   for (ll v = 1; v <= n ; ++v)
      pre[v] = -1;
   t = cnt = id = 0;
   for (ll v = 1; v <= n ; ++v)
      if (pre[v] == -1) { 
         pa[v] = v;
         dfsRebcc( v);
      }
   return id;
}

void build_ebcc_graph() {
	for (ll v = 1; v <= n; v++)
		for (auto x : adj[v]){
			if (bcc[v] != bcc[x.fst])
				adjbcc[bcc[v]].push_back({bcc[x.fst], x.snd});
	}
}


ll dist[MAXN];

void dfs(ll v, ll dst) {
	dist[v] = dst;
	for (auto x : adjbcc[v]){
		if (dist[x.fst] != -1)
			continue;
		pa[x.fst] = v;
		dfs( x.fst, dst + x.snd);
	}
}

ll md(ll a){
	if(a < 0)
		return -a;
	return a;
}

ll menorkrai[MAXN];
void solve(){
	cin>>n>>m;

	fr(i,n+10){
		adj[i].clear();
		adjbcc[i].clear();
	}

	ll a,b,c;
	fr(i,m) {
		cin>>a>>b>>c;
		adj[a].pb({b,c});
		adj[b].pb({a,c});
	}

	//get bicconected componentes
	ll k = ebcc();

	if (k == 1){
		cout<<1<<' '<<0<<endl;
		return;
	}

	//build biconnected components graph	
	build_ebcc_graph();

	ll bst, dbst, dend, end, start;


	//find max dist in a tree
	ms(dist,-1);
	pa[0] = 0;
	dfs( 0, 0);
	
	dend = -1;
	fr(i,k) {
		if(dist[i] > dend) {
			dend = dist[i];
			end = i;
		}
	}


	start = end;


	ms(dist,-1);
	pa[start]=start;
	dfs( start, 0);

	dend = -1;
	fr(i,k) {
		if(dist[i] > dend) {
			dend = dist[i];
			end = i;
		}
	}

	//get lowest index node for each component
	fr(i,k) menorkrai[i] = INF;
	frr(i,n) menorkrai[bcc[i]] = min<ll>(menorkrai[bcc[i]],i);


	//get minimum max dist node
	int v = end;
	dbst = llINF;
	bst = llINF;
	while (true) {
		if ( dbst > max( dist[v], md(dist[end] - dist[v]) ) ) {
			dbst = max( dist[v], md(dist[end] - dist[v]) );
			bst = menorkrai[v];
		}
		if (dbst == max( dist[v], md(dist[end] - dist[v]) ) and menorkrai[v] < bst) {
			bst = menorkrai[v];
		}
		if (v == pa[v]) 
			break;
		v = pa[v];
	}	

	cout<<bst<<' '<<dbst<<endl;	

}

int main() {
	fastio;
	int T;
	cin>>T;
	while (T--) solve();
	
}	