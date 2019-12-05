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
const int LMAXN = 25;

int ned;
int first[MAXN], work[MAXN], dist[MAXN], q[MAXN];
int nxt[MAXM], cap[MAXM], to[MAXM];

void init() {
	memset( first, -1 , sizeof first);
	ned = 0;
}

void add( int u, int v, int f) {
	to[ned] = v; cap[ned] = f;
	nxt[ned] = first[u];
	first[u] = ned++;

	to[ned] = u; cap[ned] = 0;
	nxt[ned] = first[v];
	first[v] = ned++;
}

int dfs( int u, int t, int f) {
	if (u == t) return f;

	for (int &e = work[u]; e != -1; e = nxt[e]) {
		int v = to[e];
		if (dist[v] == dist[u] + 1 and cap[e] > 0) {
			int df = dfs( v, t, min(f,cap[e]));
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
	memset( dist, -1, sizeof dist);
	int st = 0, en = 0;
	dist[s] = 0;
	q[en++] = s;

	while (en > st) {
		int u = q[st++];

		for (int e = first[u]; e != -1; e = nxt[e]) {
			int v = to[e];
			if(dist[v] < 0 and cap[e] > 0){
				dist[v] = dist[u] + 1;
				q[en++] = v;
			}
		}
	}

	return dist[t] >= 0;
}

int dinic( int s, int t) {
	int res = 0, f;

	while (bfs( s, t)){
		memcpy( work, first, sizeof work);
		while (f = dfs( s, t , INF))
			res += f;
	}
	return res;
}

void solve() {
	init();
	int n, m;
	cin>>n>>m;

	int a, b;
	fr(i,m){
		cin>>a>>b;
		//Problem has input errors
		if (a > n or b > n)
			continue;

		add( a + n, b, 1);
		add( b + n, a, 1);
	}

	//double each vertex
	//add an edge of unity capacity to avoid double using the vertex
	frr(i,n) 
		add( i, i + n, 1);
	
	if (n < 3) {
		cout<<"NO"<<endl;
		return;
	}

	int snk = 0;
	add( 1 + n, snk, 1);
	add( 3 + n, snk, 1);

	if (dinic( 2 + n, snk) == 2)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}

int main(){
	fastio;
	int t;
	cin>>t;
	while (t--) solve();
}

/////////////////WARNING/////////////////
//this problem has weak testcases. The 
//solution below also got AC
// void solve() {
// 	init();
// 	int n, m;
// 	cin>>n>>m;
// 	int a, b;
// 	fr(i,m){
// 		cin>>a>>b;
// 		if (a > n or b > n)
// 			continue;
// 		add( a, b, 1);
// 		add( b, a, 1);
// 	}
// 	if (n < 3) {
// 		cout<<"NO"<<endl;
// 		return;
// 	}
// 	int snk = n + 1;
// 	add( 1, snk, 1);
// 	add( 3, snk, 1);
// 	if (dinic( 2, snk) == 2)
// 		cout<<"YES"<<endl;
// 	else
// 		cout<<"NO"<<endl;
// }
//It only checks if there are two edge disjoint paths
