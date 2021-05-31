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

ll n, l[MAXN], r[MAXN], memo[MAXN][2];
vi adj[MAXN];


void dfs(int v, int p){
	memo[v][0] = memo[v][1] = 0;

	for (auto x : adj[v])
		if (x != p){
			dfs(x, v); // resolve para baixo

			memo[v][0] += max(memo[x][0] + abs(l[x] - l[v]), memo[x][1] + abs(r[x] - l[v]));

			memo[v][1] += max(memo[x][0] + abs(l[x] - r[v]), memo[x][1] + abs(r[x] - r[v]));
		}
}

void solve(){
	cin>>n;
	fr(i, n + 10)
		adj[i].clear();

	frr(i, n){
		cin>>l[i]>>r[i];
	}

	int u, v;
	fr(i, n - 1){
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(1, 1);		

	cout<<max(memo[1][0], memo[1][1])<<endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}