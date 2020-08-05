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
const int MAXN = 2e5 + 10;
const ll mod=1e9+7;

int n, v[MAXN], ans[MAXN], dist[MAXN];
vi adj[MAXN];

queue<int> fila;

void bfs(){
	int aux;
	while (!fila.empty()){
		aux = fila.front();
		fila.pop();

		for (int x : adj[aux])
			if (dist[x] == -1){
				dist[x] = dist[aux] + 1;
				fila.push(x);
			}				
	}
}

int32_t main(){
	fastio;
	cin>>n;

	frr(i, n)
		cin>>v[i];

	frr(i, n){ // Reversed
		if (i + v[i] <= n)
			adj[i + v[i]].pb(i);
		if (i - v[i] >= 1)
			adj[i - v[i]].pb(i);
	}

	fill(ans, ans + MAXN, -1);	
	fill(dist, dist + MAXN, -1);

	// Pares
	frr(i, n)
		if (v[i] % 2){
			fila.push(i);
			dist[i] = 0;
		}
	bfs();
	
	frr(i, n)
		if (v[i] % 2 == 0)	
			ans[i] = dist[i];

	// Impares
	fill(dist, dist + MAXN, -1);	

	frr(i, n)
		if (v[i] % 2 == 0){
			fila.push(i);
			dist[i] = 0;
		}

	bfs();
	
	frr(i, n)
		if (v[i] % 2)	
			ans[i] = dist[i];	

	frr(i, n)
		cout<<ans[i]<<' ';
	gnl;
}