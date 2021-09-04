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
const int MAXN = 400 + 10;
const ll mod = 998244353;

ll fastxp(ll base, ll exp){
	ll ans = 1;
	while (exp){
		if (exp & 1)
			ans = (ans * base) % mod;
		base = (base * base) % mod;
		exp >>= 1;
	}
	return ans;
}

ll fat[MAXN];

ll comb(ll a, ll b){
	ll ans = fastxp(fat[a - b], mod - 2);
	ans = (ans * fastxp(fat[b], mod - 2)) % mod;
	return (ans * fat[a]) % mod;
}


int n, m;
vi adj[MAXN];
ll memo[MAXN][MAXN];

ll pd(){
	fr(i, MAXN)
		fr(j, MAXN)
			memo[i][j] = 1;

	frr(i, n)
		memo[i][i] = 0;

	for (int sz = 1; sz < n; sz += 2)
		for (int l = 1; l + sz <= n; l++){
			int r = l + sz;
			memo[l][r] = 0;
			for (int j : adj[l]){
				if ((j - l)&1 and j <= r){
					ll cnt = memo[l + 1][j - 1];
					ll rgt = memo[j + 1][r];
					ll n1 = (j - l)/2;
					ll n2 = (r - j)/2;

					ll aux = (cnt * rgt) % mod;
					aux = (aux * comb(n1 + n2 + 1, n2)) % mod;
					memo[l][r] = (memo[l][r] + aux) % mod;	
				}
			}
		}	

	return memo[1][n];	
}


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
		
	fat[0] = 1;
	for (ll i = 1; i < MAXN; i++)
		fat[i] = (i * fat[i - 1]) % mod;	


	cin>>n>>m;

	n += n;

	int a, b;
	fr(i, m){
		cin>>a>>b;
		adj[a].pb(b);
	}

	frr(i, n)
		sort(all(adj[i]));

	ll ans = pd();

	cout<<ans<<endl;
}