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
const ll mod = 998244353;

ll memo[MAXN][MAXN], tmp[MAXN]; // number of subtrees of v with longest decreasing path i
ll n, k;
vi adj[MAXN];

int dfs(int v, int p){
	int h = 0; // longest path below me
	memo[v][0] = 1;
	for (int u : adj[v])
		if (u != p){
	
			int hf = dfs(u, v);
			fill(tmp, tmp + max(h, hf) + 2, 0); // temporary array

			for (int i = 0; i <= h; i++)
				for (int j = 0; j <= hf; j++){
					
					if (i + j + 1 <= k){ // + 1 for my children, the other edge was considered before
						ll aux = (memo[v][i] * memo[u][j]) % mod; // # of paths with i + j + 1 crossing old and the new subtree
						tmp[max(i, j + 1)] = (tmp[max(i, j + 1)] + aux) % mod;
					}
					
					if (i <= k and j <= k){ // cutting edges from new child
						ll aux = (memo[v][i] * memo[u][j]) % mod;
						tmp[i] = (tmp[i] + aux) % mod;
					}
				}
			h = max(h, hf + 1);		
			for (int i = 0; i <= h; i++)
				memo[v][i] = tmp[i];
		}

	return h;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>k;

	int a, b;
	fr(i, n - 1){
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	dfs(1, 1);

	ll ans = 0;
	for (int i = 0; i <= k; i++)
		ans = (ans + memo[1][i]) % mod;

	cout<<ans<<endl;
}