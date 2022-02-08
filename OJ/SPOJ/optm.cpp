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
const int MAXN = 2e3;
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

bool know[MAXN], vis[MAXN];
int ans[MAXN], id[MAXN];
vii edges;

void recover(int v, int bit){
	vis[v] = 1;
	ans[v] |= (1<<bit);

	for (int e = first[v]; e != -1; e = nxt[e]){
		if (((e&1) == 0) and cap[e] > 0 and !vis[to[e]]) // real edge
			recover(to[e], bit);
	}
}

void solve(){
	edges.clear();
	int n, m, k;

	cin>>n>>m;	

	fr(i, m){
		int x, y;
		cin>>x>>y;
		edges.pb({x, y});
	}

	frr(i, n){
		know[i] = 0;
		ans[i] = 0; // inicia todos os bits zero, só coloca 1 em quem precisa
	}


	cin>>k;

	fr(i, k){
		int u, p;
		cin>>u>>p;

		ans[u] = p;
		know[u] = 1;
	}


	for (int bit = 0; bit < 31; bit++){
		init();

		int src = 0; // esse é o nó que tem os 1
		int snk = n + 1; // esse tem os zeros

		frr(i, n){
			vis[i] = 0;
			id[i] = i;
			if (know[i]){
				if (ans[i] & (1<<bit)) // esse cara tem 1
					id[i] = src;
				else
					id[i] = snk;
			}
		}

		for (auto e : edges){
			add(id[e.fst], id[e.snd], 1);
			add(id[e.snd], id[e.fst], 1);
		}		

		dinic(src, snk);
		recover(src, bit);
	}

	frr(i, n)
		cout<<ans[i]<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}