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
const ll mod = 998244353;

ll n, m, freq[MAXN];

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

ll fat[MAXN], inv[MAXN], ans[MAXN];

ll comb(ll a, ll b){
	if (a < b) return 0;
	return (fat[a] * inv[a - b]) % mod;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	fat[0] = inv[0] = 1;

	for (ll i = 1; i < MAXN; i++){
		fat[i] = (i * fat[i - 1]) % mod;
		inv[i] = fastxp(fat[i], mod - 2);
	}

	cin>>n>>m;

	frr(i, n)
		freq[i % m]++;

	for (ll k = 1; k <= n; k++){
		ll &aux = ans[k];
		
		aux = 1;
		for (ll i = 0; i < m; i++)
			aux = (aux * comb(k, freq[i])) % mod; // botar freq[i] em k caras distintos, pode ter cara vazio
			
		for (ll i = 1; i < k; i++){
			ll cmb = (ans[i] * comb(k, i)) % mod;
			aux = (aux - cmb + mod) % mod; // formas de ter i caras e k - i vazios
		}

		aux = (aux * inv[k]) % mod;
	}

	frr(i, n)
		cout<<ans[i]<<endl;
}