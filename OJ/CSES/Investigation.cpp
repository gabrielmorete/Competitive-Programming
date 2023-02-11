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

const ll mod = 1000000007;

ll n, m;
ll dist[MAXN], indeg[MAXN];
vii adj[MAXN];

void dij(){
	frr(i, n)
		dist[i] = -1;

	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	pq.push({0, 1});


	ll d, v;
	while (!pq.empty()){
		tie(d, v) = pq.top();
		pq.pop();

		if (dist[v] != -1){
			if (dist[v] == d)
				indeg[v]++;
			
			continue;
		}

		dist[v] = d;
		indeg[v]++;

		for (auto x : adj[v])
			if (dist[x.fst] == -1)
				pq.push({d + x.snd, x.fst});
			else if (d + x.snd == dist[x.fst])
				indeg[x.fst]++;
	}
}

ll ways[MAXN], minw[MAXN], maxw[MAXN];

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>m;

	fr(i, m){
		int a, b, c;
		cin>>a>>b>>c;
		adj[a].pb({b, c});
	}

	dij();

	queue<int> fila;

	frr(i, n)
		minw[i] = n;

	ways[1] = 1;
	minw[1] = maxw[1] = 0;

	fila.push(1);

	while (!fila.empty()){
		int v = fila.front();
		fila.pop();

		for (auto [u, c] : adj[v])
			if (dist[u] == dist[v] + c){
				ways[u] += ways[v];
				ways[u] %= mod;
				minw[u] = min(minw[u], minw[v] + 1);
				maxw[u] = max(maxw[u], maxw[v] + 1);
		
				indeg[u]--;
				if (indeg[u] == 0)
					fila.push(u);
			}
	}

	cout<<dist[n]<<' '<<ways[n]<<' '<<minw[n]<<' '<<maxw[n]<<endl;
}