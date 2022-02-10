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

#define INF 0x3f3f3f3f
const int MAXN = 1e3;
const int MAXM = 9e5;

int ned, first[MAXN], work[MAXN], dist[MAXN], q[MAXN];
int cap[MAXM], to[MAXM], nxt[MAXM];


void init(){
	memset(first, -1, sizeof first);
	ned = 0;
}

void add(int u, int v, int f){
	to[ned] = v, cap[ned] = f;
	nxt[ned] = first[u];
	first[u] = ned++;

	to[ned] = u, cap[ned] = 0;
	nxt[ned] = first[v];
	first[v] = ned++;
}

int dfs(int u, int f, int t){
	if (u == t) 
		return f;
	
	for (int &e = work[u]; e != -1; e = nxt[e]){
		int v = to[e];

		if (dist[v] == dist[u] + 1 and cap[e] > 0){
			int df = dfs(v, min(f, cap[e]), t);
			if (df > 0){
				cap[e] -= df;
				cap[e^1] += df;
				return df;
			}
		}
	}
	return 0;
}

bool bfs(int s, int t){
	memset(&dist, -1, sizeof dist);
	dist[s] = 0;
	int st = 0, en = 0;
	q[en++] = s;

	while (en > st){
		int u = q[st++];
		for (int e = first[u]; e != -1; e = nxt[e]){
			int v = to[e];

			if (dist[v] < 0 and cap[e] > 0){
				dist[v] = dist[u] + 1;
				q[en++] = v;
			}
		}
	}

	return dist[t] >= 0;
}

int dinic(int s, int t){
	int flow = 0, f;
	while (bfs(s, t)){
		memcpy(work, first, sizeof work);
		while (f = dfs(s, INF, t))
			flow += f;
	}
	return flow;
}

int n, m, a[MAXN], b[MAXN], s[MAXN], c[110][110];
int cnt;

void solve(){
	init();

	cin>>n>>m;

	frr(i, n)
		cin>>a[i]>>b[i]>>s[i];

	frr(i, n)
		frr(j, n)
			cin>>c[i][j];

	int src = 0;
	int snk = 2 * n + 1;

	int ans = 0;
	frr(i, n){
		add(src, i, (s[i] + m - 1)/m);
		add(i + n, snk, (s[i] + m - 1)/m);
		ans += (s[i] + m - 1)/m;
	}

	frr(i, n)
		frr(j, n)
			if (b[i] + c[i][j] < a[j]) // não pega o mesmo cara
				add(i, j + n, INF);

	ans -= dinic(src, snk);
	
	cout<<"Case "<<++cnt<<": "<<ans<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}