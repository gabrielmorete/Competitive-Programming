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
const int MAXN = 2e5 + 10;

int n, ans;
vi adj[MAXN];

int dfs(int v, int p){
	if (adj[v].size() == 1 and v != 1)// folha
		return 1;

	vector<int> val;
	for (int x : adj[v])
		if (x != p)
			val.pb(dfs(x, v)); // pega os saltos para os filhos

	sort(all(val));
	
	if (val.size() > 1){
		if (v == 1)
			ans = max({ans, val.back(), val[val.size() - 2] + 1}); // ultima volta ou salto entre os filhos
		else
			ans = max(ans, val.back() + 1);
	}
	ans = max(ans, val[0]);
	return val[0] + 1; // menor distancia de retorno
}

void solve(){
	cin>>n;

	frr(i, n)
		adj[i].clear();

	int a, b;
	fr(i, n - 1){
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	ans = 0;
	dfs(1, 1);

	cout<<ans<<endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}