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

int n, bsz[MAXN], taken[MAXN] ;
vi adj[MAXN];

void dfs(int v, int p){
	bsz[v] = taken[v] = 0;

	for (auto x : adj[v])
		if (p != x){
			dfs(x, v);
			if (!taken[x])
				bsz[v]++;
		}

	if (bsz[v] > 0) // found a bud
		taken[v] = 1;
}




void solve(){
	cin>>n;

	frr(i, n)
		adj[i].clear();

	int x, y;	
	fr(i, n - 1){
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	dfs(1, 1);

	int ans = max(1, bsz[1]);

	for (int i = 2; i <= n; i++)
		if (bsz[i] > 0)
			ans += bsz[i] - 1;

	cout<<ans<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}