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
const int MAXN = 4e5 + 10;
const ll mod =  998244353;

int n;
vi adj[MAXN];
ll memo[MAXN];

void dfs(int v, int p){
	memo[v] = 1;

	for (auto x : adj[v])
		if (x != p){
			dfs(x, v);
			memo[v] = (memo[v] * (memo[x] + 1)) % mod;
		}
}

void solve(){
	cin>>n;

	fr(i, n + 1)
		adj[i].clear();

	fr(i, n - 1){
		int a, b;
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}	

	dfs(1, 1);

	ll ans = 0;
	frr(i, n)
		ans = (ans + memo[i]);

	ans = (ans + 1) % mod;

	cout << ans << endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;

	cin>>T;

	while (T--)
		solve();
}