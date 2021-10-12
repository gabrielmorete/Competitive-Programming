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

ll n, d[MAXN];
vector<pair<ll, ll>> adj[MAXN];

ll f[MAXN], ans[MAXN];

void dfs1(int v, int p){
	for (auto [x, cst] : adj[v])
		if (x != p){
			dfs1(x, v);
			if (ans[x] + cst > ans[v]){
				ans[v] = ans[x] + cst;
				f[v] = x;
			}

			if (cst + d[x] > ans[v]){
				ans[v] = cst + d[x];
				f[v] = x;
			}
		}
}

void dfs2(int v, int p, ll cstp){
	if (v != p and cstp > ans[v]){ // vir do pai é melhor
		ans[v] = cstp;
		f[v] = p;
	}

	ll fc = 0;
	for (auto [x, c] : adj[v])
		if (x != f[v] and x != p){
			fc = max<ll>(fc, c + ans[x]); // alguem nessa subárvore
			fc = max<ll>(fc, c + d[x]); // filho
		}

	for (auto [x, c] : adj[v])
		if (x != p){
			if (x != f[v]){
				ll bst = max<ll>({cstp, d[v], ans[v]}) + c;

				dfs2(x, v, bst);
			}
			else{
				ll bst = max<ll>({cstp, d[v], fc}) + c;
				dfs2(x, v, bst);
			}
		}
}



signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;

	ll a, b, c;
	fr(i, n - 1){
		cin>>a>>b>>c;
		adj[a].pb({b, c});
		adj[b].pb({a, c});
	}

	frr(i, n)
		cin>>d[i];


	dfs1(1, 1);

	dfs2(1, 1, 0);

	frr(i, n)
		cout<<ans[i]<<endl;
}