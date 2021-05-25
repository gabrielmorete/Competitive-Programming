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
const int MAXN = 3e5 + 10;

int id[MAXN], sz[MAXN];

void init(){
	fr(i, MAXN){
		id[i] = i;
		sz[i] = 1;
	}
}

int find(int a){
	if (a == id[a])
		return a;
	return id[a] = find(id[a]);
}

bool merge(int a, int b){
	a = find(a);
	b = find(b);

	if (a == b) 
		return false;
	if (sz[b] > sz[a])
		swap(a, b);
	id[b] = a;
	sz[a] += sz[b];
	return true;
}

ll n, m, cst, a[MAXN];
vii adj[MAXN];

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin>>n>>m>>cst;
	
	ll sum = 0;
	fr(i, n){
		cin>>a[i];
		sum += a[i];
	}

	int x, y;	
	fr(i, m){
		cin>>x>>y;
		adj[x - 1].pb({y - 1, i});
		adj[y - 1].pb({x - 1, i});
	}	


	if (sum < cst * (n - 1)){
		cout<<"NO"<<endl;
		return 0;
	}

	init();

	set<pair<ll, ll>> q;

	fr(i, n)
		q.insert({-a[i], i});

	vi ans;	
	ll cnt, vtx;
	while (q.size() > 1){
		tie(cnt, vtx) = *q.begin();
		q.erase(q.begin());
	
		while (find(vtx) == find(adj[vtx].back().fst)){ // não juntou
			adj[vtx].pop_back();
		}

		int u = find(adj[vtx].back().fst);

		q.erase({-a[u], u});

		ans.pb(adj[vtx].back().snd + 1);
		adj[vtx].pop_back();

		merge(vtx, u);

		a[find(vtx)] = a[vtx] + a[u] - cst;
		q.insert({-a[find(vtx)], find(vtx)});

		if (find(vtx) != vtx) // O(mlog(n))
			while (!adj[vtx].empty()){
				adj[find(vtx)].pb(adj[vtx].back());
				adj[vtx].pop_back();
			}

		if (find(u) != u) // O(mlog(n))
			while (!adj[u].empty()){
				adj[find(u)].pb(adj[u].back());
				adj[u].pop_back();
			}
	}	

	cout<<"YES"<<endl;
	for (auto it : ans)
		cout<<it<<endl;
}