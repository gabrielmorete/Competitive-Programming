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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   

const int MAXN = 1e5 + 3000;
const int MAXM = 9e5;

int ned, first[MAXN], work[MAXN], dist[MAXN], q[MAXN];
int cap[MAXM], to[MAXM], nxt[MAXM];

int adj[300][300];

void init(){
   memset(first, -1, sizeof first);
   ned = 0;
}

void add(int u, int v, int f){
	to[ned] = v, cap[ned] = f;
	nxt[ned] = first[u];
	first[u] = ned++;
	
	adj[u][v] = ned - 1;

	to[ned] = u, cap[ned] = 0;
	nxt[ned] = first[v];
	first[v] = ned++;
}

int dfs(int u, int f, int t){
	if (u == t) return f;
	for (int &e = work[u]; e != -1; e = nxt[e]){
		int v = to[e];
		if (dist[v] == dist[u] + 1 && cap[e] > 0){
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
	memset(dist, -1, sizeof dist);
	dist[s] = 0;
	int st = 0, en = 0;
	q[en++] = s;
	while (en > st){
		int u = q[st++];
		for (int e = first[u]; e != -1; e = nxt[e]){
			int v = to[e];
			if (dist[v] < 0 && cap[e] > 0){
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

char ans[300][300];


int32_t main(){
	fastio;
	int t, p, st, sp, src, snk;

	cin>>t>>p;
	while (t != 0){
		init();

		src = st = sp = 0;
		snk = t + p + 3;

		int x;
		frr(i, t){
			cin>>x;
			st += x;
			add(src, i, x);
		}

		frr(j, p){
			cin>>x;
			sp += x;
			add(j + t, snk, x);
		}

		frr(i, t)
			frr(j, p)
				add(i, j + t, 1);

		int mf = dinic(src, snk);		
		

		if (sp != st or mf != sp){
			cout<<"Impossible"<<endl;
		}
		else{
			int a, b, c;
			for (int i = 1; i <= t; i++) // percorre em ordem lexico
				for (int j = 1; j <= p; j++){
					a = adj[src][i];
					b = adj[i][j + t];
					c = adj[j + t][snk];

					if (cap[b] > 0){
						cap[b] = cap[b ^ 1] = 0;
						ans[i][j] = 'N';
						continue;
					}

					// diminui fluxo em 1
					cap[a]++;
					cap[a^1]--;
					cap[b] = cap[b^1] = 0;
					cap[c]++;
					cap[c ^ 1]--;
					// checa se há um caminho que não usa aresta
					if (dinic(src, snk) == 0){//não aumentou
						cap[a]--; // 10x mais rápido do que redar outro dinic
						cap[c]--;
						ans[i][j] = 'Y';
					}
					else
						ans[i][j] = 'N';
				}

			frr(i, t){
				frr(j, p)
					cout<<ans[i][j];
				gnl;	
			}			
		}
		
		cin>>t>>p;
		if (t != 0)
			gnl;
	}
}