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
const ll mod = 998244353;

int n, m, deg[MAXN];
vi adj[MAXN];

bool vis[MAXN];

void dfs(int v){
	vis[v] = 1;
	for (auto x : adj[v])
		if (!vis[x])
			dfs(x);
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>m;

	int x, y;
	fr(i, m){
		cin>>x>>y;
		deg[x]++;
		deg[y]++;

		adj[x].pb(y);
		adj[y].pb(x);
	}

	queue<int> fila;
	frr(i, n)
		if (deg[i] == 1)
			fila.push(i);

	while (!fila.empty()){
		x = fila.front();
		fila.pop();
		vis[x] = 1;

		for (auto y : adj[x])
			if (vis[y] == 0){
				deg[y]--;
				if (deg[y] == 0){
					cout<<0<<endl;
					return 0;
				}
				if (deg[y] == 1)
					fila.push(y);
			}
	}	

	frr(i, n)
		if (!vis[i] and deg[i] != 2){
			cout<<0<<endl;
			return 0;
		}


	ll ans = 1;
	frr(i, n)
		if (!vis[i]){
			ans = (ans*2)%mod;
			dfs(i);
		}

	cout<<ans<<endl;
}