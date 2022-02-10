#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = (int)n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int,int> pii;

#define mem(v, k) memset(v, k, sizeof(v));
#define db cout << "Debug" << endl;
#define all(x) begin(x), end(x)
#define dbg(x)  cout << #x << " = " << x << endl
#define dbgv(v)  cout << #v << " = "; for(auto x : v) cout << x << " "; cout << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define random mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define myrand(a, b) uniform_int_distribution<int>(a, b)(rng)
#define ioFile freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);

#define mp make_pair
#define pq priority_queue

const int MAXN = 1e6;
const int MAXM = 3e6;

#define MOD 1000000007
#define INF 0x3f3f3f3f

int ned, fst[MAXN], work[MAXN], dist[MAXN], q[MAXN];
int cap[MAXM], to[MAXM], nxt[MAXM];

void init(){
	memset(fst, -1, sizeof fst);
	ned = 0;
}

void add(int u, int v, int f){
	to[ned] = v, cap[ned] = f;
	nxt[ned] = fst[u];
	fst[u] = ned++;

	to[ned] = u, cap[ned] = 0;
	nxt[ned] = fst[v];
	fst[v] = ned++;
}

int dfs(int u, int f, int t){
	if(u == t) return f;
	for(int & e = work[u]; e != -1; e = nxt[e]){
		int v = to[e];
		if(dist[v] == dist[u] + 1 && cap[e] > 0){
			int df = dfs(v, min(f, cap[e]), t);
			if(df > 0){
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
	while(en > st){
		int u = q[st++];
		for(int e = fst[u]; e != -1; e = nxt[e]){
			int v = to[e];
			if(dist[v] < 0 && cap[e] > 0){
				dist[v] = dist[u] + 1;
				q[en++] = v;
			}
		}
	}

	return dist[t] >= 0;
}

int dinic(int s, int t){
	int flow = 0, f;
	while(bfs(s, t)){
		memcpy(work, fst, sizeof work);
		while(f = dfs(s, INF, t)) flow += f;
	}
	return flow;
}

int n, m;
char v[510][510];
int vtx(int r, int c){
	return m * r + c;
}
bool inside(int r, int c){
	if(r >= 0 && r < n && c < m && c >= 0 && v[r][c] == 'W') return true;
	else return false;
}
int mx[4] = {0, 0, 1, -1};
int my[4] = {1, -1, 0, 0};

void solve(){
	init();
	cin >> n >> m;
	fr(i, n) fr(j, m) cin >> v[i][j];

	int b = 0, w = 0, src = n * m, snk = n * m + 1;
	
	fr(i, n) 
	    fr(j, m) 
	        if(v[i][j] == 'B') {
	        	add(vtx(i, j), snk + 1 + b, 1);

	        	fr(k, 4){
		        	if(inside(mx[k] + i, my[k] + j)){
			        	if((mx[k] + i)%2) 
				        	add(vtx(mx[k] + i, my[k] + j), vtx(i, j), 1);
				        else
					        add(snk + 1 + b, vtx(mx[k] + i, my[k] + j), 1);
			        }
		        }

		        b++;
	        }

	fr(i, n) 
		fr(j, m) 
		if(v[i][j] == 'W'){
			w++;
			if(i%2) add(src, vtx(i, j), 1);
			else add(vtx(i, j), snk, 1);
	}

	//dbg(dinic(src, snk));

	if(2 * b != w) cout << "NO" << '\n';
	else cout << ((dinic(src, snk) == b) ? "YES" : "NO") << '\n';
}


signed main(){
	fastio;
	int t;
	cin >> t;

	while(t--) solve();
}
