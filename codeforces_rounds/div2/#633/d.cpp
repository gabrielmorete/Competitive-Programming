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
const int MAXN = 1e5 + 10;
const ll mod=1e9+7;

int n, pai[MAXN], dist[MAXN];
vi adj[MAXN];

void dfs(int v, int p){
	for (int x : adj[v]){
		if (x != p){
			dist[x] = dist[v] + 1;
			dfs(x, v);
		}
		if (adj[x].size() == 1)
			pai[v] = 1;
	}	
}

int32_t main(){
	fastio;
	cin>>n;

	int a, b;
	fr(i, n - 1){
		cin>>a>>b;
		a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	int r;
	fr(i, n)
		if (adj[i].size() == 1)
			r = i;

	dist[r] = 0;	
	dfs(r, r);

	bool ev, od;
	ev = od = 0;	
	fr(i, n)
		if (adj[i].size() == 1){
			if (dist[i] % 2)
				od = 1;
			else
				ev = 1;
		}
	int mn, mx;

	if (ev & od)
		mn = 3;
	else
		mn = 1;		

	mx = n - 1;
	fr(i, n){
		if (pai[i])
			mx++;
		if (adj[i].size() == 1)
			mx--;
	}

	cout<<mn<<' '<<mx<<endl;
		
}