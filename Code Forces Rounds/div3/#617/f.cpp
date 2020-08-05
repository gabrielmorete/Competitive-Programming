#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;
const ll mod=1e9+7;

int edge[5550][5550];
vi adj[5550];


bool dfs1(int v, int p, int w, int val){
	if (v == w)
		return true;
	for (int x : adj[v]){
		if (x != p){
			if (dfs1(x, v, w, val)){
				edge[v][x] = max(edge[v][x], val);
				edge[x][v] = edge[v][x];
				return true;
			}
		}
	}
	return false;
}

int dfs2(int v, int p, int w){
	if (v == w)
		return INF;
	for (int x : adj[v]){
		if (x != p){
			int aux = dfs2(x, v, w);
			if (aux != -1){
				return min(aux, edge[x][v]);
			}
		}
	}

	return -1;
}

vii ed;

int32_t main(){
	fastio;
	int n, m;
	cin>>n;

	int a, b;
	fr(i, n - 1){
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
		edge[a][b] = edge[b][a] = 1;
		ed.pb({a, b});
	}

	cin>>m;

	vector< tuple<int, int, int> > v;

	int c;
	fr(i, m){
		cin>>a>>b>>c;
		v.pb({a, b, c});
		dfs1(a, a, b, c);
	}

	bool ok = 1;

	fr(i, m){
		a = get<0>(v[i]); b = get<1>(v[i]); c = get<2>(v[i]);
		if (dfs2(a, a, b) != c)
			ok = 0;
	}

	if (!ok)
		cout<<-1<<endl;
	else{
		for (auto x : ed)
			cout<<edge[x.fst][x.snd]<<' ';	
		gnl;
	}
}