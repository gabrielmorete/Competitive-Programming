#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 500100;
const int MAXM = 1001000;
const ll mod=1e9+7;
const int LMAXN = 25;

int n, sz[MAXN];
ll m;
vi adj[MAXN];

int lp[MAXN], pr[MAXN], np;

void crivo(){
	for (int i = 2; i < MAXN; i++){
		if (lp[i] == 0){
			lp[i] = i;
			pr[np++] = i;
		}
		for (int j = 0; j < np and pr[j] <= lp[i] and i*pr[j] <= MAXN; j++)
			lp[i * pr[j]] = pr[j];
	}
}

int dfs(int v){
	int aux = 1;
	for (int x : adj[v])
		aux += dfs(x);
	sz[v] = aux;
	return aux;
}

int factor[MAXN];


void solve(){
	scanf("%d %lld", &n, &m);

	fr(i,n + 1)
		adj[i].clear();

	int a;	
	fr(i,n - 1){
		scanf("%d", &a);
		adj[a].pb(i + 2);	
	}

	dfs(1);

	fr(i, MAXN)
		factor[i] = 0;

	int aux;	
	for (int i = 2; i <= n - 1; i++){
		aux = i;
		while (aux > 1){
			factor[lp[aux]]++;
			aux /= lp[aux];
		}
	}
	

	for (int i = 2; i <= n; i++){
		aux = sz[i];
		while (aux > 1){
			factor[lp[aux]]--;
			aux /= lp[aux];
		}
	}

	ll ans = 1;
	for (ll i = 0; i < MAXN; i++){
		while (factor[i]){
			factor[i]--;
			ans = (ans * i) % m;
		}
	}
	printf("%lld\n", ans);
}

int main(){
	crivo();

	int t;
	scanf("%d", &t);

	while(t--)
		solve();
}