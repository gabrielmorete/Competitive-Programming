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
const ll mod=1e9+7;

#define MAXN 103000
#define MAXM 900000

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


void solve(){
	int m, n, a, b, ans[55][55];
	cin>>n>>m>>a>>b;
 
	if (n * a != m * b){
		cout<<"NO"<<endl;
		return;
	}
 
	frr(i, n)
		frr(j, m)
			ans[i][j] = 0;
 
	init();

	int str, end;
	str = 0;
	end = n + m + 1;

	frr(i, n)
		add(str, i, a);
	
	frr(i, n)
		frr(j, m)
			add(i, n + j, 1);	

	frr(j, m)
		add(n + j, end, b);

	dinic( str, end);

	frr(i, n){
		int aux = first[i];
		while (aux != -1){
			if (cap[aux] == 0)
				ans[i][to[aux] - n] = 1;
			aux = nxt[aux];
		}
	}
 
	cout<<"YES"<<endl;
 
	frr(i, n){
		frr(j, m)
			cout<<ans[i][j];
		gnl;	
	}
}
 
int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}