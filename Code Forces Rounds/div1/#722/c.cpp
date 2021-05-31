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
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 3e5 + 10;

int n;
vi adj[MAXN], g[MAXN];
int clk, in[MAXN], out[MAXN];

void dfs_time(int v){
	in[v] = clk++;
	for (int x : g[v])
		dfs_time(x);
	out[v] = clk;	
}

set<pii> q;

int inside(int v, int u){
	return in[v] <= in[u] and out[u] <= out[v];
}

int ans, now;

void dfs(int v){
	int before = now;

	auto it = q.lower_bound({in[v], 0}); // primeiro intervalo que não começa antes de in[v]

	if (it != q.end()) // eu contenho o intervalo que começa depois?
		now += 1 - inside(v, it->snd); // se não, aumenta, se sim, mantem o valor
	if (it != q.begin()){
		auto nxt = it--; // guardei o proximo e voltei
		now += 1 - inside(it->snd, v); // o anterior me contém
		if (nxt != q.end()) // entrei em ambos os casos, conserta
			now -= 1 - inside(it->snd, nxt->snd);
	}

	q.insert({in[v], v});
	
	ans = max(ans, now);
	for (auto x : adj[v])
		dfs(x);

	q.erase({in[v], v});
	
	now = before;
}

void solve(){
	cin>>n;

	fr(i, n + 10){
		adj[i].clear();
		g[i].clear();
	}

	int x;
	for (int i = 2; i <= n; i++){ // vizinhos
		cin>>x;
		adj[x].pb(i);
	}
	
	for (int i = 2; i <= n; i++){ // independentes
		cin>>x;
		g[x].pb(i);
	}

	clk = 0;
	dfs_time(1);

	ans = now = 1;
	dfs(1);

	cout<<ans<<endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}