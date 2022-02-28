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
const ll llINF = (long long)(1e18) + 100;   

const int MAXN = 1e4 + 1000;
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

int n, m, deg[MAXN];
vii edges;

bool test(int d){
	init();

	int src = 0;
	int snk = m + n + 1;

	fr(i, m){
		add(src, i + 1, 1);

		add(i + 1, m + edges[i].fst, 1);
		add(i + 1, m + edges[i].snd, 1);
	}

	frr(i, n)
		add(m + i, snk, min(d, deg[i]));


	return dinic(src, snk) >= m;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;

	fr(i, m){
		int a, b;
		cin>>a>>b;
		deg[a]++;
		deg[b]++;
		edges.pb({a, b});
	}

	int ini = 0, fim = m, bst = m;


	while (ini <= fim){
		int meio = (ini + fim)/2;

		if (test(meio)){
			bst = meio;
			fim = meio - 1;
		}
		else
			ini = meio + 1;
	}

	test(bst);

	cout<<bst<<endl;

	frr(i, m){
		for (int e = first[i]; e != -1; e = nxt[e])
			if ((e%2 == 0) and cap[e] == 0){
				int a = edges[i - 1].fst;
				int b = edges[i - 1].snd;

				if (to[e] == a + m)
					cout<<a<<' '<<b<<endl;
				else
					cout<<b<<' '<<a<<endl;
			}
	}
}