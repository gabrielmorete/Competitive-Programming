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
const int MAXN = 100100;
const int MAXM = 1001000;
const ll mod=1e9+7;
const int LMAXN = 20;

int ned;
int first[MAXN], work[MAXN], dist[MAXN], q[MAXN];
int to[MAXM], nxt[MAXM];
ll cap[MAXN];

void init() {
	ms(first, -1);
	ned = 0;
}

void add( int u, int v, ll f) {
	to[ned] = v, cap[ned] = f;
	nxt[ned] = first[u];
	first[u] = ned++;

	to[ned] = u; cap[ned] = 0;
	nxt[ned] = first[v];
	first[v] = ned++;
}

ll dfs( int u, ll f, int t) {
	if (u == t) return f;
	int v;
	ll df;

	for (int &e = work[u]; e != -1; e = nxt[e]) {
		v = to[e];
		if (dist[v] == dist[u] + 1 and cap[e] > 0) {
			df = dfs( v, min<ll>(f, cap[e]), t);
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
	int st = 0, en = 0;
	dist[s] = 0;
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

ll dinic( int s, int t) {
	int res = 0, f;
	while (bfs( s, t)) {
		memcpy( work, first, sizeof work);
		while (f = dfs( s, llINF, t))
			res += f;
	}
	return res;
}

void solve( int m, int w) {
	init();
	int src, snk;
	src = 1;
	snk = m;

	int x, y;
	ll c;
	fr(i,m-2){
		cin>>x>>c;
		add( x, x + m, c);
	}
	add( src, src + m, llINF);
	add( snk, snk + m, llINF);

	fr(i,w){
		cin>>x>>y>>c;
		add( x + m, y, c);
		add( y + m, x, c);	
	}

	cout<<dinic( src, snk)<<endl;

}

int main(){
	fastio;
	int m, w;
	cin>>m>>w;
	while (m != 0) {
		solve( m, w);
		cin>>m>>w;
	}
	return 0;
}