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
const int MAXN = 5e3 + 10;

ll n, k, memo[MAXN][MAXN], sz[MAXN], aux[MAXN];
vi adj[MAXN];

void dfs(int v, int p){
	memo[v][1] = 1;
	sz[v] = 1;

	for (auto x : adj[v])
		if (x != p){
			dfs(x, v);
			
			fr(i, sz[v] + sz[x] + 2)
				aux[i] = 0;

			for (int i = 1; i <= sz[v]; i++)
				for (int j = 0; j <= sz[x]; j++){
					__int128 val = min((__int128)k, (__int128)(memo[v][i]) * (__int128)(memo[x][j]));
					aux[i + j] = min(k, aux[i + j] + (ll)(val));
				}
			
			fr(i, sz[v] + sz[x] + 2)
				memo[v][i] = aux[i];			

			sz[v] += sz[x];	
		}

	memo[v][0] = 1;	
}


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>k;

	int x, y;
	fr(i, n - 1){
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	dfs(1, 1);

	fr(i, n + 1)
		aux[i] = 0;

	fr(i, n + 1)
		fr(j, n + 1)
			aux[i] += memo[j][i];	

	frr(i, n + 1){
		k -= aux[i];
		if (k <= 0){
			cout<<i<<endl;
			return 0;
		}
	}

	cout<<-1<<endl;
}