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

int n, m, a, b, vis[MAXN];
vi stk, adj[MAXN];


void check(){
	if (a == b){
		cout<<(n - 2 * a)<<' '<<a<<endl;
		for (auto x : stk)
			cout<<x<<' ';
		gnl;
		for (int i = 1; i <= n; i++)
			if (vis[i] == 0)
				cout<<i<<' ';
		gnl;
		for (int i = 1; i <= n; i++)
			if (vis[i] == 2)
				cout<<i<<' ';
		gnl;
		exit(0);	
	}
}

void dfs(int v){
	a--;
	vis[v] = 1;
	stk.pb(v);
	check();

	for (auto x : adj[v])
		if (vis[x] == 0)
			dfs(x);

	stk.pop_back();
	vis[v] = 2;
	b++;
	check();
}


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin>>n>>m;

	int x, y;
	fr(i, m){
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	a = n;
	dfs(1);
}