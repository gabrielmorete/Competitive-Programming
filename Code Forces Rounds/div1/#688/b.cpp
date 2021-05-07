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

int n, a, b, da, db, dim;
vi adj[MAXN];

int vmx;
void dfs(int v, int p, int d){
	if (d > dim){
		dim = d;
		vmx = v;
	}

	for (auto x : adj[v])
		if (x != p)
			dfs(x, v, d + 1);
}


void find_dim(){
	dim = -1;
	dfs(1, 1, 0);

	dfs(vmx, vmx, 0);
}

int dst;

void dfs2(int v, int p, int d){
	if (v == b)
		dst = d;

	for (auto x : adj[v])
		if (x != p)
			dfs2(x, v, d + 1);
}

void solve(){
	cin>>n>>a>>b>>da>>db;

	frr(i, n)
		adj[i].clear();

	int x, y;	
	fr(i, n - 1){
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}	

	find_dim();

	dfs2(a, a, 0);

	if (dst <= da or 2 *da >= db or dim <= 2 * da)
		cout<<"Alice"<<endl;
	else
		cout<<"Bob"<<endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}