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
const int MAXN=100100;
const int MAXM=1001001;
const ll mod=1e9+7;
const int LMAXN = 20;

int ned;
int first[MAXN], to[MAXM], nxt[MAXM], work[MAXN], q[MAXN];
ll dist[MAXN], cap[MAXM];
vector<pii> ans;

void init() {
	ms( first, -1);
	ms( work, 0);
	ned = 0;
}

void add( int u, int v, ll f) {
	to[ned] = v, cap[ned] = f;
	nxt[ned] = first[u];
	first[u] = ned++;

	to[ned] = u, cap[ned] = 0;
	nxt[ned] = first[v];
	first[v] = ned++;
}

ll dfs( int u, ll f, int t) {
	if (u==t) return f;
	for (int &e = work[u]; e != -1; e = nxt[e]) {
		int v = to[e];
		if (dist[v] == dist[u] + 1 and cap[e] > 0) {
			ll df = dfs( v, min( f, cap[e]), t);
			if (df > 0){
				cap[e] -= df;
				cap[e^1] += df;
				return df;
			}
		}
	}
	return 0;
}

bool bfs( int s, int t) {
	ms( dist, -1);
	dist[s] = 0;
	int st = 0, en = 0;
	q[en++] = s;
	while (en > st) {
		int u = q[st++];
		for (int e = first[u]; e != -1; e = nxt[e]) {
			int v = to[e];
			if (dist[v] < 0 and cap[e] > 0) {
				dist[v] = dist[u] + 1;
				q[en++] = v;
			}
		}
	}
	return dist[t] >= 0;	
}

bool vis[70];
void dfs2( int u){
	vis[u] = 1;
	for (int e = first[u]; e != -1; e = nxt[e]) {
		if( cap[e] > 0 and vis[to[e]] == 0 )
			dfs2(to[e]);
	}
}

ll dinic( int s, int t) {
	ll flow = 0, c_flow;
	while (bfs( s, t)) {
		memcpy( work, first, sizeof work);
		while (c_flow = dfs( s, llINF, t)){
			flow += c_flow;
		}
	}

	return flow;
}


int main() {
	int n, m, s, t, f;
	cin >> n >> m;

	while (n != 0){
		init();
		fr(i,m){
			cin>>s>>t>>f;
			add( s, t, f);
			add( t, s, f);
		}
		
		dinic( 1, 2);
		
		ans.clear();
		ms(vis,0);
		dfs2(1);

		frr(u,n){
			for (int e = first[u]; e != -1; e = nxt[e],e = nxt[e]) {
				if (vis[u] and !vis[to[e]])
					ans.pb({u,to[e]});
			}
		}

		for (auto x : ans)
			cout<<x.fst<<' '<<x.snd<<endl;
		gnl;
		
		cin >> n >> m;
	}	
}