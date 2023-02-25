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
const int MAXN = 21;

const ll mod = 1000000007;

int n, m;
vi adj[MAXN];

ll memo[MAXN][1<<MAXN];

ll pd(int v, int msk){
	if (v == n){
		if (__builtin_popcount(msk) == n)
			return 1;
		return 0;
	}

	ll &pdm = memo[v][msk];

	if (pdm != -1)
		return pdm;

	pdm = 0;

	for (auto x : adj[v])
		if ((msk & (1<<x)) == 0)
			pdm = (pdm + pd(x, msk | (1<<x))) % mod;

	return pdm;	
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>m;

	fr(i, m){
		int a, b;
		cin>>a>>b;
		adj[a].pb(b);
	}

	memset(memo, -1, sizeof(memo));

	cout<<pd(1, (1<<1))<<endl;
}