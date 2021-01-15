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
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 5e5 + 10;


vi adj2[MAXN];
set<int> adj[MAXN];

int cnt, fr[MAXN], to[MAXN], md[MAXN], vis[MAXN];

int remove(int v){
	int a = *adj[v].begin();
	adj[v].erase(a);
	adj[a].erase(v);
	return a;
}

void dfs(int v, int p){
	vis[v] = 1;
	for (auto it : adj2[v])
		if (!vis[it])
			dfs(it, v);

	if (p != -1)
		adj[v].erase(p);

	while (adj[v].size() >= 2){
		to[cnt] = remove(v);
		fr[cnt] = remove(v);
		md[cnt++] = v;
	}

	if (adj[v].size() == 1 and p != -1){
		to[cnt] = remove(v);
		adj[p].erase(v);
		fr[cnt] = p;
		md[cnt++] = v;
	}		
}


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;

	cin>>n>>m;

	int a, b;
	fr(i, m){
		cin>>a>>b;
		adj[a].insert(b);
		adj[b].insert(a);
		adj2[a].pb(b);
		adj2[b].pb(a);
	}


	dfs(1, -1);

	cout<<m/2<<endl;
	for (int i = 0; i < m / 2; i++)
		cout<<fr[i]<<' '<<md[i]<<' '<<to[i]<<endl;
}