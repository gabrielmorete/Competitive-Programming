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
const int MAXN = 500 + 10;

ll n, m, q;
ll adj[MAXN][MAXN];

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m>>q;

	frr(i, n)
		frr(j, n)
			adj[i][j] = llINF;

	frr(i, n)
		adj[i][i] = 0;

	fr(i, m){
		ll a, b, c;
		cin>>a>>b>>c;

		adj[a][b] = adj[b][a] = min(adj[a][b], c);
	}

	frr(k, n)
		frr(i, n)
			frr(j, n)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

	while (q--){
		int a, b;
		cin>>a>>b;

		cout<<(adj[a][b] >= llINF? -1 : adj[a][b])<<endl;
	}
}