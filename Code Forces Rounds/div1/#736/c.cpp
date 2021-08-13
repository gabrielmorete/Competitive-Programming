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
const int MAXN = 3e6 + 10;
const ll mod = 1e9 + 7;

ll n, q, memo[MAXN][3], fat[MAXN], comb[MAXN];


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


ll choose(ll x, ll y){
	ll ans = (fat[x] * fastxp(fat[y], mod - 2)) % mod;
	ans = (ans * fastxp(fat[x - y], mod - 2)) % mod;
	return ans;
}



int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n>>q;


	fat[0] = 1;

	for (ll i = 1; i < MAXN; i++)
		fat[i] = (fat[i - 1] * i) % mod;

	for (ll i = 0; i < MAXN; i++)
		comb[i] = choose(3 * n, i);

	ll div3 = fastxp(3, mod - 2);


	fr(i, 3)
		memo[0][i] = n;

	for (int i = 1; i < MAXN; i++){
		ll x = comb[i + 1];
		ll y = memo[i - 1][0];
		ll z = memo[i - 1][1];

		ll c = ( (x + y + 2 * z) * div3) % mod;
		ll b = (c - z + mod) % mod;
		ll a = (b - y + mod) % mod;

		memo[i][0] = a;
		memo[i][1] = b;
		memo[i][2] = c;
	}	


	ll x;
	while (q--){
		cin>>x;

		ll ans = (memo[x][0] + comb[x]) % mod;

		cout<<ans<<endl;
	}
}