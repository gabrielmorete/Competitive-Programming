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
const int MAXN = 1e6 + 10;
const int LMAXN = 19;

int n, k, divi[MAXN];
int nxt[MAXN][LMAXN];
ll cst[MAXN][LMAXN];

int vis[MAXN], cicle[MAXN], szc[MAXN], nc;

void cicle_detec(int v){
	vis[v] = 1;
	
	if (vis[nxt[v][0]] == 1) // cicle
		cicle[v] = ++nc;
	else if (vis[nxt[v][0]] == 0)
		cicle_detec(nxt[v][0]);

	vis[v] = 2;
}

int dist[MAXN];
int calc_dist(int v){
	if (dist[v] != -1)
		return dist[v];
	if (cicle[v] != 0){
		dist[v] = 0;
		return dist[v];
	}

	return dist[v] = calc_dist(nxt[v][0]) + 1;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>k;

	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j += i)
			divi[j]++;

	for (int v = 0; v < n; v++){
		nxt[v][0] = (v + divi[v]) % n;
		cst[v][0] = v;
	}

	for (int i = 1; i < LMAXN; i++)
		for (int v = 0; v < n; v++){
			nxt[v][i] = nxt[ nxt[v][i - 1] ][i - 1];
			cst[v][i] = cst[v][i - 1] + cst[ nxt[v][i - 1] ][i - 1];
		}

	for (int v = 0; v < n; v++)
		if (vis[v] == 0)	
			cicle_detec(v);

	for (int v = 0; v < n; v++)
		if (cicle[v] > 0 and szc[cicle[v]] == 0){
			int u = nxt[v][0];
			int sz = 1;
			while (u != v){
				cicle[u] = cicle[v];
				sz++;
				u = nxt[u][0];
			}
			szc[cicle[v]] = sz;
		}	
	

	memset(dist, -1, sizeof dist);
	for (int v = 0; v < n; v++)
		calc_dist(v);

	ll ans = llINF;
	int vtx = -1;

	for (int v = 0; v < n; v++){
		int c = nxt[v][LMAXN - 1];

		if (szc[cicle[c]] + dist[v] >= k){
			ll aux = 0;
			int tam = k;
			int u = v;
			for (int j = LMAXN - 1; j >= 0; j--){
				if ((1<<j) <= tam){
					aux += cst[u][j];
					u = nxt[u][j];
					tam -= 1<<j;
				}
			}
			
			if (aux < ans){
				ans = aux;
				vtx = v;
			}
		}
	}

	if (vtx == -1)
		cout<<-1<<endl;
	else{
		for (int j = 0; j < k; j++){
			cout<<vtx<<' ';
			vtx = nxt[vtx][0];
		}
		gnl;
	}
}