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
	for (int &e = work[u]; e != -1; e = nxt[e]) {
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
		for (int e = first[u]; e!=-1; e = nxt[e]) {
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
	int flow = 0, f;
	while (bfs(s, t)) {
		memcpy(work, first, sizeof work);
		while (f = dfs(s, INF, t)) 
			flow += f;
	}
	return flow;
}


int mx[4] = {1, -1, 0, 0};
int my[4] = {0, 0, 1, -1};
int r, c;
char mapa[50][50];

bool valid(int x, int y){
	if (x < 0 or y < 0)
		return false;
	if (x >= r or y >= c)
		return false;
	return true;
}

void dfs_fill(int x, int y){
	mapa[x][y] = 'W';

	int i, j;
	fr(k, 4){
		i = x + mx[k];
		j = y + my[k];

		if (valid(i, j)){
			if (mapa[i][j] == 'L')
				dfs_fill(i, j);
			else if (mapa[i][j] == 'C')
				mapa[i][j] = 'W';
		}
	}
}

int32_t main(){
	fastio;

	init();

	cin>>r>>c;

	string s;
	fr(i, r){
		cin>>s;
		fr(j, c)
			mapa[i][j] = s[j];
	}

	int ans = 0;
	fr(i, r)
		fr(j, c)
			if (mapa[i][j] == 'L'){
				dfs_fill(i, j);
				ans++;
			}

	int src, snk; 
	src = r * c + 1;
	snk = src + 1;		

	int aux = 0;

	int x, y;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++){
			if (mapa[i][j] != 'C')
				continue;

			aux++;

			if ((i + j) % 2){
				add(src, i * c + j, 1);
				fr(k, 4){
					x = i + mx[k];
					y = j + my[k];
					if (valid(x, y))
						add(i * c + j, x * c + y, 1);
				}
			}
			else
				add(i * c + j, snk, 1);
		}

	aux -= dinic(src, snk);	

	cout<<ans + aux<<endl;			
}