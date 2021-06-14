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
const int MAXN = 1e6 + 10;

ll n;
vi adj[MAXN];

map<ll, ll> id, rid;

vector<ll> comp[MAXN];

bool vis[MAXN];
void dfs(int v, int cmp){
	vis[v] = 1;
	if (v <= n)
		comp[cmp].pb(v);
	for (auto x : adj[v])
		if (!vis[x])
			dfs(x, cmp);
}


bool ja[MAXN];

ll solve(int cmp){
	ll sum = 0, bst = llINF;
	bool perf = 0, fst = 1;
	for (auto u : comp[cmp]){
		if (fst){
			fst = 0;
			for (auto x : adj[u]){
				sum += rid[x];
				ja[x] = true;
				bst = min(bst, rid[x]);
			}
			if (adj[u].size() == 1) perf = 1;
		}
		else{
			ll novo = 0, val;
			for (auto x : adj[u]){
				if (!ja[x]){
					novo++;
					sum += rid[x];
					val = rid[x];
				}
				ja[x] = 1;
			}

			if (novo >= 2) assert(0);
			if (novo == 0){
				bst = sum;
				perf = 1;
			}
			else{
				if (perf)
					bst = val + bst;
				else
					bst = min(val + bst, sum - val);
			}
		}
	}
	return bst;
}




int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;

	ll cnt = n + 1, x, y, sum = 0;
	frr(i, n){
		cin>>x>>y;
		sum += x + y;

		if (!id.count(x)){
			id[x] = cnt;
			rid[cnt++] = x;
		}
		if (!id.count(y)){
			id[y] = cnt;
			rid[cnt++] = y;
		}

		adj[i].pb(id[x]);
		adj[id[x]].pb(i);

		if (x != y){
			adj[i].pb(id[y]);
			adj[id[y]].pb(i);
		}
	}

	ll cmp = 0;
	frr(i, n)
		if (!vis[i]){
			dfs(i, ++cmp);
		}


	ll ans = 0;
	frr(i, cmp)
		ans += solve(i);	
	cout<<sum - ans<<endl;	
}