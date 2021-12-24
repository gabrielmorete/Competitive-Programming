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

int n, k, hgt[MAXN], sz[MAXN], pai[MAXN];

vi adj[MAXN];

void dfs_sz(int v, int p){
	pai[v] = p;
	hgt[v] = 1;
	sz[v] = 1;

	for (auto x : adj[v])
		if (x != p){
			dfs_sz(x, v);
			hgt[v] = max(hgt[v], hgt[x] + 1);
			sz[v] += sz[x];
		}	
}

priority_queue<pii> pq;

void dfs(int v, int p){
	int nxt = p;

	for (auto x : adj[v]){
		if (x == p)
			continue;

		if (nxt == p)
			nxt = x;
		else if (hgt[x] > hgt[nxt])
			nxt = x;
	}


	for (auto x : adj[v])
		if (x != nxt and x != p){
			pq.push({hgt[x], x});
		}

	if (nxt != p)	
		dfs(nxt, v);
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>k;

	frr(i, n - 1){
		int x, y;
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	dfs_sz(1, 1);

	pq.push({n, 1});

	ll r = 0;

	int x, s;
	fr(i, k){
		if (pq.empty())
			break;

		tie(s, x) = pq.top();
		pq.pop();

		dfs(x, pai[x]);
		r++;
	}

	ll b = 0;
	if (r < min(n/2, k))
		r = min(n/2, k);	


	while (!pq.empty()){
		b += sz[pq.top().snd];
		pq.pop();
	}

	b = min<ll>(b, n/2);

	ll w = n - r - b;

	cout<<w * (r - b)<<endl;
}