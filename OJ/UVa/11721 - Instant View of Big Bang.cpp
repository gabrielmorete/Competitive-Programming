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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e3 + 10;
const ll mod=1e9+7;

int n, m, vis[MAXN], dist[MAXN];
bool ans[MAXN];
vii adj[MAXN];


bool bellman(){
	fill(ans, ans + n, 0);
	fill(dist, dist + n, INF);
	dist[0] = 0;

	int a, b;
	
	fr(cnt, n - 1)
		fr(i, n)
			for (auto x : adj[i]){
				a = x.fst; b = x.snd;
				dist[a] = min(dist[a], dist[i] + b);
			}

	bool ok = 0;		
	fr(i, n)
		for (auto x : adj[i]){
			a = x.fst; b = x.snd;
			if (dist[a] > dist[i] + b)
				ans[a] = 1, ok = 1;
		}
	return ok;
}

int deg[MAXN];
void toposort(){
	fill(deg, deg + n, 0);
	queue<int> fila;
	fr(i, n)
		for (auto x : adj[i])
			deg[x.fst]++;
	fr(i, n)
		if (deg[i] == 0)
			fila.push(i);
	int a;
	while (!fila.empty()){
		a = fila.front();
		fila.pop();
		for (auto x : adj[a]){
			deg[x.fst]--;
			if (deg[x.fst] == 0)
				fila.push(x.fst);
		}
		adj[a].clear();			
	}			
}

void solve(){	
	cin>>n>>m;

	fr(i, n)
		adj[i].clear();

	int a, b, c;
	fr(i, m){
		cin>>a>>b>>c;
		adj[b].pb({a, c}); // Reverse
	}

	toposort();

	if (bellman()){
	
		fr(cnt, n)
			fr(i, n)
				for (auto x : adj[i])
					ans[x.fst] |= ans[i];

		fr(i, n)
			if(ans[i])
				cout<<' '<<i;
		gnl;
	}
	else
		cout<<" impossible"<<endl;
}


int32_t main(){
	fastio;
	int T;
	cin>>T;
	frr(i, T){
		cout<<"Case "<<i<<":";
		solve();
	}
}