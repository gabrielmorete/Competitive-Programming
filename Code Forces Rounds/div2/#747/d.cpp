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

int id[MAXN], sz[MAXN];

int find(int a){
	if (id[a] == a) return a;
	return id[a] = find(id[a]);
}

void merge(int a, int b){
	a = find(a);
	b = find(b);

	if (a == b) return;
	if (sz[b] > sz[a]) swap(a, b);

	id[b] = a;
	sz[a] += sz[b];
}

vi adj[MAXN];
int col[MAXN], red, blue;

bool dfs(int v, int c){
	if (c == 1)
		red += sz[v];
	else
		blue += sz[v];

	col[v] = c;

	int l = 1;
	if (c == 1)
		l = 2;

	bool ok = 0;

	for (auto x : adj[v]){
		if (col[x] == c)
			ok = 1; // deu merda
		if (col[x] == 0)
			ok |= dfs(x, l);
	}

	return ok;
}


void solve(){
	int n, m;
	cin>>n>>m;

	frr(i, n){
		id[i] = i;
		sz[i] = 1;
		adj[i].clear();
		col[i] = 0;
	}

	vii bad;

	string s;
	int x, y;
	fr(i, m){
		cin>>x>>y>>s;
		if (s == "imposter")
			bad.pb({x, y});
		else
			merge(x, y);
	}

	if (bad.size() == 0){
		cout<<n<<endl;
		return;
	}

	for (auto e : bad){
		tie(x, y) = e;
		x = find(x);
		y = find(y);

		adj[x].pb(y);
		adj[y].pb(x);
	}

	int ans = 0;
	frr(i, n)
		if (col[i] == 0 and find(i) == i){
			red = blue = 0;
			if (dfs(i, 1)){
				cout<<-1<<endl;
				return;
			}

			ans += max(red, blue);
		}

	cout<<ans<<endl;
}


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}