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
const int MAXN = 3e5 + 10;
const ll mod = 1e9 + 7;

int n, m, sn, clk, id;
int pre[MAXN], lo[MAXN], stk[MAXN], ebcc[MAXN], freq[MAXN];
vi adj[MAXN], adjbcc[MAXN];

void dfs_ebcc(int v, int p){
	lo[v] = pre[v] = clk++;
	stk[sn++] = v;

	for (auto w : adj[v]){
		if (pre[w] == -1){
			dfs_ebcc(w, v);
			lo[v] = min(lo[v], lo[w]);
		}
		else if (w != p)
			lo[v] = min(lo[v], pre[w]);
	}

	if (lo[v] == pre[v]){
		int u;
		freq[id] = 0;
		do {
			u = stk[--sn];
			ebcc[u] = id;
			freq[id]++;
		} while (u != v);
		id++;
	}
}

int findbcc(){
	fill(pre, pre + n + 3, -1);
	sn = clk = id = 0;
	frr(v, n)
		if (pre[v] == -1)
			dfs_ebcc(v, v);
	return id;	
}

void build_ebcc(){
	frr(v, n)
		for (auto x : adj[v])
			if (ebcc[v] != ebcc[x])
				adjbcc[ebcc[v]].pb(ebcc[x]);
}

ll k;
ll peq[MAXN], pdf[MAXN];

ll dfs(int v, int p){
	ll ans = 1;

	if (freq[v] == 1){
		ans = k;
		if (v != p)
			ans = k - 1;
	}
	else{
		ans = (k * pdf[freq[v]])%mod;
		if (v != p)
			ans = ((k - 1) * pdf[freq[v]])%mod;
	}

	for (auto x : adjbcc[v])
		if (x != p)
			ans = (ans * dfs(x, v)) % mod;

	return ans;	
}


void solve(){
	cin>>n>>m>>k;

	int x, y;
	frr(i, m){
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	findbcc();
	build_ebcc();	

	peq[2] = 0;
	pdf[2] = k - 1;

	// fr(i, id){
	// 	dbg(i);
	// 	for (auto x : adjbcc[i])
	// 		dbg(x);
	// }

	for (int i = 3; i <= n; i++){
		peq[i] = pdf[i - 1];
		pdf[i] = ((k - 2)*pdf[i - 1] + (k - 1)*peq[i - 1])%mod;
	}

	cout<<dfs(0, 0)<<endl;

	fr(i, n + 10){
		adj[i].clear();
		adjbcc[i].clear();
	}
}


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int T;
	cin>>T;

	while (T--)
		solve();
}