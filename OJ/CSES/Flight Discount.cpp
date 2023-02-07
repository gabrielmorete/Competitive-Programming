#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

// #define endl '\n'
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
vector<pii> adj[MAXN];

ll dist[MAXN][2];

ll dij(){
	frr(i, n)
		fr(j, 2)
			dist[i][j] = -1;

	priority_queue< array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>> > pq;
	
	pq.push({0, 0, 1}); // dist, halved?, v

	while (!pq.empty()){
		auto [d, h, v] = pq.top();
		pq.pop();

		if (dist[v][h] != -1)
			continue;

		dist[v][h]= d;

		for (auto x : adj[v]){
			if (h == 1){
				if (dist[x.fst][1] == -1)
					pq.push({d + x.snd, 1, x.fst}); // already halved
			}
			else{
				if (dist[x.fst][0] == -1)
					pq.push({d + x.snd, 0, x.fst}); // didn't halved and wont do it now

				if (dist[x.fst][1] == -1)
					pq.push({d + (x.snd/2), 1, x.fst}); // didn't halved and will do it now
			}
		}
	}

	return dist[n][1];
}


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>m;

	fr(i, m){
		int a, b, c;
		cin>>a>>b>>c;
		adj[a].pb({b, c});
	}

	cout<<dij()<<endl;
}