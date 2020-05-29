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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 2e5 + 10;
const ll mod = 998244353;

ll fastxp(ll base, ll exp){
	ll ans = 1;
	while (exp > 0){
		if (exp % 2)
			ans = (ans * base) % mod;
		base = (base * base) % mod;
		exp /= 2;	 
	}
	return ans;
}

ll invmod(ll x){
	return fastxp(x, mod - 2);
}

ll fat[MAXN];

int32_t main(){
	fastio;
	ll n, k;
	cin>>n>>k;

	if (k >= n){
		cout<<0<<endl;
		return 0;
	}

	ll ans = 0;
	ll c = n - k;

	fat[0] = 1;
	for (ll i = 1; i <= n; i++)
		fat[i] = (fat[i - 1] * i) % mod;


	// Quero colunas com ao menos uma torre
	ll aux;
	for (ll i = 0; i <= c; i++){
		aux = (fat[c] * invmod( (fat[i] * fat[c - i]) % mod)) % mod;
		aux = (aux * fastxp(c - i, n)) % mod;
		ans += (i % 2 ? -1ll : 1ll) * aux + mod;
		ans %= mod;
	}


	// Todas as formas de escolher c colunas
	ans = (ans * fat[n]) % mod;
	ans = (ans * invmod( (fat[c] * fat[n - c]) % mod)) % mod;

	if (k != 0)
		ans = (2 * ans) % mod; // Linhas
	cout<<ans<<endl;


}