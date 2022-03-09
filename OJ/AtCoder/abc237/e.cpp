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
typedef pair<ll, ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 4e5 + 10;

ll n, m, hgt[MAXN], dist[MAXN];
vi adj[MAXN];

ll cost(int v, int x){
	ll aux = 0;
	if (hgt[x] > hgt[v])
		aux = 2*(hgt[x] - hgt[v]);
	else
		aux = hgt[x] - hgt[v];

	return aux - hgt[x] + hgt[v];
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>m;

	frr(i, n)
		cin>>hgt[i];

	fr(i, m){
		int x, y;
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}	

	frr(i, n)
		dist[i] = -1;

	priority_queue<pll, vector<pll>, greater<pll>> pq;

	pq.push({0, 1});

	ll ans = 0, dst, v;
	while (!pq.empty()){
		tie(dst, v) = pq.top();
		pq.pop();

		if (dist[v] == -1){
			dist[v] = dst;

			ans = min(ans, dst - hgt[1] + hgt[v]);

			for (auto x : adj[v])
				if (dist[x] == -1)
					pq.push({dst + cost(v, x), x});
		}
	}

	cout<<-ans<<endl;
}	