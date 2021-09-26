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

int n;
vi adj[MAXN];

ll dist[MAXN], cnt[MAXN], ans[MAXN];

void dfs1(int v, int p){
	cnt[v] = 1; // eu
	dist[v] = 0;

	for (auto x : adj[v])
		if (x != p){
			dfs1(x, v);
			cnt[v] += cnt[x];
			dist[v] += dist[x] + cnt[x]; // distancia até ele mais essa ultima aresta
		}
}

void dfs2(int v, int p){
	if (v == p)
		ans[v] = dist[v];
	else{
		ll ap = ans[p];
		ap -= (dist[v] + cnt[v]); // minha subárvore

		ap += n - cnt[v]; // todos os outros nós

		ans[v] = ap + dist[v];
	}

	for (auto x : adj[v])
		if (x != p)
			dfs2(x, v);
}


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;

	int x, y;
	fr(i, n - 1){
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	dfs1(1, 1);
	dfs2(1, 1);

	frr(i, n)
		cout<<ans[i]<<endl;
}