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
int first[MAXN],to[MAXM],nxt[MAXM],work[MAXN],q[MAXN];
long long int dist[MAXN],cap[MAXM];

void init() {
	ms( first, -1);
	ned = 0;
}

void add( int u, int v, ll f){
	to[ned] = v, cap[ned] = f;
	nxt[ned] = first[u];
	first[u] = ned++;
	
	to[ned] = u, cap[ned] = 0;
	nxt[ned] = first[v];
	first[v] = ned++;
}

ll dfs( int u, ll f, int t) {
	if (u == t) return f;
	for(int &e = work[u]; e != -1; e = nxt[e]) {
		int v = to[e];
		if (dist[v] == dist[u] + 1 && cap[e] > 0) {
			ll df = dfs(v, min(f, cap[e]), t);
			if (df > 0) {
				cap[e] -= df;
				cap[e^1] += df;
				return df;
			}
		}
	}
	return 0;
}

bool bfs( int s, int t) {
	memset(&dist, -1, sizeof dist);
	dist[s] = 0;
	int st = 0, en = 0;
	q[en++] = s;
	while (en > st) {
		int u = q[st++];
		for(int e = first[u]; e!=-1; e = nxt[e]) {
			int v = to[e];
			if (dist[v] < 0 && cap[e] > 0) {
				dist[v] = dist[u] + 1;
				q[en++] = v;
			}
		}
	}
	return dist[t] >= 0;
}

ll dinic( int s, int t) {
	ll flow = 0, c_flow;

	while (bfs( s, t)) {
		memcpy( work, first, sizeof work);
		while (c_flow = dfs( s, llINF, t))
			flow += c_flow;
	}

	return flow;
}

int main() {
	fastio;
	init();
		
	int n, m, src, snk;
	ll cost;
	cin>>n>>m;
	src = 0;
	snk = n + m + 1;

	ll c;
	frr(i,n) {
		cin>>c;
		add( m + i, snk, c);
	}

	cost = 0;
	int a, b;
	frr(i,m) {
		cin>>a>>b>>c;
		cost += c;
		add( src, i, c);
		add( i, a + m, llINF);
		add( i, b + m, llINF);
	}

	cost -= dinic( src, snk);

	cout<<(cost > 0 ? cost : 0)<<endl;
}