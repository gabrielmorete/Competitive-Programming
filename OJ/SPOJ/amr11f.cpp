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
const int MAXN = 4e5 + 10;

int n, f, m, cnt;
vi tower[MAXN];
map<pii, int> crd;

vector<pair<int, ll>> adj[MAXN];

vector<vector<ll>> dist;

void dijkstra(int src){
	fr(i, cnt)
		dist[src][i] = -1;

	priority_queue< pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>> > pq;

	pq.push({0, src});

	ll dst, vtx;

	while (!pq.empty()){
		tie(dst, vtx) = pq.top();
		pq.pop();

		if (dist[src][vtx] == -1){
			dist[src][vtx] = dst;

			for (auto x : adj[vtx])
				if (dist[src][x.fst] == -1)
					pq.push({dst + x.snd, x.fst});
		}
	}
}

array<int, 2> get(int twr, int flr){
	int p = (int)(lower_bound(all(tower[twr]), flr) - tower[twr].begin());

	if (p == tower[twr].size())
		p--;
	int q = max(p - 1, 0);

	return {tower[twr][p], tower[twr][q]};
}


void solve(){
	cnt = 0;
	crd.clear(); // torre, andar -> numero

	cin>>n>>f>>m;

	fr(i, 2*(n + m))
		adj[i].clear();

	frr(i, n)
		tower[i].clear();	

	frr(i, n){
		tower[i].pb(1);
		crd[{i, 1}] = cnt++;
	}	

	fr(i, m){
		int f[2], t[2], cst;

		cin>>t[0]>>f[0]>>t[1]>>f[1]>>cst;

		int v[2];

		fr(i, 2){
			if (!crd.count({t[i], f[i]})){
				tower[t[i]].pb(f[i]);
				crd[{t[i], f[i]}] = cnt++;
			}
			v[i] = crd[{t[i], f[i]}];
		}

		adj[v[0]].pb({v[1], cst});
		adj[v[1]].pb({v[0], cst});
	}

	frr(i, n - 1){
		int v = crd[{i, 1}];
		int u = crd[{i + 1, 1}];

		adj[v].pb({u, 1});
		adj[u].pb({v, 1});
	}

	adj[crd[{n, 1}]].pb({crd[{1, 1}], 1});
	adj[crd[{1, 1}]].pb({crd[{n, 1}], 1});


	frr(i, n){
		sort(all(tower[i]));

		for (int j = 0; j + 1 < tower[i].size(); j++){
			int v = crd[{i, tower[i][j]}];
			int u = crd[{i, tower[i][j + 1]}];

			adj[v].pb({u, tower[i][j + 1] - tower[i][j]});
			adj[u].pb({v, tower[i][j + 1] - tower[i][j]});
		}
	}

	dist.resize(cnt);

	fr(i, cnt){
		dist[i].resize(cnt);

		dijkstra(i);
	}


	int q;
	cin>>q;

	while (q--){
		ll ans = llINF;
		int t[2], f[2];

		fr(i, 2)
			cin>>t[i]>>f[i];

		if (t[0] == t[1]){
			ans = abs(f[0] - f[1]); // por dentro da torre;
		}	

		array<int, 2> viz[2];
		fr(i, 2)
			viz[i] = get(t[i], f[i]);


		fr(i, 2)
			fr(j, 2){
				ll aux = abs(f[0] - viz[0][i]);
				aux += abs(f[1] - viz[1][j]);

				int v0 = crd[{t[0], viz[0][i]}];
				int v1 = crd[{t[1], viz[1][j]}];

				aux += dist[v1][v0];

				ans = min(ans, aux);
			}	

		cout<<ans<<endl;
	}
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}