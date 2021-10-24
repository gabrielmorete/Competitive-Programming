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

int n, nvis;
bool v[400], vis[400];
vi adj[400];

void dfs(int v){
	nvis++;
	vis[v] = 1;

	for (auto x : adj[v])
		if (!vis[x])
			dfs(x);
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	fr(i, n){
		int x;
		cin>>x;
		v[x] = 1;
	}

	int ans = 0;

	frr(d, 359){
		fr(i, 360){
			adj[i].clear();
			vis[i] = 0;
		}

		fr(i, 360){
			if (v[i]){
				int l = (i + d) % 360;
				int r = (i - d + 360) % 360;

				if (v[r])
					adj[i].pb(r);
				if (v[l])
					adj[i].pb(l);
			}
		}

		int aux = 0;

		fr(i, 360)
			if (!vis[i]){
				nvis = 0;
				dfs(i);
				aux += nvis/2;
			}

		ans = max(ans, aux);
	}

	cout<<ans<<endl;
}