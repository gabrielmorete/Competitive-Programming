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
//cout << setprecision(9)<<fixed;

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 100100;
const int MAXM = 1001000;
const ll mod=1e9+7;
const int LMAXN = 25;

int ned, first[MAXN], work[MAXN], dist[MAXN], q[MAXN];
int cap[MAXM], to[MAXM], nxt[MAXM];

void init() {
   memset(first, -1, sizeof first);
   ned = 0;
}

void add(int u, int v, int f) {
	to[ned] = v, cap[ned] = f;
	nxt[ned] = first[u];
	first[u] = ned++;
	
	to[ned] = u, cap[ned] = 0;
	nxt[ned] = first[v];
	first[v] = ned++;
}

int dfs(int u, int f, int t) {
	if (u == t) return f;
	for(int &e = work[u]; e != -1; e = nxt[e]) {
		int v = to[e];
		if (dist[v] == dist[u] + 1 && cap[e] > 0) {
			int df = dfs(v, min(f, cap[e]), t);
			if (df > 0) {
				cap[e] -= df;
				cap[e^1] += df;
				return df;
			}
		}
	}
	return 0;
}

bool bfs(int s, int t) {
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

int dinic(int s, int t) {
	int result = 0, f;
	while (bfs(s, t)) {
		memcpy(work, first, sizeof work);
		while (f = dfs(s, INF, t)) result += f;
	}
	return result;
}

int src, snk, n, match[212];
bool cover[212], vis[212];
void dfsm(int v) {
	vis[v] = 1;
	for (int e = first[v]; e != -1; e = nxt[e]) {
		if (to[e] != src and cap[e] and !vis[to[e]]){
			vis[to[e]] = 1;
			if (match[to[e]] != -1)
			dfsm(match[to[e]]);
		}
	}		
}

int main(){
	fastio;
	init();
	int m[112][112];

	cin>>n;

	int x;
	frr(i,n)
		frr(j,n){
			cin>>m[i][j];
		}
	
	src = 0;
	snk = 2*n + 1;

	frr(k,n)
		frr(i,n)
			frr(j,n)
				m[i][j] |= m[i][k]&m[k][j];

	frr(i,n){
		frr(j,n){
			if (m[i][j] and i != j)
				add( i, j + n, 1);
		}
	}

	frr(i,n)
		add( src, i, 1), add( i + n, snk, 1);	

	cout<< n - dinic( src, snk)<< endl;			

	ms(vis, 0);
	ms(cover, 0);
	ms(match, -1);

	for (int i = 1; i <= n; i++)
		for (int e = first[i]; e != -1; e = nxt[e])
			if (!cap[e] and to[e] != src)
				 match[i] = to[e], match[to[e]] = i;

	for (int e = first[src]; e != -1; e = nxt[e]) {
		if (cap[e]) {
			vis[to[e]] = 1;
			for (int a = first[to[e]]; a != -1; a = nxt[a]) {
				if (to[a] != src) {
					vis[to[a]] = 1;
					if (match[to[a]] != -1)
						dfsm(match[to[a]]);
				}
			}	
		}
	}

	for (int i = 1; i <= n; i++)
		if (!vis[i])
			cover[i] = 1;	

	for (int i = n + 1; i <= 2*n; i++)
		if (vis[i])
			cover[i] = 1;	

	bool ans[212];
	ms( ans, 0);

	for (int i = 1; i <= n; i++)
		if (cover[i])
			ans[i] = 1;

	for (int i = n + 1; i <= 2*n; i++)
		if (cover[i])
			ans[i - n] = 1;	
	
	for (int i = 1; i <= n; i++)
		if (!ans[i])
			cout<<i<<' ';
	gnl;	
}