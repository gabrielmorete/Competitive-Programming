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
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;

const ll mod = 1e9 + 7;

ll n, pai[MAXN], sz[MAXN];

vi adj[MAXN];

void dfs(int v, int p){
	pai[v] = p;
	sz[v] = 0;

	for (int x : adj[v])
		if (x != p){
			dfs(x, v);
			sz[v] += sz[x];
		}
	sz[v]++;	
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

	dfs(1, 1);	

	priority_queue<ll> pq;

	for (int i = 2; i <= n; i++)
		pq.push((n - sz[i]) * sz[i]);
	
	ll ans = 0, m, aux;
	vector<ll> p;

	cin>>m;
	fr(i, m){
		cin>>aux;
		p.pb(aux);
	}

	sort(all(p));	

	while (m > n - 1){
		p[m - 2] = (p[m - 2] * p[m - 1]) % mod;
		p.pop_back();
		m--;
	}


	ll val;
	while (!pq.empty()){
		aux = pq.top();
		pq.pop();

		val = 1;

		if (m > 0){
			val = p.back();
			p.pop_back();
			m--;
		}

		ans = (ans + val * aux) % mod;
	}

	cout<<ans<<endl;
}


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}