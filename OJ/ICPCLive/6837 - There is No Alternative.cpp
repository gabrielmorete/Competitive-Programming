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

int id[MAXN], sz[MAXN];

int find(int a){
	if (id[a] == a)
		return id[a];
	return id[a] = find(id[a]);
}

void merge(int a, int b){
	a = find(a);
	b = find(b);

	if (a == b) return;

	if (sz[a] < sz[b])
		swap(a, b);

	id[b] = a;
	sz[a] += sz[b];
}


int clk, n, m;
int pre[MAXN], lo[MAXN];
vi adj[MAXN];
map<pii, bool> bridge;

void dfsRbc(int v, int p){
	pre[v] = lo[v] = clk++;
	int chd = 0;
	bool any = false;
	for (auto x : adj[v]){
		if (pre[x] == -1){
			chd++;
			dfsRbc(x, v);
			lo[v] = min(lo[v], lo[x]);
			if (lo[x] >= pre[v])
				any = true;
			if (lo[x] > pre[v])
				bridge[{v, x}] = bridge[{x, v}] = true;
		}
		else if (x != p)
			lo[v] = min(lo[v], pre[x]);
	}
}

void findbc(){
	bridge.clear();
	fill(pre, pre + n + 1, -1);
	clk = 0;
	for (int v = 0; v <= n; v++)
		if (pre[v] == -1)
			dfsRbc(v, v);
}

vector<array<int, 3>> edges;
map<pii, int> freq;

ll tam, cst;

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (cin>>n>>m){
		tam = 0;
		cst = 0;

		fr(i, n + 10){
			id[i] = i;
			sz[i] = 1;
		}

		edges.clear();
		fr(i, m){
			int x, y, z;

			cin>>x>>y>>z;
			edges.pb({z, x, y});
		}

		sort(all(edges));

		int p = 0;
		while (p < m){
			int q = p;

			while (q < m and edges[q][0] == edges[p][0])
				q++;

			fr(i, n + 10)
				adj[i].clear();

			freq.clear();	
			for (int e = p; e < q; e++){
				int x = find(edges[e][1]);
				int y = find(edges[e][2]);
				freq[{min(x, y), max(x, y) }]++;

				if (x != y){
					adj[x].pb(y);
					adj[y].pb(x);
				}
			}
		
			findbc();

			for (int e = p; e < q; e++){
				int x = find(edges[e][1]);
				int y = find(edges[e][2]);

				if (bridge[{x, y}] == 1 and freq[{min(x, y), max(x, y) }] <= 1){
					tam++;
					cst += edges[e][0];
				}
			}

			for (int e = p; e < q; e++){
				int x = find(edges[e][1]);
				int y = find(edges[e][2]);
				merge(x, y);
			}

			p = q;
		}

		cout<<tam<<' '<<cst<<endl;
	}
}