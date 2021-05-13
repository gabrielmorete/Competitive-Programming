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
const int MAXN = 1e5 + 10;
const ll mod = 1e9 + 7;

ll n, memo[MAXN][3], pre[MAXN][3], suf[MAXN][3], t[MAXN];
vi adj[MAXN], filho[MAXN];

void dfs(int v, int p){
	for (auto x : adj[v])
		if (x != p){
			filho[v].pb(x);
			dfs(x, v);
		}
		
}

void calc(int v){
	int k = filho[v].size();
	t[k - 1] = 0;
	for (int i = k - 1; i > 0; i--){ // propaga resposta
		int x = filho[v][i];
		t[i - 1] = (t[i] * memo[x][2]) % mod;
		ll aux = memo[x][1];
		if (i != k - 1)
			aux = (aux * suf[i + 1][2]) % mod;
		t[i - 1] = (t[i - 1] + aux) % mod;
	}
}

// 0 - Acabou no meu pai (não pode começar em mim!)
// 1 - Vou continuar meu pai
// 2 - Meu pai está no meio

void pd(int v){
	if (filho[v].empty()){
		memo[v][0] = 0;
		memo[v][1] = 1;
		memo[v][2] = 1;
		return;
	}

	for (auto x : filho[v])
		pd(x);

	int k = filho[v].size();
	fr(i, k){
		int x = filho[v][i];
		fr(j, 3){
			if (i == 0)
				pre[i][j] = memo[x][j];
			else
				pre[i][j] = (pre[i - 1][j] * memo[x][j]) % mod;
		}
	}

	for (int i = k - 1; i >= 0; i--){
		int x = filho[v][i];
		fr(j, 3){
			if (i == k - 1)
				suf[i][j] = memo[x][j];
			else
				suf[i][j] = (suf[i + 1][j] * memo[x][j]) % mod;
		}
	}

	calc(v);


	fr(j, 3){
		ll &pdm = memo[v][j];
		pdm = 0;

		if (j == 0){
			fr(i, k){
				int x = filho[v][i];
				ll aux = memo[x][1];
				if (i) aux = (aux * pre[i - 1][2])%mod;
				aux = (aux * t[i]) % mod;
				pdm = (pdm + aux) % mod;
			}
		}
		else if (j == 1){
			pdm = suf[0][0];
			fr(i, k){
				int x = filho[v][i];
				ll aux = memo[x][1];
				if (i) aux = (aux * pre[i - 1][2]) % mod;
				if (i != k - 1) aux = (aux * suf[i + 1][2]) % mod;
				pdm = (pdm + aux) % mod;
			}
		}
		else{
			pdm = suf[0][0];
			fr(i, k){
				int x = filho[v][i];
				ll aux = memo[x][1];
				if (i != 0) aux = (aux * pre[i - 1][0]) % mod;
				if (i != k - 1) aux = (aux * suf[i + 1][0]) % mod;
				pdm = (pdm + aux) % mod;
			}
			pdm = (pdm + memo[v][0]) % mod;
		}
	}
}


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;

	int a, b;
	fr(i, n - 1){
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	
	dfs(1, -1);
	pd(1);

	cout<<memo[1][2]<<endl;
}