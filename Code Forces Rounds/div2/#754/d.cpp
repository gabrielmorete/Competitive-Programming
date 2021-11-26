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

int n, frq[2], ans[MAXN];
vi dist[2], v[35], adj[MAXN];

void dfs(int v, int p, int dst){
	frq[dst]++;
	dist[dst].pb(v);

	for (auto x : adj[v])
		if (x != p)
			dfs(x, v, (dst + 1)%2);
}

void solve(){
	cin>>n;

	frq[0] = frq[1] = 0;
	dist[0].clear();
	dist[1].clear();
	fr(i, 32)
		v[i].clear();
	frr(i, n)
		adj[i].clear();	


	int x, y;
	fr(i, n - 1){
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	dfs(1, 1, 0);

	int cnt = 0, pwr = 0;

	while (cnt < n){
		fr(j, 1<<pwr){
			cnt++;
			v[pwr].pb(cnt);
			if (cnt >= n)
				break;
		}

		pwr++;
	}

	int p = 0;
	if (frq[1] < frq[0])
		p = 1;

	for (int i = 28; i >= 0; i--)
		if (frq[p] & (1<<i)){
			while (!v[i].empty()){
				ans[dist[p].back()] = v[i].back();
				dist[p].pop_back();
				v[i].pop_back();
			}
		}
	
	fr(i, 28)
		while (!v[i].empty()){
			ans[dist[p^1].back()] = v[i].back();
			dist[p^1].pop_back();
			v[i].pop_back();
		}

	frr(i, n)
		cout<<ans[i]<<' ';
	gnl;	
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;

	while (T--)
		solve();
}