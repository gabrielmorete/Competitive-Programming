#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 3e2 + 10;
const int MAXM = 9e4;

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
	memset(&dist, -1, sizeof dist);
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

int n, m;
int back_cap[MAXM]; // backup capacity
int pai[MAXN], fpai[MAXN], cuts[MAXN];
int mflow[MAXN][MAXN];

void find_cut(int v){ // constroi o corte
	cuts[v] = true;
	for (int e = first[v]; e != -1; e = nxt[e])
		if (!cuts[to[e]] and cap[e] > 0)
			find_cut(to[e]);
}

int min_cut(int s, int t){
	memset(cuts, 0, sizeof cuts);
	memcpy(cap, back_cap, sizeof cap);

	int flow = dinic(s, t); // qualquer algoritmo de fluxo
	find_cut(s);			// que computa uma rede residual

	return flow;
}

void gomory_hu(){
	memset(mflow, -1, sizeof mflow);
	memcpy(back_cap, cap, sizeof cap);
	fill(pai, pai + n + 1, 1); // começa com k_{1, n - 1}

	for (int s = 2; s <= n; s++){
		int t = pai[s];
		fpai[s] = min_cut(s, t);
		
		mflow[s][t] = mflow[t][s] = fpai[s];

		for (int v = s + 1; v <= n; v++)
			if (cuts[v] and pai[v] == t)
				pai[v] = s;

		for (int v = 1; v < s; v++)
			if (mflow[s][v] == -1)
				mflow[s][v] = mflow[v][s] = min(mflow[s][t], mflow[t][v]);
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	init();

	cin>>n>>m;

	int v, u, w;
	fr(i, m){
		cin>>v>>u>>w;
		add(u, v, w);
		add(v, u, w);
	}

	gomory_hu();

	int sum = 0; 
	for (int i = 1; i <= n; i++) // induction on tree size
		sum += fpai[i];          // take te edge with minimal cost
								 // solve te ptoblem on subtrees and concat
	
	vi ans(2), used(n + 1, 0);

	int mx = -1;
	for (int i = 1; i <= n; i++)         // If U have to go back in path the
		for (int j = i + 1; j <= n; j++) // edges that were already choosen 
			if (mflow[i][j] > mx){       // do not bottleneck the cost. Hence
				ans[0] = i;              // we sum all the edges costs only
				ans[1] = j;				 // once, and by the induction proof
				mx = mflow[i][j];        // this is optimun.
			}

	used[ans[0]] = used[ans[1]] = 1;		

	while (ans.size() < n){
		mx = -1;
		for (int i = 1; i <= n; i++)
			if (!used[i] and mflow[ans.back()][i] > mx){ // max cost, no bottlenecks
				v = i;									 //	for the next ones			
				mx = mflow[ans.back()][i];
			}
		ans.pb(v);
		used[v] = 1;	
	}			

	cout<<sum<<endl;
	for (int v : ans)
		cout<<v<<' ';
	gnl;
}