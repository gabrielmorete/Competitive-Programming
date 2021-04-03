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
const int MAXN = 1e5 + 10;

int n;
vector<pair<ll, ll>> v;

int bb(int vtx){
	int ini = vtx, fim = n - 1, bst = n;

	while (ini <= fim){
		int meio = (ini + fim)/2;

		if (v[meio].fst <= v[vtx].fst + v[vtx].snd){ // valido
			ini = meio + 1;
			bst = meio;
		}
		else
			fim = meio - 1;
	}

	return bst;
}


ll dist[MAXN];

ll dij(){
	memset(dist, -1, sizeof dist);

	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	pq.push({0, 0});

	int vtx, dst;
	while (!pq.empty()){
		tie(dst, vtx) = pq.top();
		pq.pop();

		if (dist[vtx] == -1){
			dist[vtx] = dst;
			if (vtx > 0 and dist[vtx - 1] == -1)
				pq.push({dst, vtx - 1}); // lower beauty

			int u = bb(vtx);
			
			if (u < n)
				pq.push({dst, u});
			if (u + 1 < n)
				pq.push({dst + max<ll>(0, v[u + 1].fst - v[vtx].fst - v[vtx].snd), u + 1});
			
		}
	}

	return dist[n - 1];
}


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;

	ll ans = 0;
	int a, b;
	fr(i, n){
		cin>>a>>b;
		ans += b;
		v.pb({a, b});
	}

	sort(all(v));

	ans += dij();

	cout<<ans<<endl;
}