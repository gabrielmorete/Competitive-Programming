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

int ned, first[MAXN], work[MAXN], dist[MAXN], q[MAXN];
int cap[MAXM], to[MAXM], nxt[MAXM];
int ans[111][111];

void init() {
	ms( first, -1);
	ned = 0;
}

void add( int u, int v, int f) {
	to[ned] = v, cap[ned] = f;
	nxt[ned] = first[u];
	first[u] = ned++;

	to[ned] = u, cap[ned] = 0;
	nxt[ned] = first[v];
	first[v] = ned++;
}

int dfs( int u, int f, int t) {
	if (u == t) return f;
	for (int &e = work[u]; e != -1; e = nxt[e]) {
		int v = to[e];
		if (dist[v] == dist[u] + 1 and cap[e] > 0) {
			int df = dfs( v, min(f, cap[e]), t);
			if (df > 0) {
				cap[e] -= df;
				cap[e^1] += df;
				return df;
			}
		}
	}
	return 0;
}

bool bfs( int s, int t){
	ms(dist,-1);
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

int dinic( int s, int t) {
	int res = 0, f;
	while (bfs( s, t)) {
		memcpy( work, first, sizeof work);
		while (f = dfs( s, INF, t))
			res += f;
	}
	return res;
}

int main(){
	fastio;
	init();

	int n, m, src, snk, a[111], b[111], tot = 0, tt = 0;
	cin>>n>>m;
	src = 0;
	snk = 2*n + 1;

	frr(i,n){
		cin>>a[i];
		tt += a[i];
	}
	frr(i,n){
		cin>>b[i];
		tot += b[i];
	}
	
	if ( tt != tot){
		cout<<"NO"<<endl;
		return 0;
	}

	int x, y;
	fr(i,m){
		cin>>x>>y;
		add( x, n + y, 100);
		add( y, n + x, 100);
	}		
	frr(i,n){
		add( src, i, a[i]);
		add( i + n, snk, b[i]);
		add( i, i + n, 100);
	}
	int mf = dinic( src, snk);
	cout<<(mf == tot ? "YES" : "NO")<< endl;
	
	if (mf != tot)
		return 0;

	frr(v,n)
		for(int e = first[v + n]; e != -1; e = nxt[e]) {
			if (to[e] == snk)
				continue;
			ans[to[e]][v] = cap[e];
		}


	frr(i,n){
		frr(j,n)
			cout<<ans[i][j]<<' ';
		gnl;	
	}

}