#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

// #define endl '\n'
#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(), x.end()

typedef long long int ll;

#define int ll


const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 100 + 10;

ll stein[1<<11][MAXN], cst[1<<11];
ll memo[1<<6][1<<6];

ll n, m, k, nterm;

ll pd(int msk1, int msk2){
	if (__builtin_popcount(msk1) == k and __builtin_popcount(msk2) == k)
		return 0;

	ll &pdm = memo[msk1][msk2];
	if (pdm != -1)
		return pdm;

	pdm = INF;

	for (int i = 1; i < (1<<k); i++)
		if ((i & msk1) == 0)
			for (int j = 1; j < (1<<k); j++)
				if (((j & msk2) == 0) and __builtin_popcount(i) == __builtin_popcount(j)){
					int aux = (j<<k); // destino está kbits para direita
					aux |= i;

					pdm = min(pdm, cst[aux] + pd(msk1 | i, msk2 | j));
				}

	return pdm;
}


ll dist[MAXN][MAXN], to_vtx[55];

void solve(){
	cin>>n>>m>>k;

	fr(i, n)
		fr(j, n)
			dist[i][j] = INF;

	fr(i, m){
		int x,y,w;
		cin>>x>>y>>w;
		x--;
		y--;

		dist[x][y] = min(dist[x][y], w);		
		dist[y][x] = min(dist[y][x], w);
	}		

	fr(i, n)
		dist[i][i] = 0;

	fr(i, k)
		to_vtx[i] = i;
	fr(i, k)
		to_vtx[k + i] = n - 1 - i;		


// / memo[mask][v] custo da árvore de steiner
 // conectando vértices da mask com raiz v

	for (int l = 0; l < n; l++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				dist[i][j] = min(dist[i][j], dist[i][l] + dist[l][j]);


	nterm = 2 * k;
	memset(stein, INF, sizeof stein);
	for (int v = 0; v < n; v++)
		for (int t = 0; t < nterm; t++)
			stein[1<<t][v] = dist[v][to_vtx[t]];

	for (int msk = 1; msk < (1 << nterm); msk++) // steiner dp
		for (int v = 0; v < n; v++){
			for (int smsk = (msk - 1)&msk; smsk > 0; smsk = (smsk - 1) & msk)
				stein[msk][v] = min(stein[msk][v], stein[smsk][v] + stein[msk^smsk][v]);
			for (int u = 0; u < n; u++)
				stein[msk][u] = min(stein[msk][u], stein[msk][v] + dist[u][v]);	
		}		

	for (int mask = 1; mask < (1<<nterm); mask++){
		cst[mask] = INF;
		fr(v, n)
			cst[mask] = min(cst[mask], stein[mask][v]);
	}

	memset(memo, -1, sizeof memo);
	if (pd(0, 0) >= INF)
		cout<<"No solution"<<endl;
	else
		cout<<pd(0, 0)<<endl;
}


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}