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

int n, m;
vii adj[MAXN];

ll dist[MAXN];

void dij(){
	frr(i, n)
		dist[i] = -1;

	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll> > > pq;
	pq.push({0, 1});

	ll d, v;
	while (!pq.empty()){
		tie(d, v) = pq.top();
		pq.pop();

		if (dist[v] != -1)
			continue;

		dist[v] = d;

		for (auto x : adj[v])
			if (dist[x.fst] == -1){
				pq.push({d + x.snd, x.fst});
			}
	}	
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>m;

	fr(i, m){
		int a, b, c;
		cin>>a>>b>>c;
		adj[a].pb({b, c});
	}

	dij();

	frr(i, n)
		cout<<dist[i]<<' ';
	gnl;
}