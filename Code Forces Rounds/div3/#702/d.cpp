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

int n, a[110];
vi adj[110];

int getmax(int l, int r){
	int pmx = l;
	for (int i = l; i <= r; i++)
		if (a[i] > a[pmx])
			pmx = i;
	return pmx;	
}


void build(int l, int r){
	int pmx = getmax(l, r);
	if (pmx - 1 >= l){
		int lft = getmax(l, pmx - 1);
		adj[pmx].pb(lft);
		adj[lft].pb(pmx);
		build(l, pmx - 1);

	}

	if (r >= pmx + 1){
		int rgt = getmax(pmx + 1, r);
		adj[pmx].pb(rgt);
		adj[rgt].pb(pmx);
		build(pmx + 1, r);
	}
}

int hgt[110];	
void dfs(int v, int p){
	for (auto x : adj[v]){
		if (x != p){
			hgt[x] = hgt[v] + 1;
			dfs(x, v);
		}
	}
}

void solve(){
	cin>>n;
	fr(i, n)
		adj[i].clear();

	fr(i, n)
		cin>>a[i];

	build(0, n - 1);

	fr(i, n)
		if (a[i] == n){
			hgt[i] = 0;
			dfs(i, i);
		}

	fr(i, n)
		cout<<hgt[i]<<' ';
	gnl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}